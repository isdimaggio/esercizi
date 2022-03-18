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

ESERCIZIO n.8 - Risolvere un equazione di secondo grado.
04/03/2022 (Esercizio a casa)
*/

// #include <math.h>
#include <stdio.h>

int main(void)
{
    int a, b, c;
    float x1, x2, delta;
    // input
    printf("EQUAZIONE: ax^2+bx+c=0\n");
    printf("Inserisci il primo coefficente (a): ");
    scanf("%d", &a);
    printf("Inserisci il secondo coefficente (b): ");
    scanf("%d", &b);
    printf("Inserisci il termine noto (c): ");
    scanf("%d", &c);
    printf("DA RISOLVERE: %dx^2+%dx+%d=0\n", a, b, c);
    if (a == 0)
    {
        if ((b == 0) && (c == 0))
            printf("Equazione inderterminata\n");
        else if (b == 0)
            printf("Equazione impossibile\n");
        else
        {
            printf("Equazione di primo grado: ");
            x1 = -c / b;
            printf("x= %f \n", x1);
        }
    }
    else
    {
        delta = b * b - 4 * a * c;
        printf("Delta: %f \n", delta);
        if (delta > 0)
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("Radici reali e distine: x1=%f e x2=%f \n", x1, x2);
        }
        else if (delta == 0)
        {
            x1 = (-b) / (2 * a);
            printf("x=%f \n", x1);
        }
        else
            printf("Equazione impossibile\n");
    }
    return 0;
}