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

ESERCIZIO n.23
Dopo aver inserito due valori numerici interi (num_1, num_2) verificando
che il primo sia inferiore al secondo, chiedere in input un terzo numero (num_3) 
compreso tra num_1 e num_2 ( num_1 < num_3 < num_2) e visualizzare tutti i multipli 
del terzo numero compresi tra i primi due numeri inseriti.
13/12/2021 (Verifica, ES.3)
*/

#include <iostream>

using namespace std;

void controllaMultiplo(int n, int m);

int main()
{
    // dichiarazione variabili
    int num_1, num_2, num_3;
    // programma
    do
    {
        cout << "Inserisci il primo numero: ";
        cin >> num_1;
        cout << "Inserisci il secondo numero (superiore al primo): ";
        cin >> num_2;
    } while (num_2 < num_1);

    do
    {
        cout << "Inserisci un numero compreso tra il primo ed il secondo: ";
        cin >> num_3;
    } while (num_3 < num_1 || num_3 > num_2);

    cout << "I multipli di " << num_3 << " compresi tra " << num_1 << " e " << num_2 << " sono:" << endl;

    for (int i = num_1; i <= num_2; i++)
    {
        controllaMultiplo(i, num_3);
    }

    return 0;
}

void controllaMultiplo(int n, int m)
{
    if ((n % m) == 0)
    {
        cout << n << endl;
    }
}