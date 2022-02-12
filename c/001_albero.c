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

ESERCIZIO n.1 - Albero di natale in ASCII... scalabile!
10/02/2022 (Lab. Inf.)
*/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// colori
#define GRNB "\e[42m\e[30m" // erba
#define YELB "\e[43m\e[30m" // tronco
#define GRNHB "\e[0;102m\e[32m" // foglie
#define GRNHBDR "\e[0;102m\e[91m" // foglie con decorazione rossa
#define GRNHBDB "\e[0;102m\e[94m" // foglie con decorazione blu
#define YELHB "\e[0;107m\e[33m" // stella
#define WHTHB "\e[0;107m\e[90m" // aria-neve
#define WHTHR "\e[0;107m\e[91m" // messaggio
#define CRESET "\e[0m" // reset

// SE SIAMO SU MACCHINA WINDOWS È NECESSARIO FARE
// TUTTO QUESTO

// SOURCE: https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

static HANDLE stdoutHandle;
static DWORD outModeInit;

void setupConsole(void) {
	DWORD outMode = 0;
	stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if(stdoutHandle == INVALID_HANDLE_VALUE) {
		exit(GetLastError());
	}
	
	if(!GetConsoleMode(stdoutHandle, &outMode)) {
		exit(GetLastError());
	}

	outModeInit = outMode;
	
    // Enable ANSI escape codes
	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	if(!SetConsoleMode(stdoutHandle, outMode)) {
		exit(GetLastError());
	}	
}

void restoreConsole(void) {
    // Reset colors
    printf("\x1b[0m");	
	
    // Reset console mode
	if(!SetConsoleMode(stdoutHandle, outModeInit)) {
		exit(GetLastError());
	}
}
#else
void setupConsole(void) {}

void restoreConsole(void) {
    // Reset colors
    printf("\x1b[0m");
}
#endif

#define CANVAS_PADDING 15
#define POST_STAR_PADDING 3

void renderPixel(int pixelCode, bool enableSnow, bool enableDecoration);

