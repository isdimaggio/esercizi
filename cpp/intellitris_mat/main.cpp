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

#include <iostream>
#include <string>
#include <string.h>

#include "console.h"
#include "game.h"
#include "graphics.h"
#include "ai.h"
#include "matrix.h"

/*
 * Variable: TRIS_grid
 * ----------------------------
 *   Tabella di gioco organizzata nel seguente modo
 *      00  |  01  |  02
 *      10  |  11  |  12
 *      20  |  21  |  22
 */
int TRIS_grid[3][3];

bool TRIS_v_debugEnabled = false;
int TRIS_v_selectedBot = 0;
int TRIS_v_currentPlayer = 3; // inizia sempre player1
bool TRIS_v_winFlag = false;

std::string player1_name = "";
std::string player2_name = "";

char playerNameBuf[128] = "";

int main(
    int argc, 
    char *argv[]
)
{
    // controlla se il debug va abilitato
    if (argc > 1)
    {
        if (strcmp("--debug", argv[1]) == 0) TRIS_v_debugEnabled = true;
    }

    TRIS_setup_console();

    if(TRIS_v_debugEnabled) std::cerr << "[i] Inserimento nomi player" << std::endl;

    // chiedi nomi dei giocatori
    std::cout << "---------- CONFIGURAZIONE PLAYER ----------" << std::endl;
    std::cout << "Inserisci il nome del Giocatore 1 (0, Rosso): ";
    do
    {
        if (player1_name.length() > 126)
        {
            std::cout << "Nome troppo lungo, riprova: ";
        }
        getline(std::cin, player1_name);
    } while (player1_name.length() > 126);

    // scelta tra bot e player
    std::string tmpchoice = "";
    bool useBot = false;

    std::cout << "Giocare contro un bot o player? (B | P): ";
    getline(std::cin, tmpchoice);

    if (tmpchoice.length() != 1) 
    {
        printf("Scelta non valida, fallback su player \n");   
        useBot = false;
    }
    else
    {
        switch (tmpchoice.front()) // seleziona primo carattere
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
    } 

    if (useBot)
    {
        if(TRIS_v_debugEnabled) std::cerr << "[i] Selezionato bot come secondo player" << std::endl;

        std::cout << "----------- CONFIGURAZIONE BOT -----------" << std::endl;
        std::cout << "1. dumbfuck" << std::endl;
        std::cout << "2. lineblock" << std::endl;
        std::cout << "3. winningmove" << std::endl;

        std::string tmpchoice = "";

        std::cout << "Seleziona il bot contro cui giocare: ";
        getline(std::cin, tmpchoice);

        if (tmpchoice.length() != 1) 
        {
            printf("Scelta non valida, fallback su 1. dumbfuck \n");
            TRIS_v_selectedBot = 1;
            TRIS_delay(1000);
        }
        else
        {
            switch (tmpchoice.front())
            {
            case '1':
                TRIS_v_selectedBot = 1;
                player2_name = "[BOT] dumbfuck";
                break;
            case '2':
                TRIS_v_selectedBot = 2;
                player2_name = "[BOT] lineblock";
                break;
            case '3':
                TRIS_v_selectedBot = 3;
                player2_name = "[BOT] winningmove";
                break;
            default:
                printf("Scelta non valida, fallback su 1. dumbfuck \n");   
                TRIS_v_selectedBot = 1;
                TRIS_delay(1000);
                break;
            }
        }

    }
    else
    {
        if(TRIS_v_debugEnabled) std::cerr << "[i] Selezionato umano come secondo player" << std::endl;

        std::cout << "Inserisci il nome del Giocatore 2 (X, Blu): ";
        do
        {
            if (player2_name.length() > 126)
            {
                std::cout << "Nome troppo lungo, riprova: ";
            }
            getline(std::cin, player2_name);
        } while (player2_name.length() > 126);
    }

    if(TRIS_v_debugEnabled) std::cerr   << "[i] Nomi player inseriti 1: " 
                                        << player1_name
                                        << " 2: "
                                        << player2_name
                                        << std::endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            TRIS_grid[i][j] = 1;
        }
    }

    // per tutte le giocate possibili
    for (int i = 0; i < 9; i++)
    {
        clrscr();

        if(TRIS_v_debugEnabled) std::cerr   << "---" 
                                            << std::endl 
                                            << "[d] player " 
                                            << playerNameBuf 
                                            << " giocata: " 
                                            << i << std::endl;

        // controlla vincita
        if(i > 3)
        {
            // ha senso controllare solo dalla quinta in poi
            int wp = TRIS_winning_player(TRIS_grid);
            if(TRIS_v_debugEnabled) std::cerr << "---" << std::endl << "[d] player vincente: " << wp << std::endl;
            if(wp != 1)
            {
               if(TRIS_v_debugEnabled) std::cerr << "[i] Flag vittoria triggerata" << std::endl; 
               TRIS_v_currentPlayer = wp;
               TRIS_v_winFlag = true;
            }
        }

        // carica nel buffer il nome del giocatore corrente
        if(TRIS_v_currentPlayer == 3)
        {
            memset(playerNameBuf, 0, sizeof playerNameBuf); // ripulisce array prima della copia
            player1_name.copy(playerNameBuf, player1_name.length());
        }
        else
        {
            memset(playerNameBuf, 0, sizeof playerNameBuf);
            player2_name.copy(playerNameBuf, player2_name.length());
        }

        // stampa grafiche
        TRIS_print_header
        (
            TRIS_v_currentPlayer,
            playerNameBuf,
            TRIS_v_winFlag
        );
        TRIS_print_grid(TRIS_grid);

        if(TRIS_v_debugEnabled) std::cerr << "[i] Stampata interfaccia grafica" << std::endl; 

        if (TRIS_v_winFlag)
        {
            if(TRIS_v_debugEnabled) std::cerr << "[i] Gioco vinto, uscendo dal programma" << std::endl; 
            break;
        }

        if(TRIS_v_debugEnabled) std::cerr << "[d] chiedendo posiz. ins. a player " 
                                    << TRIS_v_currentPlayer  
                                    << " (bot on: " 
                                    << TRIS_v_selectedBot 
                                    << ")"
                                    << std::endl;

        // se il bot è attivo ed è il suo turno
        if(TRIS_v_selectedBot > 0 && TRIS_v_currentPlayer == 5)
        {
            std::cout << player2_name << " sta pensando..." << std::endl;
            TRIS_delay(1000);

            // chiamata AI
            TRIS_coords pos = TRIS_ai_wrapper
            (
                TRIS_v_selectedBot, 
                TRIS_grid
            );

            if (TRIS_grid[pos.x][pos.y] == 1)
            {
                // se la cella è libera fai piazzare bot
                TRIS_grid[pos.x][pos.y] = 5;
            }
            else
            {
                std:: cout  << "[!] Exception occurred: " 
                            << player2_name 
                            << " ha provato a inserire una giocata nella cella "
                            << pos.x << ',' << pos.y
                            << " gia occupata";
                return(0);
            }
        }
        else
        {
            // gioca il player
            int pos = 0;

            do
            {
                do
                {
                    // input sicuro singola cifra
                    pos = 0;
                    std::string tmpchoice = "";
                    std::cout   << "Dove inserisco "
                                << TRIS_p2c(TRIS_v_currentPlayer)
                                << " [1-9]: ";
                    getline(std::cin, tmpchoice);

                    if (tmpchoice.length() != 1) 
                    {
                        std::cout << "Posizione non valida!" << std::endl;   
                    }
                    else
                    {
                        // controlla per caratteri validi (da 1 a 9)
                        if (tmpchoice.front() < 49 || tmpchoice.front() > 57)
                        {
                            // inserito un carattere
                            std::cout << "Posizione non valida!" << std::endl;  
                        }
                        else
                        {
                            pos = tmpchoice.front() - 48;
                        }
                    }
                } while (pos == 0);      
            } 
            while 
            (
                !TRIS_set_grid
                (
                    TRIS_grid,
                    pos,
                    TRIS_v_currentPlayer
                )
            );

            if(TRIS_v_debugEnabled) std::cerr << "[d] posizione valida piazzata in " << pos << std::endl; 
        }

        // scambia giocatore corrente
        if (TRIS_v_currentPlayer == 3)
        {
            TRIS_v_currentPlayer = 5;
        }
        else
        {
            TRIS_v_currentPlayer = 3;
        }
    }

    if (!TRIS_v_winFlag)
    {
        clrscr();
        
        // pareggio
        TRIS_print_header
        (
            TRIS_v_currentPlayer,
            playerNameBuf,
            2
        );
        TRIS_print_grid(TRIS_grid);

        if(TRIS_v_debugEnabled) std::cerr << "[i] partita finita in pareggio, uscendo" << std::endl; 
    }

    TRIS_restore_console();
    return 0;
}