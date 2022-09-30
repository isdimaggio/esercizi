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
 * Rappresenta un punto sul piano cartesiano
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class Punto {

    /**
     * Coordinata x del punto
     */
    private float coordX;
    /**
     * Coordinata y del punto
     */
    private float coordY;

    /**
     * Crea un nuovo punto con le coordinate specificate
     *
     * @param x coordinata delle x
     * @param y coordinata delle y
     * @see Float
     */
    public Punto(float x, float y) {
        coordY = y;
        coordX = x;
    }

    // getters
    public float getCoordX() {
        return coordX;
    }

    public float getCoordY() {
        return coordY;
    }

    // setters
    public void setCoordX(float x) {
        coordX = x;
    }

    public void setCoordY(float y) {
        coordY = y;
    }

    /**
     * Calcola la distanza da un altro punto
     *
     * @param p altro punto dal quale calcolare la distanza
     * @see Punto
     */
    public float distanzaDa(Punto p) {
        // formula per calcolare la distanza
        return (float) Math.sqrt(
                Math.pow(
                        p.getCoordX() - coordX, 2
                ) - Math.pow(
                        p.getCoordY() - coordY, 2
                )
        );
    }

    /**
     * Ritorna in quale quadrante si trova il punto
     * (INT da 0 a 4) dove zero significa che si trova su un asse
     */
    public int getQuadrante() {
        if (coordX == 0 | coordY == 0) {
            return 0; // punto su asse
        }

        if (coordX > 0) {
            // o primo o quarto
            if (coordY > 0) {
                return 1;
            } else {
                return 4;
            }
        } else {
            // o secondo o terzo
            if (coordY > 0) {
                return 2;
            } else {
                return 3;
            }
        }
    }

}
