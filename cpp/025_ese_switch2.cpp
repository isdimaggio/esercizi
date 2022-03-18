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

ESERCIZIO n.25 -  Calcolatrice basic con switch.
21/02/2022 (Esercitazione in laboratorio)
*/

#include <iostream>
#include <math.h>

using namespace std;

void esercizio1();
void esercizio2();
void esercizio3();
void esercizio4();

int main()
{
    // dichiarazione delle variabili
    char comando;
    bool ciclo = true;
    // stampa delle tracce
    cout << "Scegli:" << endl;
    while(ciclo)
    {

        cout << "1. Somma" << endl;
        cout << "2. Sottrazione" << endl;
        cout << "3. Divisione" << endl;
        cout << "4. Prodotto" << endl;
        cout << "F. Esci dal programma" << endl;
        cout << "> ";
        cin >> comando;

        switch(comando)
        {
            case '1':
            esercizio1();
            break;

            case '2':
            esercizio2();
            break;

            case '3':
            esercizio3();
            break;

            case '4':
            esercizio4();
            break;

            case 'F':
            return 0;
            break;

            default:
            ciclo = false;
            break;

        }
    }
}

void esercizio1()
{
    // Esercizio 1
    cout << endl << "----------- Somma -----------" << endl;
    // dichiarazione variabili
    int a, b;
    // programma
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    cout << "La somma è: " << a+b << endl;
    cout << "----------------------" << endl << endl;
}

void esercizio2()
{
    // Esercizio 2
    cout << endl << "----------- Sottrazione -----------" << endl;
    // dichiarazione variabili
    int a, b;
    // programma
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    cout << "La sottrazione è: " << a-b << endl;
    cout << "----------------------" << endl << endl;
}

void esercizio3()
{
    // Esercizio 3
    cout << endl << "----------- Moltiplicazione -----------" << endl;
    // dichiarazione variabili
    int a, b;
    // programma
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    cout << "La moltiplicazione è: " << a*b << endl;
    cout << "----------------------" << endl << endl;
}

void esercizio4()
{
    // Esercizio 4
    cout << endl << "----------- Divisione -----------" << endl;
    // dichiarazione variabili
    int a, b;
    // programma
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    cout << "La divisione è: " << a/b << endl;
    cout << "----------------------" << endl << endl;
}