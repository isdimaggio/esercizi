/*
Copyright 2021 Lo Mele Vittorio  / Loris Lurdo

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

Realizzare un programma in C++ che permetta di visualizzare il seguente menù utilizzando i vettori:
1)  Caricamento del vettore (utilizzando la funzione random)
2)  Ordinamento del vettore
3)  Stampa del vettore
4)  Ricerca di un elemento del vettore
5)  Somma degli elementi del vettore
6)  Esci
16/03/2022 (Esercitazione in classe)
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{

    int vet[10], temp, scelta, num, som = 0;
    bool conta = false;

    srand(time(NULL));

    while (scelta != 6)
    {
        cout << "1. Caricamento vettore" << endl;
        cout << "2. Ordinamento vettore" << endl;
        cout << "3. Stampa vettore" << endl;
        cout << "4. Ricerca elemento nel vettore" << endl;
        cout << "5. Somma degli elementi nel vettore" << endl;
        cout << "6. Esci" << endl;
        cout << "> ";
        cin >> scelta;

        switch (scelta)
        {
        case 1:
            // POPOLAMENTO VETTORE
            for (int i = 0; i < 10; i++)
            {
                vet[i] = rand() % 101;
            }
            cout << "Vettore generato!" << endl;
            break;
        case 2:
            // BUBBLE SORT
            for (int i = 0; i < 10; i++)
            {
                for (int j = i + 1; j < 10; j++)
                {
                    if (vet[i] > vet[j])
                    {
                        temp = vet[i];
                        vet[i] = vet[j];
                        vet[j] = temp;
                    }
                }
            }
            cout << "Vettore riordinato!" << endl;
            break;

        case 3:
            // STAMPA
            cout << "----Vettore----" << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << vet[i] << "  ";
            }
            cout << endl;
            break;

        case 4:
            // CONTROLLO
            cout << "quale numero vuoi controllare? ";
            cin >> num;
            for (int i = 0; i < 10; i++)
            {
                if (vet[i] == num)
                {
                    conta = true;
                }
            }
            if (conta == true)
            {
                cout << "Il numero " << num << " è nel vettore";
            }
            else
            {
                cout << "Il numero " << num << " non è nel vettore";
            }
            cout << endl;
            break;

        case 5:
            // SOMMA
            for (int i = 0; i > 10; i++)
            {
                som = som + vet[i];
            }
            cout << "La somma degli elementi è " << som;
            cout << endl;
            break;
        default:
            break;
        }
    }
}