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

ESERCIZIO n.24 -  Visualizzare un menù che consenta all'utente di 
scegliere un poligono e calcolarne l'area.
21/02/2022 (Esercitazione in laboratorio)
*/

#include <iostream>
#include <math.h>

using namespace std;

void esercizio1();
void esercizio2();
void esercizio3();

int main()
{
    // dichiarazione delle variabili
    char comando;
    bool ciclo = true;
    // stampa delle tracce
    cout << "Scegli:" << endl;
    while(ciclo)
    {

        cout << "1. Area del triangolo" << endl;
        cout << "2. Area del rettangolo" << endl;
        cout << "3. Area del quadrato" << endl;
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
    cout << endl << "----------------------" << endl;
    cout << "Area del triangolo" << endl;
    // dichiarazione variabili
    int b, h;
    // programma
    cout << "Inserisci la base: ";
    cin >> b;
    cout << "Inserisci l'altezza: ";
    cin >> h;
    cout << "L'area è: " << (b*h)/2 << endl;
    cout << "----------------------" << endl << endl;
}

void esercizio2()
{
    // Esercizio 2
    cout << endl << "----------------------" << endl;
    cout << "Area del rettangolo" << endl;
    // dichiarazione variabili
    int b, h;
    // programma
    cout << "Inserisci la base: ";
    cin >> b;
    cout << "Inserisci l'altezza: ";
    cin >> h;
    cout << "L'area è: " << b*h << endl;
    cout << "----------------------" << endl << endl;
}

void esercizio3()
{
    // Esercizio 3
    cout << endl << "----------------------" << endl;
    cout << "Area del quadrato" << endl;
    // dichiarazione variabili
    int l;
    // programma
    cout << "Inserisci il lato: ";
    cin >> l;
    cout << "L'area è: " << l*l << endl;
    cout << "----------------------" << endl << endl;
}