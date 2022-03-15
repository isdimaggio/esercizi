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

ESERCIZIO n.22 - Svolgere l’esercizio 17 utilizzando il ciclo WHILE.
15/03/2022 (Esercitazione in laboratorio)
*/

#include <stdio.h>

int main()
{
    int i = 0, ris = 0, n;

    while (i < 5)
    {
        printf("Inserisci il numero: ");
        scanf("%d", &n);
        ris = ris + n;
        i++;
    }

    printf("Il risultato è %d", ris);
    return 0;
}