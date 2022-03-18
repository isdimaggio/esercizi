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

ESERCIZIO n.28 - Dopo aver riempito un vettore di 10 elementi utilizzando
la funzione random con numeri interi compresi tra 0 e 100, copiare i valori
inferiori a 50 in un vettore e quelli uguali o superiori in un altro vettore.
Visualizzare entrambi i vettori. Poi fare la somma degli elementi del primo
vettore risultante e la somma degli elementi del secondo vettore risultante
e dire quale somma è maggiore.
28/02/2022 (Esercitazione in laboratorio)
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    // dichiarazione variabili
    int vet[10];
    int inferiori[10];
    int superiori[10];
    int toWriteInf = 0;
    int toWriteSup = 0;
    int sommaInf = 0;
    int sommaSup = 0;

    // riempimento vettore
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        vet[i] = (rand() % 100) + 1;
    }

    // visualizzazione originale
    cout << "VETTORE: ";
    for (int i = 0; i < 10; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;

    // inizializzazione celle vuote
    for (int i = 0; i < 10; i++)
    {
        superiori[i] = 0;
        inferiori[i] = 0;
    }

    // smistamento
    for (int i = 0; i < 10; i++)
    {
        if (vet[i] < 50)
        {
            inferiori[toWriteInf] = vet[i];
            toWriteInf++;
        }
        else
        {
            superiori[toWriteSup] = vet[i];
            toWriteSup++;
        }
    }

    // visualizzazione vettori
    cout << "VETTORE INF: ";
    for (int i = 0; i < 10; i++)
    {
        if(inferiori[i] == 0){
            break;
        }
        cout << inferiori[i] << " ";
    }
    cout << endl;

    cout << "VETTORE SUP: ";
    for (int i = 0; i < 10; i++)
    {
        if(superiori[i] == 0){
            break;
        }
        cout << superiori[i] << " ";
    }
    cout << endl;


    // somme vettori
    for (int i = 0; i < 10; i++)
    {
        sommaInf = sommaInf + inferiori[i];
        sommaSup = sommaSup + superiori[i];
    }

    cout << "La somma del vettore INF è " << sommaInf << endl;
    cout << "La somma del vettore SUP è " << sommaSup << endl;
    cout << "Quella maggiore è quella ";

    if (sommaSup > sommaInf)
    {
        cout << "SUP" << endl;
    }
    else if (sommaSup < sommaInf)
    {
        cout << "INF" << endl;
    }
    else
    {
        cout << "NESSUNO" << endl;
    }

    return 0;
}
