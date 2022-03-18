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

ESERCIZIO n.14 (Verifica, es.2)
Data l'altezza e il peso di uno studente, calcolare l'IMC ( = Peso/(Altezza*Altezza) ).
   Visualizzare successivamente a video i seguenti esiti:

	1. 	IMC<20 		 --> SOTTOPESO
	2. 	IMC <= 25    --> NORMOPESO
	3.  IMC <= 35    --> SOVRAPPESO
	4. 	IMC >35 	 --> OBESO

15/11/2021 (Verifica in laboratorio)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    float peso, altezza, imc;
    // programma
    cout << "Inserisci il tuo peso in chilogrammi: ";
    cin >> peso;
    cout << "Inserisci la tua altezza in metri: ";
    cin >> altezza;
    // calcolo IMC
    imc = peso / (altezza * altezza);
    // determinazione output
    if(imc < 20)
    {
        cout << "Sei sottopeso" << endl;
    }
    else
    {
        if(imc <= 25)
        {
            cout << "Sei normopeso" << endl;
        }
        else
        {
            if(imc <= 35)
            {
                cout << "Sei sovrappeso" << endl;
            }
            else
            {
                cout << "Sei obeso" << endl;
            }
        }
    }
    return 0;
}
