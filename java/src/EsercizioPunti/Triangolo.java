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

/**
 * Rappresenta un triangolo sul piano cartesiano
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */

public class Triangolo {

    /**
     * Punto A del triangolo
     */
    private final Punto puntoA;

    /**
     * Punto B del triangolo
     */
    private final Punto puntoB;

    /**
     * Punto C del triangolo
     */
    private final Punto puntoC;

    /**
     * Lunghezza del primo segmento
     */
    private final float lunghezzaAb;

    /**
     * Punto C del triangolo
     */
    private final float lunghezzaBc;

    /**
     * Punto C del triangolo
     */
    private final float lunghezzaCa;

    /**
     * Crea un nuovo triangolo con i tre punti specificati
     *
     * @param a punto a
     * @param b punto b
     * @param c punto c
     * @see Punto
     */
    public Triangolo(Punto a, Punto b, Punto c) {
        // assegna punti
        puntoA = a;
        puntoB = b;
        puntoC = c;
        // calcola segmenti
        lunghezzaAb = puntoA.distanzaDa(puntoB);
        lunghezzaBc = puntoB.distanzaDa(puntoC);
        lunghezzaCa = puntoC.distanzaDa(puntoA);
    }

    // getters
    public Punto getPuntoA() {
        return puntoA;
    }

    public Punto getPuntoB() {
        return puntoB;
    }

    public Punto getPuntoC() {
        return puntoC;
    }

    /**
     * Ritorna il perimetro del triangolo.
     *
     * @return perimetro del triangolo
     */
    public float getPerimetro() {
        return lunghezzaAb + lunghezzaBc + lunghezzaCa;
    }

    /**
     * Ritorna l'area del triangolo.
     * L'area viene calcolata con la formula di Erone.
     *
     * @return area del triangolo
     */
    public float getArea() {
        float semiPerimetro = getPerimetro() / 2;
        return (float) Math.sqrt(
                semiPerimetro *
                        (semiPerimetro - lunghezzaAb) *
                        (semiPerimetro - lunghezzaBc) *
                        (semiPerimetro - lunghezzaCa)
        );
    }

    /**
     * Ritorna l'area del triangolo.
     *
     * @return "isoscele" | "scaleno" | "equilatero"
     */
    public String getTipo() {
        // se tutti e tre i lati sono uguali
        if (
                lunghezzaAb == lunghezzaBc &&
                        lunghezzaCa == lunghezzaAb
        ) {
            return "equilatero";
        }

        if (
                lunghezzaAb == lunghezzaBc ||
                        lunghezzaCa == lunghezzaAb
        ) {
            return "isoscele";
        }
        return "scaleno";
    }

}
