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

ESERCIZIO n.31 - Riempire un vettore di N elementi, fare la somma 
e calcolare la media.
28/02/2022 (Esercitazione in laboratorio)
*/

#include <iostream>
using namespace std;

int main(void)
{

    int num;
    float media = 0, som = 0;

    cout << "Inserisci il numero di elementi: ";
    cin >> num;
    int vet[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Inserisci il contenuto del vettore: ";
        cin >> vet[i];
    }

    for (int i = 0; i < num; i++)
    {
        som = som + vet[i];
    }

    media = som / num;
    cout << "La somma del vettore è " << som << endl;
    cout << "La media del vettore è " << media;
}