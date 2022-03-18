/*
Copyright 2021 Lo Mele Vittorio / Loris Lurdo

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

ESERCIZIO n.16 - Letti due interi n/k>0 stampa il risultato della
sommatoria k + k^2 + k^n...
15/03/2022 (Esercitazione in laboratorio)
*/

#include <stdio.h>

int main(void)
{
    int n = 0, k = 0, mult = 1, pot;

    do
    {
        printf("Inserisci n: ");
        scanf("%d", &n);
    } while (n <= 0);

    do
    {
        printf("Inserisci k: ");
        scanf("%d", &k);
    } while (k <= 0);

    pot = 0;
    for (int i = 1; i < (n + 1); i++)
    {
        mult = mult * k;
        pot = pot + mult;
    }
    printf("Il risultato è %d \n", pot);
}