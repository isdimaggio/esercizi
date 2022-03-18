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

ESERCIZIO n.10 - Visualizzare un menù che consenta all'utente di 
scegliere un poligono e calcolarne l'area.
14/03/2022 (Esercitazione in laboratorio)
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void esercizio1();
void esercizio2();
void esercizio3();

int main()
{
    // dichiarazione delle variabili
    char comando;
    bool ciclo = true;
    // stampa delle tracce
    printf("Scegli:\n");
    while(ciclo)
    {
        printf("1. Area del triangolo\n");
        printf("2. Area del rettangolo\n");
        printf("3. Area del quadrato\n");
        printf("F. Esci dal programma\n");
        printf("> ");
        scanf("%c", &comando);
        switch(comando)
        {
            case '1':
            esercizio1();
            break;

            case '2':
            esercizio2();
            break;

            case '3':
            esercizio3();
            break;

            case 'F':
            return 0;
            break;

            default:
            ciclo = false;
            break;

        }
    }
}

void esercizio1()
{
    // Esercizio 1
    printf("\n");
    // dichiarazione variabili
    int b, h;
    // programma
    printf("Inserisci la base: ");
    scanf("%d", &b);
    printf("Inserisci l'altezza: ");
    scanf("%d", &h);
    printf("L'area è: %d", (b*h)/2);
    printf("\n\n");
}

void esercizio2()
{
    // Esercizio 2
    printf("\n");
    // dichiarazione variabili
    int b, h;
    // programma
    printf("Inserisci la base: ");
    scanf("%d", &b);
    printf("Inserisci l'altezza: ");
    scanf("%d", &h);
    printf("L'area è: %d", b*h);
    printf("\n\n");
}

void esercizio3()
{
    // Esercizio 3
    printf("\n");
    // dichiarazione variabili
    int l;
    // programma
    printf("Inserisci lato: ");
    scanf("%d", &l);
    printf("L'area è: %d", l*l);
    printf("\n\n");
}