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

ESERCIZIO n.6 - Dato il prezzo di un prodotto e la percentuale di sconto, 
calcolare il prezzo scontato.
04/03/2022 (Esercizio a casa)
*/

// #include <math.h>
#include <stdio.h>

int main(void){
    int prezzopieno, percentuale = 0;
    double prezzoscontato, sconto;
    // input
    printf("Inserisci il prezzo pieno: ");
    scanf("%d", &prezzopieno);
    do{
        printf("Inserisci la percentuale di sconto: ");
        scanf("%d", &percentuale);
    }while (percentuale < 1 && percentuale > 99);
    
    // calcolo 
    sconto = ((float)percentuale / 100) * prezzopieno;
    prezzoscontato = prezzopieno - sconto;

    // output
    printf("Sconto: %f \n", sconto);
    printf("Prezzo scontato: %f \n", prezzoscontato);
    return 0;
}