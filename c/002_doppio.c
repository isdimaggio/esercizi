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

ESERCIZIO n.2 - Dato un numero da tastiera, calcolare il doppio.
12/02/2022 (Aula P2-05)
*/

#include <stdio.h>

int main(void){
    int num;
    printf("Inserisci un numero: ");
    scanf("%d", &num);
    printf("Il doppio del numero inserito: %d\n", num * 2);
    return 0;
}