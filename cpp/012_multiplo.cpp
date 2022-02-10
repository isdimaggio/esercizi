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

ESERCIZIO n.12 -  Dati due numeri verifica che il secondo sia multiplo del primo
08/11/2021 (Esercitazione in laboratorio)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    int a, b;
    // programma
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    if((a % b) == 0)
    {
        cout << "Il secondo numero è multiplo del primo :)" << endl;
    }
    else
    {
        cout << "Il secondo numero non è multiplo del primo :(" << endl;
    }
    return 0;
}
