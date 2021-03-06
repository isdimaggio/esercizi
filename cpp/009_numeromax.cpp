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

ESERCIZIO n.9 -  L'utente inserisce [n] numeri, trova il massimo di quelli
quando l'utente immette 0.
21/10/2021 (Esercitazione in classe)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
	int n = 1;
    int max = 0;
    int i = 0;
    // programma
    while(n != 0)
    {
        cout << "Inserisci un numero (se == 0 il programma termina): ";						
	    cin >> n;
        if(n == 0)
        {
            break; // se è zero rompi il ciclo
        }   
        i++; // incrementa il counter dei numeri inseriti
        if(n > max)
        {
            max = n; // se hai trovato un nuovo massimo memorizza
        }
    }
    cout << "Dei " << i << " numeri che hai inserito il massimo è: " << max << endl;
}