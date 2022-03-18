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

ESERCIZIO n.19
Dato un numero intero calcola la somma dei primi n positivi.
29/11/2021 (Esercitazione di laboratorio)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    int n, tot = 0;
    // programma
    cout << "Inserisci il numero: ";
    cin >> n;
    for(int i = 0; i <= n; i++){
        tot = tot + i;
    }
    cout << tot;
    return 0;
}
