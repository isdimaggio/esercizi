/*
Copyright 2021 Lo Mele Vittorio

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

ESERCIZIO n.21
Scrivere un algoritmo che calcoli il prodotto di due numeri 
(assumendo come nota l’addizione).
13/12/2021 (Verifica, ES.1)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    int a, b, ris = 0;
    // programma
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        ris = ris + a;
    }
    cout << "Il risultato è " << ris << endl;
    return 0;
}