int main(void)
{
    /* Variabili globali, configurazione del generatore */
    int treeWidth;          // larghezza dell'albero
    int grassHeight;        // altezza dell'erba
    bool enableDecoration;  // se attivare le decorazioni
    bool enableSnow;        // se attivare la neve

    /* Variabili globali, parametri per il rendering */
    int treeSideLenght;     // lunghezza di un lato dell'albero
    int maxTreeWidth;       // ingombro massimo dell'albero in larghezza
    int maxTreeHeight;      // ingombro massimo dell'albero in altezza
    int logHeight;          // altezza del tronco
    int logSideLenght;      // lunghezza pari di un lato del tronco
    int canvasWidth;        // larghezza del canvas di rendering
    int canvasHeight;       // altezza del canvas di rendering
    int constructionPp = 0; // riga fino alla quale l'ultimo ciclo for ha costruito
    int canvasCenterPoint;  // punto centrale del canvas
    int tempCPP;            // construction point temporaneo

    // messaggio da stampare in header
    char messaggio[] = "BUON NATALE! https://vitto.dev";

    /* Input delle impostazioni del generatore */

    setupConsole();
    srand(time(NULL));

    // larghezza albero
    do
    {
        printf("Inserisci larghezza massima dell'albero (15 < x < 45): ");
        scanf("%d", &treeWidth);
    } while (treeWidth < 15 || treeWidth > 45);

    // altezza erba
    do
    {
        printf("Inserisci l'altezza dell'erba (1 < x < 4): ");
        scanf("%d", &grassHeight);
    } while (grassHeight < 1 || grassHeight > 4);

    // disegnare la neve?
    char tmpSnow;
    do
    {
        printf("Disegnare la neve? (N | s): ");
        scanf(" %c", &tmpSnow);
    } while (tmpSnow == '\0');
    switch (tmpSnow)
    {
    case 'S':
        enableSnow = true;
        break;
    case 's':
        enableSnow = true;
        break;
    case 'N':
        enableSnow = false;
        break;
    case 'n':
        enableSnow = false;
        break;
    default:
        enableSnow = false;
        break;
    }

    // disegnare le decorazioni?
    char tmpDecoration;
    do
    {
        printf("Disegnare le decorazioni? (N | s): ");
        scanf(" %c", &tmpDecoration);
    } while (tmpDecoration == '\0');
    switch (tmpDecoration)
    {
    case 'S':
        enableDecoration = true;
        break;
    case 's':
        enableDecoration = true;
        break;
    case 'N':
        enableDecoration = false;
        break;
    case 'n':
        enableDecoration = false;
        break;
    default:
        enableDecoration = false;
        break;
    }

    /* Calcolo misure del canvas e dei componenti */

    // controllo se la larghezza dell'albero è pari o dispari
    if ((treeWidth % 2) == 0)
    {
        // in caso sia pari, la lunghezza di un lato corrisponde
        // esattamente alla metà dell'albero
        treeSideLenght = treeWidth / 2;
        // di conseguenza per ottenere l'ingombro massimo basta
        // aggiungere il centro (1) al valore della larghezza
        maxTreeWidth = treeWidth + 1;
    }
    else
    {
        // in caso sia dispari, la lunghezza di un lato è la metà
        // dell'albero dopo aver sottratto il centro
        treeSideLenght = (treeWidth - 1) / 2;
        // l'ingombro massimo è pari alla larghezza siccome include
        // anche il centro
        maxTreeWidth = treeWidth;
    }

    // la larghezza del canvas è pari all'ingombro massimo dell'albero
    // al quale viene aggiunto un padding di x colonne per ogni lato
    canvasWidth = maxTreeWidth + (CANVAS_PADDING * 2);

    // il punto centrale è calcolato da un lato solo dell'albero
    // al quale viene aggiunto il padding
    canvasCenterPoint = treeSideLenght + CANVAS_PADDING;

    // l'altezza del corpo dell'albero viene calcolata aggiungendo una colonna
    // al numero dispari per renderlo pari per poi dividerlo per due ed ottenere
    // il numero di cicli che verrano eseguiti in fase di costruzione
    maxTreeHeight = (maxTreeWidth + 1) / 2;

    // l'altezza del tronco è esattamente 1/3 dell'altezza del corpo dell'albero
    // arrotondata a numero intero
    logHeight = maxTreeHeight / 3;

    // la larghezza del tronco è invece 1/6 della largehzza del corpo dell'albero;
    // siccome abbiamo bisogno di un numero pari (un lato) per creare una forma simmetrica
    // il valore sarà 1/12 della largehzza del corpo dell'albero arrotondata a numero intero
    logSideLenght = maxTreeWidth / 12;

    // sommiamo tutte le misure prese alle costanti e calcoliamo l'altezza totale del canvas
    // il tre corrisponde all'altezza della stella
    canvasHeight = grassHeight + logHeight + maxTreeHeight + 3 + POST_STAR_PADDING;

    /* 
     * Costruzione albero (al contrario) nella matrice canvas 
     * 0 = ARIA / NEVE
     * 1 = ERBA
     * 2 = TRONCO
     * 3 = FOGLIA ALBERO
     * 4 = (|)
     * 5 = (+)
     * 6 = (-)
     * 7 = (/)
     * 8 = (\)
     */

    // Matrice contenente l'albero costruito al contrario
    int canvas[canvasHeight][canvasWidth];

    // Impostiamo tutta la matrice a 0 per disegnare lo sfondo
    for (int i = 0; i < canvasHeight; i++)
    {
        for (int j = 0; j < canvasWidth; j++)
        {
            canvas[i][j] = 0;
        }
    }

    // Costruiamo i layer di erba
    for (int i = 0; i < grassHeight; i++)
    {
        // per ogni riga di erba
        for (int j = 0; j < canvasWidth; j++)
        {
            canvas[i][j] = 1; // imposta la colonna
        }
        constructionPp = i;
    }

    // Costruzione del tronco
    // SPIEGATO SOLO QUA: La costruzione riprende dall'ultima riga toccata
    // dal precedente array, e viene calcolato il punto dove costruire, aggiungendo
    // ad essa l'item che l'array stesso andrà a costruire.
    // N.B.: Viene usata una copia del construction point siccome quello originale serve al
    // ciclo for e modificarlo causerebbe un segfault!
    tempCPP = constructionPp;
    for (int i = constructionPp + 1; i <= (constructionPp + logHeight); i++)
    {
        // set punto centrale
        canvas[i][canvasCenterPoint] = 2;
        // costruzione lato sinistro (in decrement)
        for (int j = canvasCenterPoint; j >= (canvasCenterPoint - logSideLenght); j--)
        {
            canvas[i][j] = 2;
        }
        // costruzione lato destro (in increment)
        for (int j = canvasCenterPoint; j <= (canvasCenterPoint + logSideLenght); j++)
        {
            canvas[i][j] = 2;
        }
        // set ultimo construction point
        tempCPP = i;
    }
    constructionPp = tempCPP;

    // Costruzione del corpo dell'albero
    tempCPP = constructionPp;
    int ladder = 0; // variabile utility per costruzione lati triangolo
    for (int i = constructionPp + 1; i <= (constructionPp + maxTreeHeight); i++)
    {
        // set punto centrale
        canvas[i][canvasCenterPoint] = 3;
        // costruzione lato sinistro (in decrement)
        // SPIEGATO SOLO QUA: per costruire il lato del triangolo, ad ogni ciclo padre (riga)
        // viene ridotto di una colonna il lato dell'albero
        for (
            int j = canvasCenterPoint;
            j >= (canvasCenterPoint - (treeSideLenght - ladder));
            j--)
        {
            canvas[i][j] = 3;
        }
        // costruzione lato destro (in increment)
        for (
            int j = canvasCenterPoint;
            j <= (canvasCenterPoint + (treeSideLenght - ladder));
            j++)
        {
            canvas[i][j] = 3;
        }
        // set ultimo construction point
        tempCPP = i;
        // incrementa ladder per il lato del triangolo
        ladder++;
    }
    constructionPp = tempCPP;

    // costruzione stella con caratteri
    //prima riga (ext)
    canvas[constructionPp + 1][canvasCenterPoint] = 4;     // centro
    canvas[constructionPp + 1][canvasCenterPoint + 1] = 8; // destra
    canvas[constructionPp + 1][canvasCenterPoint - 1] = 7; // sinistra
    //seconda riga (int)
    canvas[constructionPp + 2][canvasCenterPoint] = 5;     // centro
    canvas[constructionPp + 2][canvasCenterPoint + 1] = 6; // destra
    canvas[constructionPp + 2][canvasCenterPoint - 1] = 6; // sinistra
    //terza riga (ext)
    canvas[constructionPp + 3][canvasCenterPoint] = 4;     // centro
    canvas[constructionPp + 3][canvasCenterPoint + 1] = 7; // destra
    canvas[constructionPp + 3][canvasCenterPoint - 1] = 8; // sinistra

    /* Stampa informazioni sulla generazione */

    printf("\n----- VARIABILI -----\n");
    printf("treeSideLenght: %d\n", treeSideLenght);
    printf("maxTreeWidth: %d\n", maxTreeWidth);
    printf("maxTreeHeight: %d\n", maxTreeHeight);
    printf("logHeight: %d\n", logHeight);
    printf("logSideLenght: %d\n", logSideLenght);
    printf("canvasWidth: %d\n", canvasWidth);
    printf("canvasHeight: %d\n", canvasHeight);

    printf("\n----- MATRIX -----\n");
    // marker del centro
    printf("    "); // quattro spazi per la numeraz. righe
    // stampa spazio bianco
    for (int i = 0; i < (treeSideLenght + CANVAS_PADDING); i++)
    {
        printf(" ");
    }
    printf("C\n"); // inserisci marker centro

    // stampa matrix
    for (int i = 0; i < canvasHeight; i++)
    {
        if (i < 10)
        {
            printf("%d.  ", i); // stampa index riga
        }
        else
        {
            printf("%d. ", i); // stampa index riga
        }
        for (int j = 0; j < canvasWidth; j++)
        {
            printf("%d", canvas[i][j]); // stampa cella
        }
        printf("\n"); // fine riga, vai a capo
    }

    /* Rendering finale albero */

    printf("\n\n----- RENDER FINALE -----\n\n");
    // stampa della matrix al contrario, in decrement
    for (int i = canvasHeight - 1; i >= 0; i--)
    {
        for (int j = 0; j < canvasWidth; j++)
        {
            // soltanto nella prima riga, se il contatore di colonna j
            // ha un valore che è presente nel messaggio, stampa il
            // messaggio al posto del pixel
            if(i == (canvasHeight-1) && j < (int) sizeof(messaggio)){
                printf(WHTHR "%c", messaggio[j]); // stampa caratteri messaggio
            }else{
                renderPixel(canvas[i][j], enableSnow, enableDecoration);
            }
        }
        // se sei nella prima riga (quindi con messaggio)
        // renderizza un pixel extra per compensare quello tolto dal messaggio
        if(i == (canvasHeight-1)){
            renderPixel(0, enableSnow, enableDecoration); // pixel aria/neve
        }
        printf("\n"); // fine riga, vai a capo
    }

    restoreConsole();
    return 0;
}

