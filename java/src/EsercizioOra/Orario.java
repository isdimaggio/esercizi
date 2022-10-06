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
 * Rappresenta un orario.
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class Orario {

    /**
     * Ore dall'inizio della giornata
     */
    int ore;
    /**
     * Minuti dall'inizio dell'ora
     */
    int minuti;
    /**
     * Secondi dall'inizio del minuto
     */
    int secondi;

    /**
     * Crea un nuovo oggetto con l'orario specificato
     *
     * @param ore     Ore dall'inizio della giornata
     * @param minuti  Minuti dall'inizio dell'ora
     * @param secondi Secondi dall'inizio del minuto
     * @throws Exception se forniti numeri negativi
     */
    public Orario(
            int ore,
            int minuti,
            int secondi
    ) throws Exception {
        // niente negativi
        setOre(ore);
        setMinuti(minuti);
        setSecondi(secondi);
    }

    // getter and setter
    public int getOre() {
        return ore;
    }

    public void setOre(int ore) throws Exception {
        if (ore < 0) throw new Exception();
        this.ore = ore;
    }

    public int getMinuti() {
        return minuti;
    }

    public void setMinuti(int minuti) throws Exception {
        if (minuti < 0) throw new Exception();
        this.minuti = minuti;
    }

    public int getSecondi() {
        return secondi;
    }

    public void setSecondi(int secondi) throws Exception {
        if (secondi < 0) throw new Exception();
        this.secondi = secondi;
    }

    /**
     * Tempo passato dall'inizio della giornata in secondi
     *
     * @return int
     */
    int secondiDaInizioGiornata() {
        return (ore * 3600) + (minuti * 60) + secondi;
    }

    /**
     * Tempo in secondi per arrivare a fine giornata
     *
     * @return int
     */
    int secondiAFineGiornata() {
        return 86400 - secondiDaInizioGiornata();
    }

    /**
     * Distanza da un altro orario in secondi
     *
     * @param o2 altro orario
     * @return int
     */
    int distanzaDaOrarioInSecondi(Orario o2) {
        return Math.abs(
                secondiDaInizioGiornata() -
                        o2.secondiDaInizioGiornata()
        );
    }

    /**
     * Stampa formattata in HH:mm:ss
     *
     * @return String
     */
    String oraPerStampa() {
        String hh, mm, ss;

        if (getOre() < 10) {
            hh = "0" + getOre();
        } else {
            hh = Integer.toString(getOre());
        }

        if (getMinuti() < 10) {
            mm = "0" + getMinuti();
        } else {
            mm = Integer.toString(getMinuti());
        }

        if (getSecondi() < 10) {
            ss = "0" + getSecondi();
        } else {
            ss = Integer.toString(getSecondi());
        }
        return "%s:%s:%s".formatted(hh, mm, ss);
    }

}
