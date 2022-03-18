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

ESERCIZIO n.27 - Dopo aver caricato in memoria un array di numeri interi 
con 20 componenti, contare le componenti che hanno valore superiore a 5.
21/02/2022 (Esercitazione in laboratorio)
*/

#include <iostream>

using namespace std;

int main()
{
    int vet[20];
    int count = 0;
    // caricamento vettore
    for (int i = 0; i < 20; i++)
    {
        cout << "Inserisci intero nella cella " << i << ": ";
        cin >> vet[i];
    }
    // conteggio
    for (int i = 0; i < 20; i++)
    {
        if(vet[i] > 5){
            count++;
        }
    }
    cout << "I valori caricati superiori a 5 sono " << count << endl;
    return 0;
}
