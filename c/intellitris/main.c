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
#include "ai.h"

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
int selectedBot = 0;

// player names
char playerNameBuf[128] = {0};
char player1[128] = {0};
char player2[128] = {0};

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
    printf("------------- PLAYER ---------------\n");
    printf("Inserisci il nome del giocatore 1 (0 - rosso): ");
    TRIS_scanf(127, &player1);

    // scelta tra bot e player
    char tmpb;
    bool useBot;
    do
    {
        printf("Giocare contro un bot o player? (B | P): ");
        scanf(" %c", &tmpb);
    } while (tmpb == '\0');
    switch (tmpb)
    {
    case 'B':
        useBot = true;
        break;
    case 'b':
        useBot = true;
        break;
    case 'P':
        useBot = false;
        break;
    case 'p':
        useBot = false;
        break;
    default:
        printf("Scelta non valida, fallback su player \n");   
        useBot = false;
        break;
    }
    
    if (useBot)
    {
        if(debug_enabled) fprintf(stderr, "selezionato bot come secondo player \n");

        printf("\n --------------- BOT ----------------\n");
        printf("1. dumbfuck\n");
        printf("2. lineblock\n");
        printf("3. winningmove\n");

        char tmpbc;
        do
        {
            printf("Seleziona il bot contro cui giocare: ");
            scanf(" %c", &tmpbc);
        } while (tmpbc == '\0');
        switch (tmpbc)
        {
        case '1':
            selectedBot = 1;
            strcpy(player2, "[dumbfuck]");
            break;
        case '2':
            selectedBot = 2;
            strcpy(player2, "[lineblock]");
            break;
        case '3':
            selectedBot = 3;
            strcpy(player2, "[winningmove]");
            break;
        default:
            printf("Scelta non valida, fallback su [dumbfuck] \n");   
            selectedBot = 1;
            break;
        }
    }
    else
    {
        if(debug_enabled) fprintf(stderr, "selezionato umano come secondo player \n");
        printf("Inserisci il nome del giocatore 2 (X - blu): ");

        // ripulisci buffer da scanf precedente
        char tmp;
        scanf("%c", &tmp);
        write(STDIN_FILENO, "a", 1);
        
        TRIS_scanf(127, &player2);
    }

    if(debug_enabled) fprintf(stderr, "nomi player inseriti \n");

    // reset griglia
    for (int i = 0; i < 9; i++)
    {
        grid[i] = 1;
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
            int wp = TRIS_winning_player(grid);
            if(debug_enabled) fprintf(stderr, "player vincente: %d \n", wp);
            if (wp != -1)
            {
                if(debug_enabled) fprintf(stderr, "flag vittoria triggerata \n");
                currentPlayer = wp;
                vincita = true;
            }
        }

        if (currentPlayer)
            strcpy(playerNameBuf, player2);
        else
            strcpy(playerNameBuf, player1);

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

        // se bot attivo e suo turno
        if (selectedBot && currentPlayer) 
        {
            // gioca il bot
            if(debug_enabled) fprintf(stderr, "--- \n chiedendo posizione inserimento (giocatore corrente %d) \n", currentPlayer);
            printf("%s sta pensando... \n", player2);
            TRIS_delay(1000);
            
            // chiamata AI
            int pos = TRIS_ai_wrapper
            (
                selectedBot, 
                grid
            );

            bool res = TRIS_set_grid
            (
                grid,
                pos,
                currentPlayer
            );

            if(!res) 
            {
                printf(
                    "[!] Exception occurred: il bot %s ha provato a inserire una giocata nella cella %d gia occupata",
                    player2,
                    pos
                );
                return(0);
            }
        }
        else
        {
            // gioca il player
            int pos;

            do
            {
                if(debug_enabled) fprintf(stderr, "--- \n chiedendo posizione inserimento (giocatore corrente %d) \n", currentPlayer);
                int c;

                do 
                {
                    printf("Dove inserisco %s? [1-9]: ", TRIS_p2c(currentPlayer+3));
                    c = scanf ("%d", &pos);
                    if (c == 0) 
                    {
                        scanf ("%*[^\n ]");
                        printf ("Posizione non valida! \n");
                    }
                } 
                while (c == 0);
            } 
            while 
            (
                !TRIS_set_grid
                (
                    grid,
                    pos-1,
                    currentPlayer
                )
            );

            if(debug_enabled) fprintf(stderr, "posizione valida, piazzata in %d \n", pos);
        }

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