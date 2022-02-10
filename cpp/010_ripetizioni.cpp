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

ESERCIZIO n.10 -  Stampa n volte una stringa di testo, le ripetizioni
le decide l'utente in input.
28/10/2021 (Esercitazione in classe)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    int n = 0;
    // programma
    cout << "Inserisci un numero (se == 0 il programma termina): ";
    cin >> n;
    if(n == 0){
        return 0;
    }
    for(int i = 1; i <= n; i++){
        //stampa
	    cout << "Buongiornissimo" << endl;
    }
    return 0;
}
