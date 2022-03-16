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

ESERCIZIO n.8 - Conversioni tra base 2 e 10.
1) Convertire un numero da base 10 a base 2 little endian
2) Convertire un numero da base 10 a base 2 big endian
3) Convertire un numero binario nel corrispondente numero decimale.
08/03/2022 (Lab. T.P.S.I.T.)
*/

#include <stdio.h>
#include <math.h>

void traccia1();
void traccia2();
void traccia3();

int main(void)
{
    for (;;)
    {
        // Scelta traccia
        int traccia;
        printf("1) b10->b2 little endian\n");
        printf("2) b10->b2 big endian\n");
        printf("3) b2->b10\n");
        printf("0) Esci dal programma\n");
        printf("> ");
        scanf(" %d", &traccia);
        switch (traccia)
        {
        case 1:
            traccia1();
            break;
        case 2:
            traccia2();
            break;
        case 3:
            traccia3();
            break;
        default:
            return 0; // rompe ciclo ed esce dal programma
        }
    }
}

void traccia1()
{
    printf("\n------- b10->b2 little endian -------\n");

    // inserimento del numero base 10
    int b10;
    do
    {
        printf("Inserisci numero in base 10: ");
        scanf("%d", &b10);
    } while (b10 < 1); // controlla non sia zero

    // determinazione dimensioni vettore
    float tdim = log2f((float)b10);
    int dim = (int)tdim + 1;

    printf("Dimensione vettore: %d\n\n", dim);

    int ris = b10, vet[dim], i = 0;

    // divisioni successive
    while (ris > 0)
    {
        printf("%d / 2 = ", ris);
        int mod = (ris % 2);
        ris = ris / 2;
        printf("%d R %d \n", ris, mod);
        vet[i] = mod;
        i++;
    }

    printf("\nRISULTATO: ");

    // stampa vettore
    for (int j = 0; j < dim; j++)
    {
        printf("%d ", vet[j]);
    }

    printf("\n-------------------------------------\n\n");
    return;
}

void traccia2()
{
    printf("\n------- b10->b2 big endian -------\n");

    // inserimento del numero base 10
    int b10;
    do
    {
        printf("Inserisci numero in base 10: ");
        scanf("%d", &b10);
    } while (b10 < 1); // controlla non sia zero

    // determinazione dimensioni vettore
    float tdim = log2f((float)b10);
    int dim = (int)tdim + 1;

    printf("Dimensione vettore: %d\n\n", dim);

    int ris = b10, vet[dim], i = 0;

    // divisioni successive
    while (ris > 0)
    {
        printf("%d / 2 = ", ris);
        int mod = (ris % 2);
        ris = ris / 2;
        printf("%d R %d \n", ris, mod);
        vet[dim - i - 1] = mod;
        i++;
    }

    printf("\nRISULTATO: ");

    // stampa vettore
    for (int j = 0; j < dim; j++)
    {
        printf("%d ", vet[j]);
    }

    printf("\n----------------------------------\n\n");
    return;
}

void traccia3()
{
    printf("------- b2->b10 -------\n");

    // inserimento del numero base 2
    printf("Inserisci numero binario (max 16 bit): ");
    char str[17] = {0};
    int vet[17] = {-1};
    int j = 0, som = 0;
    scanf("%16s", str);

    for (int i = 16; i > -1; i--)
    {
        if (str[i] != 0)
        {
            vet[j] = (int)str[i] - 48; // ascii -> int
            j++;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        som += vet[i] *  pow(2, i);
    }

    printf("Il numero convertito è: %d \n", som);    
    printf("-----------------------\n");
    return;
}