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

ESERCIZIO n.1 - Varie operazioni aritmetiche codificate in C++
02/10/2021 (Lab. Inf.)
*/

#include <iostream>

using namespace std;

int num1, num2, opt;

int main(){
	cout << "Inserisci il primo numero: ";
	cin >> num1;
	cout << "Inserisci il secondo numero: ";
	cin >> num2;
	cout << "Scegli 1 per SOMMA, 2 per SOTTRAZIONE, 3 per DIVISIONE, 4 per PRODOTTO: ";
	cin >> opt;
	switch(opt){
		case 1:
			//somma
			cout << "La somma è " << num1 + num2 << endl;
			break;
		case 2:
			//sottrazione
			cout << "La sottrazione è " << num1 - num2 << endl;
			break;
		case 3:
			//divisione
			cout << "La divisione è " << num1 / num2 << endl;
			break;
		case 4:
			//prodotto
			cout << "Il prodotto è " << num1 * num2 << endl;
			break;
		default:
			cout << "L'opzione selezionata non esiste.";
			break;
	}
	return 0;

}

