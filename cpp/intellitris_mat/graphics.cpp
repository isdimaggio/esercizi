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
    if(player == 3)
    {
        return COLOR_PLAYER0 "0" CRESET;
    }
    else if(player == 4 || player == 5)
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
    std::string playerName,
    int win
)
{
    std::cout << COLOR_HEADER << "TRIS by Vittorio Lo Mele (3Ci)" << CRESET << std::endl;
    /* impostazione colore */
    if (player == 5) 
    {
        std::cout << COLOR_PLAYER1;
    }
    else
    {
        std::cout << COLOR_PLAYER0;
    }
    /* controlla vincita */
    if (win == 1)
    {
        std::cout << "Complimenti " << playerName << ", HAI VINTO!" << CRESET << std::endl;
    }
    else if (win == 0)
    {
        std::cout << playerName << ", è il tuo turno..." << CRESET << std::endl;
    }
    else
    {
        std::cout << CRESET << "La partita termina in pareggio :(" << std::endl;
    }
}

#ifdef _WIN32

void TRIS_print_grid(
    int grid[3][3]
){
    printf("+-1-+-2-+-3-+" ENDL);
    printf(
        "| %s | %s | %s |" ENDL,
        TRIS_p2c(grid[0][0]),
        TRIS_p2c(grid[0][1]),
        TRIS_p2c(grid[0][2])
    );
    printf("+-4-+-5-+-6-+" ENDL);
    printf(
        "| %s | %s | %s |" ENDL,
        TRIS_p2c(grid[1][0]),
        TRIS_p2c(grid[1][1]),
        TRIS_p2c(grid[1][2])
    );
    printf("+-7-+-8-+-9-+" ENDL);
    printf(
        "| %s | %s | %s |" ENDL,
        TRIS_p2c(grid[2][0]),
        TRIS_p2c(grid[2][1]),
        TRIS_p2c(grid[2][2])
    );
    printf("+---+---+---+" ENDL);
}

#else

void TRIS_print_grid(
    int grid[3][3]
){
    
    printf("╒═1═╤═2═╤═3═╕" ENDL);
    printf(
        "│ %s │ %s │ %s │" ENDL,
        TRIS_p2c(grid[0][0]),
        TRIS_p2c(grid[0][1]),
        TRIS_p2c(grid[0][2])
    );
    printf("├─4─┼─5─┼─6─┤" ENDL);
    printf(
        "│ %s │ %s │ %s │" ENDL,
        TRIS_p2c(grid[1][0]),
        TRIS_p2c(grid[1][1]),
        TRIS_p2c(grid[1][2])
    );
    printf("├─7─┼─8─┼─9─┤" ENDL);
    printf(
        "│ %s │ %s │ %s │" ENDL,
        TRIS_p2c(grid[2][0]),
        TRIS_p2c(grid[2][1]),
        TRIS_p2c(grid[2][2])
    );
    printf("╘═══╧═══╧═══╛" ENDL);
}

#endif