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

ESERCIZIO n.7 -  Risolvere un'equazione di primo grado.
09/10/2021 (Esercizio per casa)
*/

#include <iostream>

using namespace std;

int main()
{
	// dichiarazione variabili
	int a, b;
	// programma
	cout << "EQUAZIONE: x+a-b=0" << endl;								// stampiamo il tipo di equazione che il programma risolve
	cout << "Inserisci il primo coefficente (a): ";						// Chiediamo in input il primo coefficiente
	cin >> a;															
	cout << "Inserisci il secondo coefficente (b): ";					// Chiediamo in input il secondo coefficiente
	cin >> b;
	cout << "DA RISOLVERE: " << "x+" << a << "-" << b << "=0" << endl;	// Stampiamo l'equazione da risolvere
	cout << "RISULTATO: x=" << -a+b << endl;							// Calcoliamo e stampiamo il risultato
    return 0;
}