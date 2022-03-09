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

void traccia1();
void traccia2();
void traccia3();

int main(void){
    for(;;)
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
            return 0;  //rompe ciclo ed esce dal programma
        }
    }
}

void traccia1(){
    printf("------- b10->b2 little endian -------\n");

    // inserimento del numero base 10
    int b10;
    do
    {
        printf("Inserisci numero in base 10: \n");
        scanf("%d", &b10);
    } while (b10 < 1); // controlla non sia zero

    int ris = b10;

    // divisioni successive
    while(ris > 2){
        sas = ris % 2;
        ris = ris / 2;
    }
    
    printf("-------------------------------------\n");
    return;
}

void traccia2(){
    printf("------- b10->b2 big endian -------\n");

    // inserimento del numero base 10
    int b10;
    do
    {
        printf("Inserisci numero in base 10: \n");
        scanf("%d", &b10);
    } while (b10 < 1); // controlla non sia zero
    
    printf("----------------------------------\n");
    return; 
}

void traccia3(){
    printf("------- b2->b10 -------\n");

    // inserimento del numero base 2
    /*
    char b2;
    do
    {
        printf("Inserisci numero in base 2: \n");
        scanf("%d", &b2);
    } while (b2 != ""); // controlla non sia zero
    */

    printf("-----------------------\n");
    return; 
}