void renderPixel(int pixelCode, bool enableSnow, bool enableDecoration)
{
    switch (pixelCode)
    {
    case 1:
        // ERBA
        printf(GRNB "\"" CRESET);
        break;
    case 2:
        // TRONCO
        printf(YELB "\"" CRESET);
        break;
    case 3:
        // FOGLIA ALBERO
        // c'è una chance che la foglia contenga una decorazione
        if(enableDecoration && rand() % 2 && rand() % 2 && rand() % 2){
            // alterna tra decorazioni rosse e decorazioni blu
            if(rand() % 2){
                // decorazione rossa
                printf(GRNHBDR "o" CRESET);
            }else{
                // decorazione blu
                printf(GRNHBDB "o" CRESET);
            }
        }else{
            // foglia normale
            printf(GRNHB "^" CRESET);
        }
        break;
    case 4:
        // (|)
        printf(YELHB "|" CRESET);
        break;
    case 5:
        // STELLA (+)
        printf(YELHB "+" CRESET);
        break;
    case 6:
        // STELLA (-)
        printf(YELHB "-" CRESET);
        break;
    case 7:
        // STELLA (/')
        printf(YELHB "/" CRESET);
        break;
    case 8:
        // STELLA (\)
        printf(YELHB "\\" CRESET);
        break;
    default:
        // ARIA / NEVE
        // stampa la neve randomicamente e solo se abilitata
        if(enableSnow && rand() % 2 && rand() % 2){
            printf(WHTHB "*" CRESET);
        }else{
            printf(WHTHB " " CRESET);
        }
        break;
    }
}