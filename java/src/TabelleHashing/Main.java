package TabelleHashing;

import java.util.Objects;
import java.util.Random;
import java.util.Scanner;

public class Main {

    static int dimTab;
    static Auto[] tabella;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Inserisci dimensioni tabella:");
        dimTab = sc.nextInt();
        System.out.println();

        tabella = new Auto[dimTab];

        System.out.println("USAGE (premere un paio di volte invio se non va menu)");
        System.out.println(" add {targa} {marca} {modello} {colore} {km}");
        System.out.println(" search {targa}");
        System.out.println(" exit");
        System.out.println();

        do {
            System.out.print("> ");
            String[] commandLine = sc.nextLine().split("\\s+");

            if (commandLine[0].contains("exit"))
                return;

            if (commandLine.length < 2) {
                System.out.println("Comando non riconosciuto");
                continue;
            }

            switch (commandLine[0]) {
                case "add" -> {
                    if (commandLine.length != 6) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }
                    Auto auto = new Auto(commandLine[1], commandLine[2], commandLine[3], commandLine[4],
                            Integer.parseInt(commandLine[5]));

                    // calcolo hash e aggiunta
                    int hash = hash(dimTab, commandLine[1]);
                    int posizione = 0;

                    // controlla collisioni da fare
                    if(tabella[hash] == null){
                        tabella[hash] = auto;
                        posizione = hash;
                    }else{
                        // se collide cerca posto vuoto
                        boolean vuoto = false;
                        for(int j = hash; j < tabella.length; j++){
                            if(tabella[j] == null){
                                vuoto = true;
                                posizione = j;
                                tabella[j] = auto;
                            }
                        }
                        if(!vuoto){
                            // continua con ricerca fino a inizio (posto vuoto non trovato)
                            for(int i = 0; i < hash; i++){
                                if(tabella[i] == null){
                                    vuoto = true;
                                    posizione = i;
                                    tabella[i] = auto;
                                }
                            }
                        }
                        if(!vuoto){
                            System.out.println("Tabella piena\n");
                            continue;
                        }
                    }

                    System.out.println("Inserimento effettuato con hash " + hash + " e inserita in posizione " + posizione);

                }
                case "search" -> {
                    if (commandLine.length != 2) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }

                    // calcolo hash e ricerca
                    int hash = hash(dimTab, commandLine[1]);
                    if(tabella[hash] == null){
                        System.out.println("Auto non trovata");
                    }

                    Auto autoTrovata = null;
                    int numAcc = 0;

                    // controlla collisioni da fare
                    if(Objects.equals(tabella[hash].getTarga(), commandLine[1])){
                        autoTrovata = tabella[hash];
                        numAcc++;
                    }else{
                        // non è uguale, vai avanti
                        boolean vuoto = false;
                        for(int j = hash; j < tabella.length; j++){
                            numAcc++;
                            if(Objects.equals(tabella[j].getTarga(), commandLine[1])){
                                vuoto = true;
                                autoTrovata = tabella[j];
                            }
                        }
                        if(!vuoto){
                            // continua con ricerca fino a inizio (posto vuoto non trovato)
                            for(int i = 0; i < hash; i++){
                                numAcc++;
                                if(Objects.equals(tabella[i].getTarga(), commandLine[1])){
                                    vuoto = true;
                                    autoTrovata = tabella[i];
                                }
                            }
                        }
                        if(!vuoto){
                            System.out.println("Auto non trovata\n");
                            continue;
                        }
                    }

                    if(autoTrovata != null){
                        System.out.println("Auto trovata con n.acc " + numAcc + ":");
                        System.out.println("  Posizione: " + hash);
                        System.out.println("  Targa: " + autoTrovata.getTarga());
                        System.out.println("  Marca: " + autoTrovata.getMarca());
                        System.out.println("  Modello: " + autoTrovata.getMarca());
                        System.out.println("  Colore: " + autoTrovata.getColore());
                        System.out.println("  Km: " + autoTrovata.getKm());
                        System.out.println();
                    }

                }
                default -> System.out.println("Comando sconosciuto");
            }

        } while (!Objects.equals(sc.nextLine(), "exit"));
    }

    private static int hash(int key, String value){
        // converte in char array
        char[] array = value.toCharArray();
        double sum = 0;
        for(int i = 0; i < array.length; i++){
            // prendiamo il valore in int di ogni char
            int j = array[i];
            // otteniamo l'inverso della posizione
            int inv = array.length - i;
            // aggiungiamo al valore in char il seno moltiplicato per 75 di 'inv' + il valore del char a array[inv]
            double sin = Math.sin(inv + array[inv - 1] + j) * 75.0;
            // aggiungiamo tutto alla somma finale
            sum += sin;
        }
        // usiamo un random con sempre lo stesso seme per ottenere numero in range
        Random random = new Random();
        random.setSeed((long) sum);
        return random.nextInt(key);
    }

}
