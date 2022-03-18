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

ESERCIZIO n.24 - Programma che legge una serie di numeri da tastiera,
e quando viene inserito lo 0 indica il maggiore e il minore tra i
numeri inseriti.
22/03/2022 (Verifica di laboratorio)
*/

#include <stdio.h>
#include <stdbool.h>

void main(void)
{
    int inserito, min = 0, max = 0, count = 0;
    bool primo = true; // setta la flag primo numero inserito
    while (true)       // loop
    {
        printf("Inserisci un numero: ");
        scanf("%d", &inserito);
        // per evitare conteggi di eventuali zeri inseriti
        // opto per un ciclo precondizionale con "break"
        if (inserito == 0)
        {
            printf(" Trovato 0, terminando! \n");
            break;
        }
        if (primo)
        {
            // se è il primo numero settalo come minimo e massimo conosciuti
            min = inserito;
            max = inserito;
            // aumenta il counter dei numeri inseriti
            count++;
            // togli la flag del primo numero
            primo = false;
        }
        else
        {
            // se il numero inserito è minore del minimo conosciuto aggiornalo
            if (inserito < min)
            {
                min = inserito;
            }
            // stesso discorso per il massimo
            if (inserito > max)
            {
                max = inserito;
            }
            count++;
        }
    }

    // outputs
    printf("Hai inserito %d numeri, il maggiore è %d ed il minore è %d \n", count, max, min);
    return;
}