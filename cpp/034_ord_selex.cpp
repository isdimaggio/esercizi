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

Dato un vettore di 10 elementi con l'ausilio delle funzioni ordinarlo
utilizzando il metodo di selezione.
19/04/2022 (Esercitazione a casa)
*/

#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

void visualizza_vettore(int vet[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "[" << vet[i] << "]";
    }
}

void scambia(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

int posiz_min(int vet[], int dim, int pos)
{
    int min, posmin;
    min = vet[pos];
    posmin = pos;
    for (int i = pos + 1; i < dim; ++i)
    {
        if (min > vet[i])
        {
            min = vet[i];
            posmin = i;
        }
    }
    return posmin;
}

int main(void)
{
    srand(time(NULL));

    // creazione vettore
    int num;
    cout << "Inserisci il numero di elementi: ";
    cin >> num;
    int vet[num];

    // caricamento vettore
    for (int i = 0; i < num; i++)
    {
        vet[i] = (rand() % 100) + 1;
    }

    // visualizzazione pre ordinamento
    cout << "Vettore pre ordinamento: ";
    visualizza_vettore(vet, num);
    cout << endl;

    // misura tempo exec
    auto start = high_resolution_clock::now();

    // ordina vettore
    for (int i = 0; i < num; i++)
    {
        int p_min = posiz_min(vet, num, i);
        scambia(vet[i], vet[p_min]);
    }

    // misura tempo exec
    auto end = high_resolution_clock::now();

    // visualizzazione post ordinamento
    cout << "Vettore post ordinamento: ";
    visualizza_vettore(vet, num);
    cout << endl;

    // calcolo tempo sorting
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Sorting durato: " << duration.count() << " microsecondi" << endl;
}