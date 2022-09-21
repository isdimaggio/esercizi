package EsercizioRettangoli;

import java.util.Objects;

/**
 * ESERCIZIO 1 (Rettangoli)
 * 21 settembre 2022
 * -----------------------
 * Scrivere un programma Java che istanzia due rettangoli con le basi e
 * l'altezza passati da riga di comando e ne confronta l'area e il perimetro.
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class Main {

    /**
     * Programma che ricevuti in input i dati di base ed altezza di due
     * rettangoli confronta perimetri ed aree e determina i maggiori.
     *
     * @param args array di 4 float nell'ordine [b1] [h1] [b2] [h2]
     * @throws RuntimeException in caso di errori di calcolo
     */
    public static void main(String[] args) {
        String argomento1 = args[0]; // base 1 o flag di help

        Rettangolo primoRettangolo = null;
        Rettangolo secondoRettangolo = null;

        float base1 = 0;
        float altezza1 = 0;
        float base2 = 0;
        float altezza2 = 0;

        try {
            // in caso di flag --help mostra aiuto
            if (Objects.equals(argomento1, "--help")) {
                System.out.println("Argomenti: [b1] [h1] [b2] [h2]");
                return;
            } else {
                base1 = Float.parseFloat(args[0]);
            }

            altezza1 = Float.parseFloat(args[1]);
            base2 = Float.parseFloat(args[2]);
            altezza2 = Float.parseFloat(args[3]);

        } catch (NullPointerException e) {
            System.err.println("I valori non possono essere nulli!");
            return;
        } catch (NumberFormatException e) {
            System.err.println("I valori devono essere numeri validi!");
            return;
        } catch (ArrayIndexOutOfBoundsException e) {
            System.err.println("Non hai fornito abbastanza valori.");
            return;
        }

        // imposta il primo rettangolo
        try {
            primoRettangolo = new Rettangolo(base1, altezza1);
        } catch (Exception e) {
            System.err.println("Valori invalidi per il primo rettangolo");
            return; // termina esecuzione programma
        }

        // imposta il secondo rettangolo
        try {
            secondoRettangolo = new Rettangolo(base2, altezza2);
        } catch (Exception e) {
            System.err.println("Valori invalidi per il secondo rettangolo");
            return; // termina esecuzione programma
        }

        try {
            System.out.println(
                    "[PRIMO] Perimetro: " +
                            primoRettangolo.calcolaPerimetro() +
                            " Area: " +
                            primoRettangolo.calcolaArea()
            );
            System.out.println(
                    "[SECONDO] Perimetro: " +
                            secondoRettangolo.calcolaPerimetro() +
                            " Area: " +
                            secondoRettangolo.calcolaArea()
            );

            System.out.println();

            if (primoRettangolo.calcolaPerimetro() > secondoRettangolo.calcolaPerimetro()) {
                System.out.println("Il perimetro del primo rettangolo è maggiore.");
            } else if (primoRettangolo.calcolaPerimetro() < secondoRettangolo.calcolaPerimetro()) {
                System.out.println("Il perimetro del secondo rettangolo è maggiore.");
            } else {
                System.out.println("I perimetri dei due rettangoli sono uguali.");
            }

            if (primoRettangolo.calcolaArea() > secondoRettangolo.calcolaArea()) {
                System.out.println("L'area del primo rettangolo è maggiore.");
            } else if (primoRettangolo.calcolaArea() < secondoRettangolo.calcolaArea()) {
                System.out.println("L'area del secondo rettangolo è maggiore.");
            } else {
                System.out.println("Le aree dei due rettangoli sono uguali.");
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

}
