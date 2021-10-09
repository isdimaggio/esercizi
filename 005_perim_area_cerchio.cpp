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

ESERCIZIO n.5 -  Prelevare in input il valore del raggio del cerchio
e calcolarne perimetro ed area.
09/10/2021 (Esercizio per casa)
*/

#include <iostream>

#define PI_GRECO 3.14

using namespace std;

int main()
{
    // dichiarazione variabili
    int raggio;
    //programma
    cout << "Inserisci il raggio del cerchio: ";
    cin >> raggio;
    cout << "Il perimetro del cerchio è " << 2 * raggio * PI_GRECO << endl;
    cout << "L'area del cerchio è " << (raggio * raggio) * PI_GRECO << endl;
    return 0;
}