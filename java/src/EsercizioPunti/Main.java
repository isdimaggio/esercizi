/*
Copyright 2022 Lo Mele Vittorio

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package EsercizioPunti;

import java.util.Objects;

/**
 * ESERCIZIO 2 (Rettangoli)
 * 27 settembre 2022
 * -----------------------
 * Traccia dell'esercizio non ancora definita
 * Per il momento, date le coordinate di quattro punti, istanzia due segmenti.
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class Main {

    /**
     * Traccia dell'esercizio non ancora definita.
     * PUNTO A   PUNTO B   PUNTO C   PUNTO D
     *
     * @param args le coordinate di quattro punti nel formato [x1] [y1] [x2] [y2] [x3] [y3] [x4] [y4]
     * @throws RuntimeException in caso di errori di calcolo
     */
    public static void main(String[] args) {

        String argomento1 = args[0]; // base 1 o flag di help

        Punto a1;
        Punto b1;
        Punto a2;
        Punto b2;

        Segmento s1;
        Segmento s2;

        try {
            // in caso di flag --help mostra aiuto
            if (Objects.equals(argomento1, "--help")) {
                System.out.println("Argomenti: [x1] [y1] [x2] [y2] [x3] [y3] [x4] [y4]");
                return;
            } else {
                a1 = new Punto(
                        Float.parseFloat(args[0]),
                        Float.parseFloat(args[1])
                );
            }

            b1 = new Punto(
                    Float.parseFloat(args[2]),
                    Float.parseFloat(args[3])
            );

            a2 = new Punto(
                    Float.parseFloat(args[4]),
                    Float.parseFloat(args[5])
            );

            b2 = new Punto(
                    Float.parseFloat(args[6]),
                    Float.parseFloat(args[7])
            );

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

        try {
            s1 = new Segmento(a1, b1);
            s2 = new Segmento(a2, b2);
        } catch (Exception e) {
            System.err.println("Punti non validi per formare i segmenti");
            return;
        }

        System.out.println("primo segmento passante: " + s1.passaggioPerOrigine());

    }

}

