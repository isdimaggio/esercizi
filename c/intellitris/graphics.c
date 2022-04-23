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

char* TRIS_p2c (
    int player
){
    if(player == 0)
    {
        return COLOR_PLAYER0 "0" CRESET;
    }
    else if(player == 1)
    {
        return COLOR_PLAYER1 "X" CRESET;
    }
    else
    {
        return "-";
    }
}

void TRIS_print_header(
    int player,
    char playerName[],
    int win
)
{
    printf(COLOR_HEADER "TRIS by Vittorio Lo Mele (3Ci)" CRESET ENDL);
    /* impostazione colore */
    if (player) 
    {
        printf(COLOR_PLAYER1);
    }
    else
    {
        printf(COLOR_PLAYER0);
    }
    /* controlla vincita */
    if (win == 1)
    {
        printf("Complimenti %s, HAI VINTO!" CRESET ENDL, playerName);
    }
    else if (win == 0)
    {
        printf("%s, è il tuo turno..." CRESET ENDL, playerName);
    }
    else
    {
        printf(CRESET "La partita termina in pareggio :(" ENDL);
    }
}

#ifdef _WIN32

void TRIS_print_grid(
    int grid[9]
){
    printf("+-1-+-2-+-3-+" ENDL);
    printf(
        "| %s | %s | %s |" ENDL,
        TRIS_p2c(grid[0]),
        TRIS_p2c(grid[1]),
        TRIS_p2c(grid[2])
    );
    printf("+-4-+-5-+-6-+" ENDL);
    printf(
        "| %s | %s | %s |" ENDL,
        TRIS_p2c(grid[3]),
        TRIS_p2c(grid[4]),
        TRIS_p2c(grid[5])
    );
    printf("+-7-+-8-+-9-+" ENDL);
    printf(
        "| %s | %s | %s |" ENDL,
        TRIS_p2c(grid[6]),
        TRIS_p2c(grid[7]),
        TRIS_p2c(grid[8])
    );
    printf("+---+---+---+" ENDL);
}

#else

void TRIS_print_grid(
    int grid[9]
){
    
    printf("╒═1═╤═2═╤═3═╕" ENDL);
    printf(
        "│ %s │ %s │ %s │" ENDL,
        TRIS_p2c(grid[0]),
        TRIS_p2c(grid[1]),
        TRIS_p2c(grid[2])
    );
    printf("├─4─┼─5─┼─6─┤" ENDL);
    printf(
        "│ %s │ %s │ %s │" ENDL,
        TRIS_p2c(grid[3]),
        TRIS_p2c(grid[4]),
        TRIS_p2c(grid[5])
    );
    printf("├─7─┼─8─┼─9─┤" ENDL);
    printf(
        "│ %s │ %s │ %s │" ENDL,
        TRIS_p2c(grid[6]),
        TRIS_p2c(grid[7]),
        TRIS_p2c(grid[8])
    );
    printf("╘═══╧═══╧═══╛" ENDL);
}

#endif