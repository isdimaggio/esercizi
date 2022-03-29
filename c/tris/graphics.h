/*
Copyright 2022 Lo Mele Vittorio

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef GRAPHICS
#define GRAPHICS

#include "stdbool.h"
#include "stdio.h"

#define COLOR_PLAYER0       "\e[91m"    /* colore ANSI giocatore 1 */
#define COLOR_PLAYER1       "\e[94m"    /* colore ANSI giocatore 2 */
#define COLOR_HEADER        "\e[92m"    /* colore ANSI dell'intestazione */
#define CRESET              "\e[0m"     /* codice escape ANSI per reset colori */
#define ENDL                "\n"        /* a capo */

/*
 * Function: TRIS_print_header
 * ----------------------------
 *   Stampa la testata della grafica su terminale
 *   che contiene le informazioni sul player ed eventuali
 *   messaggi di vincita
 *
 *   player: bit del player (seleziona tra 0 ed 1)
 *   playerName: array contentente nome del player
 *   playerNameLength: lunghezza del nome del player
 *   win: flag da impostare in caso di vittoria
 *
 *   returns: nothing
 */
void TRIS_print_header(
    int player,
    char playerName[],
    int playerNameLength,
    bool win
);

/*
 * Function: TRIS_print_grid
 * ----------------------------
 *   Stampa la griglia di gioco a partire dal vettore
 *
 *   grid: vettore di 9 elementi contenente i dati
 *
 *   returns: nothing
 */
void TRIS_print_grid(
    int grid[9]
);

#endif