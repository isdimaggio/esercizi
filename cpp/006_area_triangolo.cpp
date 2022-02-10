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

ESERCIZIO n.6 -  Prelevare in input i valori di base ed altezza di un
triangolo e calcolarne l'area.
09/10/2021 (Esercizio per casa)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    int base, altezza;
    //programma
    cout << "Inserisci la base del triangolo: ";
    cin >> base;
    cout << "Inserisci l' altezza del triangolo: ";
    cin >> altezza;
    cout << "L'area del triangolo è " << (base * altezza)/2 << endl;
    return 0;
}