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

package EsercizioOra;

/**
 * Rappresenta una data sul calendario.
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class Data {

    /**
     * Associa a ogni giorno del mese (indice dell' array) il numero di giorni.
     */
    private final int[] ggMesi = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /**
     * Associa a ogni resto della formula di calcolo del giorno
     * della settimana il giorno leggibile.
     */
    private final String[] mappeResti = {
            "Sabato",
            "Domenica",
            "Lunedì",
            "Martedì",
            "Mercoledì",
            "Giovedì",
            "Venerdì"
    };

    private int giorno;
    private int mese;
    private int anno;

    /**
     * Crea un nuovo oggetto data con i parametri specificati.
     *
     * @param giorno giorno
     * @param mese   mese
     * @param anno   anno
     * @throws Exception se fornita una data invalida
     */
    public Data(
            int giorno,
            int mese,
            int anno
    ) throws Exception {
        setAnno(anno);

        // se bisestile febbraio ha 29 gg
        if (isBisestile()) ggMesi[2] = 29;

        setMese(mese);
        setGiorno(giorno);
    }

    /**
     * Dato un anno ritorna il numero di giorni
     *
     * @param anno anno
     * @return int numero di giorni dell'"anno" specificato
     */
    private int numGGAnno(int anno) {
        if (anno % 400 == 0 ||
                (anno % 4 == 0 &&
                        !(anno % 100 == 0))) {
            // bisestile
            return 366;
        } else {
            return 365;
        }
    }

    // getters and setters
    public int getGiorno() {
        return giorno;
    }

    public void setGiorno(int giorno) throws Exception {
        //
        if (giorno > 31) {
            throw new Exception(); // giorni da 32 non esistono
        }

        // trenta gg a novembre(11), ad aprile(4) giugno(6) e settembre(9)
        if (giorno > 30) {
            if (getMese() == 11 || getMese() == 4 || getMese() == 6 || getMese() == 9) {
                throw new Exception();
            }
        }

        // controllo febbraio e bisestile
        if (giorno > 28 && getMese() == 2) {
            if (!isBisestile()) throw new Exception();
        }

        this.giorno = giorno;
    }

    public int getMese() {
        return mese;
    }

    public void setMese(int mese) throws Exception {
        if (mese > 0 && mese < 13) {
            this.mese = mese;
        } else {
            throw new Exception();
        }
    }

    public int getAnno() {
        return anno;
    }

    public void setAnno(int anno) throws Exception {
        if (anno >= 0) {
            this.anno = anno;
        } else {
            throw new Exception();
        }
    }

    /**
     * Restituisce true se l'anno è bisestile.
     *
     * @return boolean
     * @see Boolean
     */
    public boolean isBisestile() {
        return getAnno() % 400 == 0 ||
                (getAnno() % 4 == 0 &&
                        !(getAnno() % 100 == 0));
    }

    /**
     * Calcola i giorni passati da inizio anno
     *
     * @return integer
     * @see Integer
     */
    public int giorniDaInizioAnno() {
        int ggacc = 0;
        for (int i = 0; i < getMese() - 1; i++) {
            ggacc += ggMesi[i];
        }
        return getGiorno() + ggacc;
    }

    /**
     * Calcola i giorni che rimangono per finire l'anno
     *
     * @return integer
     * @see Integer
     */
    public int giorniAFineAnno() {
        int gt = 365;
        if (isBisestile()) gt++;
        for (int i = 0; i < getMese() - 1; i++) {
            gt -= ggMesi[i];
        }
        return gt - getGiorno();
    }

    /**
     * Calcola la distanza in giorni dall'altra data.
     *
     * @param d2 altra data
     * @return int
     */
    public int distanzaDaData(Data d2) {
        int ggPrima = 0;
        int ggSeconda = 0;
        // conversione in gg della prima data
        for (int i = 0; i < getAnno(); i++) {
            ggPrima += numGGAnno(i);
        }
        for (int i = 0; i < getMese() - 1; i++) {
            ggPrima += ggMesi[i];
        }
        ggPrima += getGiorno();

        // conversione in gg della seconda data
        for (int i = 0; i < d2.getAnno(); i++) {
            ggSeconda += numGGAnno(i);
        }
        for (int i = 0; i < d2.getMese() - 1; i++) {
            ggSeconda += ggMesi[i];
        }
        ggPrima += d2.getGiorno();

        return ggPrima - ggSeconda;
    }

    /**
     * Calcola il giorno della settimana corrispondente alla data.
     *
     * @return String
     * @see <a href="http://calendario.eugeniosongia.com/formula.htm">Formule calendario</a>
     */
    public String giornoDellaSettimana() {
        // calcolo quozienti
        int q4 = (getAnno() - 1) / 4;
        int q100 = (getAnno() - 1) / 100;
        int q400 = (getAnno() - 1) / 400;

        // formula regolare
        int x = getAnno() + q4 - q100 + q400 + giorniDaInizioAnno();

        if (getAnno() < 1583) {
            if (getMese() < 11) {
                if (getGiorno() < 16) {
                    // formula pre riforma gregoriana
                    x = getAnno() + q4 + giorniDaInizioAnno() - 2;
                }
            }
        }

        return mappeResti[x % 7];
    }

}
