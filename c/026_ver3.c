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

ESERCIZIO n.26 - Portafoglio
22/03/2022 (Verifica di laboratorio)
*/

#define UNOC 0.01
#define CINQUEC 0.05
#define DIECIC 0.10
#define CINQUANTAC 0.50
#define UNOE 1.00
#define DUEE 2.00

#include <stdio.h>
#include <stdbool.h>

float count = 0;

bool preleva(float valore)
{
    if (valore > count)
    {
        return false; // non puoi andare in negativo
    }
    else
    {
        count -= valore; // sottrai la somma richiesta
        return true;
    }
}

void stampaTracce(void)
{
    // stampa delle tracce
    printf("---------------------------------------------\n");
    printf("1. Inserisci moneta da 1 cent\n");
    printf("2. Inserisci moneta da 5 cent\n");
    printf("3. Inserisci moneta da 10 cent\n");
    printf("4. Inserisci moneta da 50 cent\n");
    printf("5. Inserisci moneta da 1 euro\n");
    printf("6. Inserisci moneta da 2 euro\n");
    printf("7. Stampa somma totale del portafoglio\n");
    printf("8. Preleva dal portafoglio\n");
    printf("9. Azzera il portafoglio\n");
    printf("0. Esci dal programma\n");
}

void main(void)
{

    int comando; // comando menu
    float somma; // somma da prelevare

    while (true)
    {
        stampaTracce(); // stampa le tracce
        printf("> ");

        scanf("%d", &comando);
        switch (comando)
        {

        case 1:
            count += UNOC;
            printf("Aggiunta moneta da 1 CENTESIMO \n");
            break;

        case 2:
            count += CINQUEC;
            printf("Aggiunta moneta da 5 CENTESIMI \n");
            break;

        case 3:
            count += DIECIC;
            printf("Aggiunta moneta da 10 CENTESIMI \n");
            break;

        case 4:
            count += CINQUANTAC;
            printf("Aggiunta moneta da 50 CENTESIMI \n");
            break;

        case 5:
            count += UNOE;
            printf("Aggiunta moneta da 1 EURO \n");
            break;

        case 6:
            count += DUEE;
            printf("Aggiunta moneta da 2 EURO \n");
            break;

        case 7:
            // se l'utente non ha soldi, insultalo
            if (count > 0)
            {
                // se ha soldi stampa la somma
                printf("Il portafoglio al momento contiene %f euro.\n", count);
            }
            else
            {
                printf("Sei povero... vai a lavorare! (0 euro)\n");
            }
            break;

        case 8:
            // preleva dal portafoglio
            printf("Inserisci somma da prelevare: ");
            scanf("%f", &somma);
            if (preleva(somma))
            {
                printf("Prelevati con successo %f EURO dal portafoglio.\n", somma);
            }
            else
            {
                printf("Non hai abbastanza soldi, ergo, vai a lavorare...\n");
            }
            break;

        case 9:
            // azzeramento portafoglio
            count = 0;
            printf("[!] Nuovo achievement sbloccato: povertà!\n");
            break;

        // esci dal programma
        case 0:
            return;
            break;

        // comando sconosciuto
        default:
            printf("Comando sconosciuto \n");
            break;
        }
    }
}