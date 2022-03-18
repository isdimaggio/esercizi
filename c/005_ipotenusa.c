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

ESERCIZIO n.5 - Calcolare la misura dell’ipotenusa di un triangolo 
rettangolo, noti i cateti.
04/03/2022 (Esercizio a casa)
*/

#include <math.h>
#include <stdio.h>

int main(void){
    int a, b;
    double c;
    // input
    printf("Inserisci il primo cateto: ");
    scanf("%d", &a);
    printf("Inserisci il secondo cateto: ");
    scanf("%d", &b);
    // calcolo (radice quadrata di a^2 + b^2)
    c = sqrt((a*a)+(b*b));
    // output
    printf("Risultato: %f \n", c);
    return 0;
}