package HashTableV2;

import java.util.Objects;
import java.util.Scanner;

public class MainTest {

    static HashTable tabella;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.println("Inserisci dimensioni tabella:");
        int dimTab = sc.nextInt();
        System.out.println();

        tabella = new HashTable(dimTab);

        System.out.println("USAGE (premere un paio di volte invio se non va menu)");
        System.out.println(" add {chiave} {valore}");
        System.out.println(" search {chiave}");
        System.out.println(" resize {nuovadim}");
        System.out.println(" loadfactor calc");
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
                    if (commandLine.length != 3) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }

                    tabella.insert(commandLine[1], commandLine[2]);
                    System.out.println("Inserimento effettuato");

                }
                case "search" -> {
                    if (commandLine.length != 2) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }

                    System.out.println("Valore per chiave: " + tabella.search(commandLine[1]));

                }
                case "loadfactor" -> {
                    System.out.println("Load factor: " + tabella.loadFactor());

                }
                case "resize" -> {
                    if (commandLine.length != 2) {
                        System.out.println("Argomenti invalidi");
                        continue;
                    }

                    tabella.resize(Integer.parseInt(commandLine[1]));

                    System.out.println("Resize effettuato con nuova dimensione: " + commandLine[1]);

                }
                default -> System.out.println("Comando sconosciuto");
            }

        } while (!Objects.equals(sc.nextLine(), "exit"));
    }

}
