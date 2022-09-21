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

package EsercizioRettangoli;

/**
 * Rappresenta un rettangolo
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class Rettangolo {

    /**
     * Base del rettangolo
     */
    private float base;
    /**
     * Altezza del rettangolo
     */
    private float altezza;

    /**
     * Crea un nuovo rettangolo con base ed altezza specificati
     * se diversi da zero
     *
     * @param base    base del rettangolo
     * @param altezza altezza del rettangolo
     * @throws Exception se i valori sono minori di zero
     * @see Float
     */
    Rettangolo(
            float base,
            float altezza
    ) throws Exception {
        setAltezza(altezza);
        setBase(base);
    }


    /**
     * Ritorna l'altezza del rettangolo
     *
     * @return l'altezza del rettangolo
     * @see Float
     */
    public float getAltezza() {
        return altezza;
    }

    /**
     * Imposta l'altezza del rettangolo se maggiore di zero
     *
     * @param altezza altezza del rettangolo
     * @throws Exception se l'altezza è minore di zero
     * @see Float
     */
    public void setAltezza(float altezza) throws Exception {
        if (altezza > 0) {
            this.altezza = altezza;
        } else {
            throw new Exception();
        }
    }

    /**
     * Ritorna la base del rettangolo
     *
     * @return la base del rettangolo
     * @see Float
     */
    public float getBase() {
        return base;
    }

    /**
     * Imposta la base del rettangolo se maggiore di zero
     *
     * @param base altezza del rettangolo
     * @throws Exception se la base è minore di zero
     * @see Float
     */
    public void setBase(float base) throws Exception {
        if (base > 0) {
            this.base = base;
        } else {
            throw new Exception();
        }
    }

    /**
     * Calcola il perimetro del rettangolo se sia la base che
     * l'altezza sono diverse da zero
     *
     * @return il perimetro calcolato
     * @throws Exception se base o altezza diversi da zero
     * @see Float
     */
    public float calcolaPerimetro() throws Exception {
        if (base > 0 && altezza > 0) {
            return (base * 2) + (altezza * 2);
        } else {
            throw new Exception();
        }
    }

    /**
     * Calcola l'area del rettangolo se sia la base che
     * l'altezza sono diverse da zero
     *
     * @return l'area calcolato
     * @throws Exception se base o altezza diversi da zero
     * @see Float
     */
    public float calcolaArea() throws Exception {
        if (base > 0 && altezza > 0) {
            return base * altezza;
        } else {
            throw new Exception();
        }
    }
}
