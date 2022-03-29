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

void TRIS_print_header(
    int player,
    char playerName[],
    int playerNameLength,
    bool win
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
    for (int i = 0; i < playerNameLength; i++)
    {
        printf("%c", playerName[i]);
    }
    /* controlla vincita */
    if (win)
    {
        printf(" - Complimenti, HAI VINTO!" CRESET ENDL);
    }
    else
    {
        printf(" - è il tuo turno..." CRESET ENDL);
    }
}

void TRIS_print_grid(
    int grid[9]
){
    printf("╒═══╤═══╤═══╕" ENDL);
    printf("│ %c │ %c │ %c │" ENDL);
    printf("├───┼───┼───┤" ENDL);
    printf("│ %c │ %c │ %c │" ENDL);
    printf("├───┼───┼───┤" ENDL);
    printf("│ %c │ %c │ %c │" ENDL);
    printf("╘═══╧═══╧═══╛" ENDL);
}