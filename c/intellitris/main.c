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

#include "graphics.h"
#include "console.h"
#include "game.h"

#include <stdbool.h>
#include <string.h>

/*
 * Variable: TRIS_grid
 * ----------------------------
 *   Tabella di gioco organizzata nel seguente modo
 *      0  |  1  |  2
 *      3  |  4  |  5
 *      6  |  7  |  8
 */
int grid[9];

bool vincita = false;
int currentPlayer = 0;

// player names
char playerNameBuf[128] = {0};
char player0[128] = {0};
char player1[128] = {0};

// debug
bool debug_enabled = 0;

int main(
    int argc, 
    char *argv[]
)
{
    // controlla se il debug va abilitato
    if (argc > 1)
    {
        if (strcmp("--debug", argv[1]) == 0) debug_enabled = true;
    }

    TRIS_setup_console();

    if(debug_enabled) fprintf(stderr, "inserimento nomi player \n");

    // chiedi i nomi dei giocatori
    printf("Inserisci il nome del giocatore 1 (0 - rosso): ");
    scanf("%s", player0);
    printf("Inserisci il nome del giocatore 2 (X - blu): ");
    scanf("%s", player1);

    if(debug_enabled) fprintf(stderr, "nomi player inseriti \n");

    // reset griglia
    for (int i = 0; i < 9; i++)
    {
        grid[i] = -1;
    }

    if(debug_enabled) fprintf(stderr, "reset della variabile griglia, inzio gioco \n");

    // per tutte le giocate possibili
    for (int i = 0; i < 9; i++)
    {
        clrscr();

        if(debug_enabled) fprintf(stderr, "--- \n giocata corrente: %d \n", i);

        // controlla vincita
        if (i > 3)
        {
            // ha senso controllare solo dalla quinta...
            // ...giocata in poi
            int wp = TRIS_winning_player(grid, debug_enabled);
            if(debug_enabled) fprintf(stderr, "player vincente: %d \n", wp);
            if (wp != -1)
            {
                if(debug_enabled) fprintf(stderr, "flag vittoria triggerata \n");
                currentPlayer = wp;
                vincita = true;
            }
        }

        if (currentPlayer)
            strcpy(playerNameBuf, player1);
        else
            strcpy(playerNameBuf, player0);

        // grafica
        TRIS_print_header
        (
            currentPlayer,
            playerNameBuf,
            vincita
        );
        TRIS_print_grid(grid);

        if(debug_enabled) fprintf(stderr, "interfaccia grafica stampata \n");

        if (vincita)
        {
            if(debug_enabled) fprintf(stderr, "gioco vinto, uscendo dal programma \n");
            break;
        }

        int pos;

        do
        {
            if(debug_enabled) fprintf(stderr, "--- \n chiedendo posizione inserimento (giocatore corrente %d) \n", currentPlayer);
            // input coordinate
            printf("Dove inserisco %s? [1-9]: ", TRIS_p2c(currentPlayer));
            scanf("%d", &pos);
            pos--; // aggiusta da 0 ad 8
        } 
        while 
        (
            !TRIS_set_grid
            (
                grid,
                pos,
                currentPlayer
            )
        );

        if(debug_enabled) fprintf(stderr, "posizione valida, piazzata in %d \n", pos);

        // scambia giocatore corrente
        currentPlayer = !currentPlayer;
    }

    if (!vincita)
    {
        clrscr();
        
        // pareggio
        TRIS_print_header
        (
            currentPlayer,
            playerNameBuf,
            2
        );
        TRIS_print_grid(grid);

        if(debug_enabled) fprintf(stderr, "finito in pari, uscendo \n");
    }

    TRIS_restore_console();
    return 0;
}