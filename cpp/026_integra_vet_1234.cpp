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

ESERCIZIO n.26 - Esercizio integrativo (1,2,3,4) sui vettori.
--------------
Esercizio 1
Scrivere un programma che riempia un vettore di 10 elementi di tipo int. 
Alla fine, visualizzare a video i dati memorizzati nel vettore.
--------------
Esercizio 2
Continuo esercizio 1. Visualizzare a video gli elementi del 
vettore partendo dall’ultima posizione.
--------------
Esercizio 3
Scrivere un programma che riempito un vettore di 10 elementi, 
visualizzi a video gli elementi di posizione pari.
--------------
Esercizio 4
Scrivere un programma che dopo aver caricato un vettore 
di N componenti, con N<= 10, calcoli il prodotto delle componenti di posto 
pari e la somma di quelle dispari.
--------------
21/02/2022 (Esercitazione in laboratorio)
*/

#include <iostream>

using namespace std;

int main()
{
    int vet[10];
    int add = 0, mul = 1;
    // caricamento vettore
    for (int i = 0; i < 10; i++)
    {
        cout << "Inserisci intero nella cella " << i << ": ";
        cin >> vet[i];
    }
    // esercizio 1
    for (int i = 0; i < 10; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
    // esercizio 2
    for (int i = 10; i > 0; i--)
    {
        cout << vet[i - 1] << " ";
    }
    cout << endl;
    // esercizio 3
    for (int i = 0; i < 10; i = i + 2)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
    // esercizio 4
    for (int i = 0; i < 10; i++)
    {
        if ((i % 2) == 0)
        {
            mul = mul * vet[i];
        }
        else
        {
            add = add + vet[i];
        }
    }
    // esercizio extra
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if(vet[i] > max){
            max = vet[i];
        }
    }
    cout << "La somma è " << add << endl;
    cout << "Il prodotto è " << mul << endl;
    cout << "Il numero massimo " << max << endl;
    return 0;
}
