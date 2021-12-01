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

ESERCIZIO n.20
Stampa i primi multipli n di k
29/11/2021 (Esercitazione di laboratorio)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    int n, k, p = 0;
    // programma
    cout << "Inserisci il numero: ";
    cin >> n;
    cout << "Inserisci la costante: ";
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        p = k*i;
        cout << p << " ";
    }
    return 0;
}
