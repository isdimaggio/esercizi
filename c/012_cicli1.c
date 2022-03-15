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

ESERCIZIO n.12 - Stampa tabellina del 2.
15/03/2022 (Esercitazione in laboratorio)
*/

#include <stdio.h>

int main(void)
{
    int i, ris;
    printf("Tabellina del 2: \n");
    for (i = 0; i < 11; i++)
    {
        ris = 2 * i;
        printf("2*%d", i);
        printf("=%d ", ris);
        printf("  \n");
    }
}