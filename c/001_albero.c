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

ESERCIZIO n.1 - Stampa dell'ascii art di un albero di natale
10/02/2022 (Lab. Inf.)
*/

#include <stdio.h>
#include <stdbool.h>

void main(){
    /* Titolo programma */
    printf("Generatore di alberi di natale - Vittorio Lo Mele, 3Ci.\n");

    /* Variabili globali, configurazione del generatore */
    int maxTreeWidth; // larghezza massima in colonne dell'albero
    float decorationRandomnessLevel; // quante decorazioni devono essere inserite randomicamente
    float snowRandomnessLevel; // intensità della neve
    bool drawGifts; // disegnare i regali sotto l'albero o meno

    /* Input delle impostazioni del generatore */
    do{
        printf("Inserisci larghezza massima dell'albero (10 < x < 80): ");
        scanf("%d", &maxTreeWidth);
    } while (maxTreeWidth < 10 || maxTreeWidth > 80);

    do{
        printf("Inserisci la randomizzazione delle decorazioni (0.1 < x < 1.0): ");
        scanf("%f", &decorationRandomnessLevel);
    } while (decorationRandomnessLevel < 0.1 || decorationRandomnessLevel > 1.0);

    do{
        printf("Inserisci l'intensità della neve (0.1 < x < 1.0): ");
        scanf("%f", &snowRandomnessLevel);
    } while (snowRandomnessLevel < 0.1 || snowRandomnessLevel > 1.0);

    char tmpGift;
    do{
        printf("Disegnare i regali? (N | s): ");
        scanf(" %c", &tmpGift);
    } while (tmpGift == '\0');
    switch (tmpGift)
    {
    case 'S':
        drawGifts = true;
        break;
    case 's':
        drawGifts = true;
        break;
    case 'N':
        drawGifts = false;
        break;
    case 'n':
        drawGifts = false;
        break;
    default:
        drawGifts = false;
        break;
    }
    
    /* Inizio codice di generazione */
    // programma da finire
    
    return;
}