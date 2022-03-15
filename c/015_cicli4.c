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

ESERCIZIO n.15 - Stampa N multipli di K
15/03/2022 (Esercitazione in laboratorio)
*/

#include <stdio.h>

int main(void)
{
    int n = 0, k = 0, mult;

    do
    {
        printf("Inserisci il numero di multipli da visualizzare: ");
        scanf("%d", &n);
    } while (n <= 0);

    do
    {
        printf("Inserisci il numero: ");
        scanf("%d", &k);
    } while (k <= 0);

    printf("I primi %d multipli di %d sono: \n", n, k);

    for (int i = 0; i < n; i++)
    {
        mult = i * k;
        printf("%d \n", mult);
    }
}