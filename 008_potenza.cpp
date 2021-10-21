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

ESERCIZIO n.8 -  Elevazione a potenza di un numero
21/10/2021 (Esercitazione in classe)
*/

#include <iostream>

using namespace std;

int main()
{
	// dichiarazione variabili
	int base, esponente, risultato;
	// programma
	cout << "Inserisci la base: ";						
	cin >> base;			
    risultato = base;												
	cout << "Inserisci l'esponente: ";
	cin >> esponente;
    if(esponente < 2 | base < 2)
    {
        cout << "Inserisci dati validi." << endl; // troppo pigri per controllare casi speciali
        return 0;
    }
    for(int i = 1; i < esponente; i++)
    {
        risultato = risultato * base;
    }
    cout << "Il risultato è: " << risultato << endl;
    return 0;
}