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

public class Taxi extends Automobile {

    private int numeroPosti;
    private float tariffaAKM;

    public Taxi(
            int velocitaMassima,
            int[] marce,
            int giriMotoreMassimi,
            int giriMotoreMinimi,
            int rapportoDifferenziale,
            int diametroRuote,
            int numeroPosti,
            float tariffaAKM
    ) throws Exception {
        super(velocitaMassima, marce, giriMotoreMassimi, giriMotoreMinimi, rapportoDifferenziale, diametroRuote);
        if (numeroPosti < 2) {
            throw new Exception("numero non valido di posti");
        }
        this.numeroPosti = numeroPosti;
        if (tariffaAKM < 0) {
            throw new Exception("tariffa non valida");
        }
        this.tariffaAKM = tariffaAKM;
    }
}
