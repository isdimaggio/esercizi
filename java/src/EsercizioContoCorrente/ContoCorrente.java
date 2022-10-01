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

package EsercizioContoCorrente;

/**
 * Rappresenta un conto corrente.
 *
 * @author Vittorio Lo Mele
 * @author hi@vitto.dev
 */
public class ContoCorrente {

    /**
     * Nome dell'intestatario
     */
    public String nome;
    /**
     * Cognome dell'intestatario
     */
    public String cognome;
    /**
     * IBAN di 27 cifre
     */
    public String iban;
    /**
     * Saldo contabile del conto
     */
    public float saldo;

    /**
     * Crea un nuovo conto corrente con i dati specificati.
     *
     * @param nome Nome dell'intestatario
     * @param cognome cognome dell'intestatario
     * @param iban IBAN a 27 cifre
     * @param saldo saldo iniziale del conto
     */
    public ContoCorrente (
            String nome,
            String cognome,
            String iban,
            float saldo
    )throws Exception{
        if(iban.length() != 27){
            throw new Exception();
        }
        this.nome = nome;
        this.cognome = cognome;
        this.iban = iban;
        this.saldo = saldo;
    }

    //getters and setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getIban() {
        return iban;
    }

    public boolean setIban(String iban) {
        if(iban.length() != 27){
            return false;
        }else{
            return true;
        }
    }

    public float getSaldo() {
        return saldo;
    }

    public boolean setSaldo(float saldo) {
        if (saldo < 0){
            return false;
        }
        this.saldo = saldo;
        return true;
    }

    /**
     * Versa dei soldi nel conto corrente.
     * @param importo importo da versare
     *
     */
    public void versa(float importo) {
        setSaldo(getSaldo() + importo);
    }

    /**
     * Se disponibili, preleva dei soldi dal conto corrente.
     * @param importo importo da prelevare
     *
     */
    public boolean preleva(float importo){
        if(importo > getSaldo()) {
            return false;
        }
        setSaldo(getSaldo() - importo);
        return true;
    }

}
