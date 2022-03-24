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
int grid [9];

bool vincita = false;
int currentPlayer = 0;

// player names
char playerNameBuf[128] = {0};
char player0[128] = {0};
char player1[128] = {0};

int main(
    void
){
    TRIS_setup_console();

    // chiedi i nomi dei giocatori
    printf("Inserisci il nome del giocatore 1 (0 - rosso): ");
    scanf("%s", player0);
    printf("Inserisci il nome del giocatore 2 (X - blu): ");
    scanf("%s", player1);

    // reset griglia
    for(int i = 0; i < 9; i++)
    {
        grid[i] = -1;
    }

    while (true)
    {
        clrscr();

        // controlla vincita
        int wp = TRIS_winning_player(grid);
        if(wp != -1)
        {
            currentPlayer =  wp;

            vincita = true;
        }

        if(currentPlayer)
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

        if(vincita)
        {
            break;
        }
        
        int pos;

        do{
            // input coordinate
            printf("Dove inserisco %s? [1-9]: ", TRIS_p2c(currentPlayer));
            scanf("%d", &pos);
            pos--; // aggiusta da 0 ad 8
        }while(
            !TRIS_set_grid(
                grid, 
                pos, 
                currentPlayer
            )
        );

        // scambia giocatore corrente
        currentPlayer = !currentPlayer;
    }

    TRIS_restore_console();
    return 0;
}