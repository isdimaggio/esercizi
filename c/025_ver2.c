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

ESERCIZIO n.25 - Scrivere un programma che legga da terminale una
sequenza di interi positivi e negativi terminati dal valore 0
(un intero su ogni linea) e stampi la media degli interi positivi.
22/03/2022 (Verifica di laboratorio)
*/

#include <stdio.h>
#include <stdbool.h>

void main(void)
{
    int inserito, sum = 0, count = 0, count_tot = 0;
    while (true) // loop
    {
        printf("Inserisci un numero: ");
        scanf("%d", &inserito);

        if (inserito > 0)
        {
            // numero positivo
            sum += inserito;    // somma il numero inserito a quelli già inseriti
            count++;            // incrementa...
            count_tot++;        // ... i due counter

        }
        else if (inserito < 0)
        {
            // numero negativo
            count_tot++;        // incrementa solo il counter di quelli totali
        }
        else
        {
            // trovato uno zero
            // per evitare conteggi di eventuali zeri inseriti
            // opto per un ciclo precondizionale con "break"
            printf(" Trovato 0, terminando! \n");
            break;
        }
    }

    float media = sum / count; // calcolo della media

    // outputs
    printf(
        "Hai inserito %d numeri, di quali %d positivi, la loro media è %f \n",
        count_tot,  // inserimenti totali
        count,      // inserimenti positivi
        media       // media
    );
    return;
}