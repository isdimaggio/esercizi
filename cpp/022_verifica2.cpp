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

ESERCIZIO n.22
Scrivere un algoritmo che acquisito in input un numero intero N maggiore 
di 1 stampi, a video tutti i numeri pari compresi tra 1 e N.
13/12/2021 (Verifica, ES.2)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    int n;
    // programma
    do
    {
        cout << "Inserisci un numero maggiore di 1: ";
        cin >> n;
    } while (n < 2);
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            cout << i + 1 << endl;
        }
    }
    return 0;
}
