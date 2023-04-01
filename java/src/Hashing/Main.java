package Hashing;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("Inserisci valore di N: ");
        int n = sc.nextInt();
        while(true){
            System.out.print("Inserisci stringa: ");
            String s = sc.next();
            if(s.equals(";")) System.exit(0);
            System.out.println("Hash calcolato: " + hash(n, s));
        }
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
