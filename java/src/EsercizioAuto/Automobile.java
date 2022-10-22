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

package EsercizioAuto;

/**
 * Rappresenta un automobile.
 * VEDI README.
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class Automobile {

    /**
     * Velocità massima che raggiunge l'auto
     * alla quale si attiva il limitatore anche se il numero
     * di giri non è arrivato al massimo.
     */
    private int velocitaMassima;
    /**
     * Array che per ogni marcia (indice) ne indica il rapporto.
     */
    private final int[] marce;
    /**
     * Marcia corrente dove si trova l'auto.
     */
    private int marcia;
    /**
     * Il rapporto del differenziale
     */
    private final int rapportoDifferenziale;
    /**
     * Limitatore dei giri motore.
     */
    private int giriMotoreMassimi;
    /**
     * Giri motore di base.
     */
    private int giriMotoreMinimi;
    /**
     * Giri a cui si trova il motore.
     */
    private int giriMotore;
    /**
     * Stato del motore (acceso o spento)
     */
    private boolean statoMotore;

    /**
     * Diametro in pollici delle ruote
     */
    private final int diametroRuote;

    public Automobile(
            int velocitaMassima,
            int[] marce,
            int giriMotoreMassimi,
            int giriMotoreMinimi,
            int rapportoDifferenziale,
            int diametroRuote
    ) {
        setVelocitaMassima(velocitaMassima);
        this.marce = marce;
        this.rapportoDifferenziale = rapportoDifferenziale;
        this.diametroRuote = diametroRuote;
        setGiriMotoreMassimi(giriMotoreMassimi);
        setGiriMotoreMinimi(giriMotoreMinimi);

        // default
        setMarcia(1);
        setGiriMotore(0);
        setStatoMotore(false);
    }

    // GETTERS AND SETTERS
    public int getDiametroRuote() {
        return diametroRuote;
    }

    public int getGiriMotoreMinimi() {
        return giriMotoreMinimi;
    }

    public void setGiriMotoreMinimi(int giriMotoreMinimi) {
        this.giriMotoreMinimi = giriMotoreMinimi;
    }

    public int getVelocitaMassima() {
        return velocitaMassima;
    }

    public void setVelocitaMassima(int velocitaMassima) {
        this.velocitaMassima = velocitaMassima;
    }

    public int[] getMarce() {
        return marce;
    }

    public int getMarcia() {
        return marcia;
    }

    public void setMarcia(int marcia) {
        this.marcia = marcia;
    }

    public int getRapportoDifferenziale() {
        return rapportoDifferenziale;
    }

    public int getGiriMotoreMassimi() {
        return giriMotoreMassimi;
    }

    public void setGiriMotoreMassimi(int giriMotoreMassimi) {
        this.giriMotoreMassimi = giriMotoreMassimi;
    }

    public int getGiriMotore() {
        return giriMotore;
    }

    private void setGiriMotore(int giriMotore) {
        this.giriMotore = giriMotore;
    }

    public boolean isStatoMotore() {
        return statoMotore;
    }

    private void setStatoMotore(boolean statoMotore) {
        this.statoMotore = statoMotore;
    }

    /**
     * Accende il motore solo se spento e con il cambio in prima marcia.
     *
     * @throws Exception se si tenta di partire in seconda o superiore
     * @throws Exception se il motore è già acceso
     */
    public void accendiMotore() throws Exception {
        if (getMarcia() != 1 || !statoMotore) {
            throw new Exception();
        }
        setStatoMotore(true);
        setGiriMotore(getGiriMotoreMinimi());
    }

    /**
     * Spegne il motore solo se acceso.
     *
     * @throws Exception se il motore è già spento
     */
    public void spegniMotore() throws Exception {
        if (!statoMotore) {
            throw new Exception();
        }
        setStatoMotore(false);
    }

    /**
     * Aumenta i giri del motore
     *
     * @param step di quanti giri aumentare i giri motore
     * @throws Exception se si raggiunge il limitatore di giri
     * @throws Exception se si raggiunge il limitatore di velocità
     * @throws Exception se il motore è spento
     */
    public void accelera(int step) throws Exception {
        if (!isStatoMotore()) throw new Exception();
        int nuoviGiri = getGiriMotore() + step;
        if (nuoviGiri > getGiriMotoreMassimi()) {
            throw new Exception(); // rev limiter raggiunto
        }
        if (calcolaVelocita(nuoviGiri) > velocitaMassima) throw new Exception();
        setGiriMotore(nuoviGiri);
    }

    /**
     * Aumenta i giri del motore di 100 rpm
     *
     * @throws Exception se si raggiunge il limitatore di giri
     * @throws Exception se si raggiunge il limitatore di velocità
     * @throws Exception se il motore è spento
     */
    public void accelera() throws Exception {
        accelera(200);
    }

    /**
     * Togli giri al motore
     *
     * @param step di quanti giri diminuire i giri motore
     * @throws Exception se si raggiunge il limitatore di giri minimi
     * @throws Exception se il motore è spento
     */
    public void decelera(int step) throws Exception {
        if (!isStatoMotore()) throw new Exception();
        int nuoviGiri = getGiriMotore() - step;
        if (nuoviGiri < getGiriMotoreMinimi()) {
            throw new Exception(); // idle raggiunto
        }
        setGiriMotore(nuoviGiri);
    }

    /**
     * Togli 100 rpm al motore
     *
     * @throws Exception se si raggiunge il limitatore di giri minimi
     * @throws Exception se il motore è spento
     */
    public void decelera() throws Exception {
        decelera(200);
    }

    /**
     * Cambia la marcia della trasmissione
     *
     * @throws Exception se si prova a saltare più di una marcia
     * @throws Exception se si inserisce una marcia inesistente
     * @throws Exception se si inserisce la stessa marcia
     */
    public void cambiaMarcia(int marcia) throws Exception {
        if (marcia < 1 || marcia > getMarce().length) {
            throw new Exception();
        }

        if (getMarcia() == marcia) throw new Exception();

        if (marcia != getMarcia() + 1 && marcia != getMarcia() - 1) {
            throw new Exception();
        }

        setMarcia(marcia);
    }

    /**
     * Calcola la velocità massima teorica raggiungibile.
     *
     * @param rpm giri del motore
     * @return velocità massima teorica della vettura
     */
    public int calcolaVelocita(int rpm) {
        // rpm * gear ratio * diff ratio * wheel circ
        return rpm * getMarce()[marcia - 1] * getRapportoDifferenziale() * getDiametroRuote();
    }

    public int calcolaVelocita() {
        return calcolaVelocita(getGiriMotore());
    }

}
