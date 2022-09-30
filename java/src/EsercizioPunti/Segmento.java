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
 * Rappresenta un segmento sul piano cartesiano
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class Segmento {

    /**
     * Punto iniziale del segmento
     */
    private final Punto puntoA;

    /**
     * Punto finale del segmento
     */
    private final Punto puntoB;

    /**
     * Crea un nuovo segmento con punto d' inizio e fine specificati
     *
     * @param a punto d'inizio del segmento
     * @param b punto di fine del segmento
     * @throws Exception se i punti forniti sono uguali
     * @see Punto
     */
    public Segmento(Punto a, Punto b) throws Exception {

        if (a.getCoordY() == b.getCoordY() &&
                b.getCoordX() == b.getCoordX()
        ) {
            // un segmento non può essere fatto da due punti uguali
            throw new Exception();
        }

        puntoA = a;
        puntoB = b;
    }

    // getters
    public Punto getPuntoA() {
        return puntoA;
    }

    public Punto getPuntoB() {
        return puntoB;
    }

    /**
     * Ritorna la lunghezza del segmento
     *
     * @return la lunghezza del segmento
     */
    public float calcolaLunghezza() {
        // la lunghezza del segmento equivale alla distanza tra i punti
        return puntoA.distanzaDa(puntoB);
    }

    /**
     * Ritorna vero se il segmento interseca l'asse Y
     *
     * @return bool
     */
    public boolean intersezioneAsseY() {
        // se una delle due x ha il segno opposto all'altro

        if (puntoA.getCoordX() >= 0 && puntoB.getCoordX() < 0) {
            return true;
        }

        return puntoA.getCoordX() < 0 && puntoB.getCoordX() >= 0;
    }

    /**
     * Ritorna vero se il segmento interseca l'asse X
     *
     * @return bool
     */
    public boolean intersezioneAsseX() {
        // se una delle due y ha il segno opposto all'altro

        if (puntoA.getCoordY() >= 0 && puntoB.getCoordY() < 0) {
            return true;
        }

        return puntoA.getCoordY() < 0 && puntoB.getCoordY() >= 0;
    }

    /**
     * Ritorna vero se il segmento passa per l'origine
     *
     * @return bool
     */
    public boolean passaggioPerOrigine() {
        return puntoA.getCoordY() / puntoA.getCoordX() == puntoB.getCoordY() / puntoB.getCoordX();
    }

}
