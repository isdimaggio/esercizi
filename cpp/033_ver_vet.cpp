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

Creare un programma in C++ che permetta di risolvere il seguente problema.
Dato un vettore di 20 elementi:
1) attraverso l'inserimento da tastiera, caricare manualmente le prime 10
celle del vettore con valori interi <= 100

2) utilizzando la funzione "random", caricare le ultime 10 celle del vettore
con valori interi <= 100

3) visualizzare in output l'interno vettore

4) inserire da tastiera un numero intero NUM e, successivamente, ricercare
tale numero nel vettore. Se il numero esiste, stampare la/e posizione/i
e le volte in cui è stato trovato.

21/03/2022 (Verifica di laboratorio)
*/

#include <iostream>
#include <time.h>

using namespace std;

int vet[20] = {0};
void punto1();
void punto2();
void punto3();
void punto4();

int main()
{

    int scelta = 0;

    srand(time(NULL));

    while (scelta < 5)
    {
        cout << "1. Caricamento manuale prime 10" << endl;
        cout << "2. Caricamento random ultime 10" << endl;
        cout << "3. Stampa vettore" << endl;
        cout << "4. Ricerca elementi" << endl;
        cout << "5. Esci dal programmma" << endl;
        cout << "> ";
        cin >> scelta;

        switch (scelta)
        {
        case 1:
            punto1();
            break;
        case 2:
            punto2();
            break;
        case 3:
            punto3();
            break;
        case 4:
            punto4();
            break;
        default:
            break;
        }
    }
}

void punto1()
{
    // inserimento prime 10 cifre
    for (int i = 0; i < 10; i++)
    {
        int tmp;
        do
        {
            cout << "Popola la posizione [" << i << "] del vettore: ";
            cin >> tmp;
        } while (tmp > 100);
        vet[i] = tmp;
    }
    cout << "Pos [0 -> 9] popolate con valori inseriti da tastiera." << endl;
}

void punto2()
{
    // inserimento ultime 10 random
    for (int i = 10; i < 20; i++)
    {
        vet[i] = (rand() % 100) + 1;
    }
    cout << "Pos [10 -> 19] popolate con valori random." << endl;
}

void punto3()
{
    // stampa del vettore
    cout << "Vettore: ";
    for (int i = 0; i < 20; i++)
    {
        cout << "[" << vet[i] << "]";
    }
    cout << endl;
}

void punto4()
{
    // ricerca
    int tot = 0; // quante volte n è stato trovato in vet
    int search;  // numero da cercare
    cout << "Inserisci il numero da cercare: ";
    cin >> search;
    for (int i = 0; i < 20; i++)
    {
        if (vet[i] == search)
        {
            cout << "Trovato '" << search << "' alla posizione " << i << endl;
            tot++;
        }
    }
    cout << "Il numero " << search << " è stato trovato " << tot << " volte." << endl;
}