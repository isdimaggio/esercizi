/*
Copyright 2021 Lo Mele Vittorio  / Loris Lurdo

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

ESERCIZIO n.30 - Dato un vettore di 15 elementi, inserire un numero da 
tastiera e controllare se esiste nel vettore. In caso affermativo, 
contare quante volte compare all’interno del vettore e visualizzare a 
video la risposta e l’eventuale numero di volte che compare.
28/02/2022 (Esercitazione in laboratorio)
*/

#include <iostream>

using namespace std;

int main(void)
{

    int vet[15], conta = 0, num;

    for (int i = 0; i < 15; i++)
    {
        cout << "Inserisci il contenuto del vettore: ";
        cin >> vet[i];
    }

    cout << "Inserisci il numero da voler controllare: ";
    cin >> num;

    for (int i = 0; i < 15; i++)
    {
        if (vet[i] == num)
        {
            conta++;
        }
    }
    if (conta != 0)
    {
        cout << "Il numero " << num << " è presente nel vettore " << conta << " volte";
    }
    else
    {
        cout << "Il numero " << num << " non è presente nel vettore";
    }
}