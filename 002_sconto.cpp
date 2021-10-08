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

ESERCIZIO n.2 - Calcolare lo sconto sull'importo dato in base a dei livelli.
07/10/2021 (P2-05)
*/

#include <iostream>

using namespace std;

int main()
{
	// inizializzazione variabili
	float importo, importo_scontato;
	float sconto = 0;
	// esecuzione del programma
	cout << "Inserisci l'importo: ";
	cin >> importo;
	if(importo >= 1000)
	{
		if(importo >= 2000)
		{
			sconto = (importo * 40)/100;
		}else
		{
			sconto = (importo * 20)/100;
		}
	}
	importo_scontato = importo - sconto;
	// output
	cout << "Lo sconto è: " << sconto << " €" << endl;
	cout << "L'importo scontato è: " << importo_scontato << " €" << endl;
	return 0;
}
