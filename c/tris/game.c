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

#include "game.h"

const int winPatternsA[8] = {0, 1, 2, 0, 3, 6, 0, 6};
const int winPatternsB[8] = {3, 4, 5, 1, 4, 7, 4, 4};
const int winPatternsC[8] = {6, 7, 8, 2, 5, 8, 8, 2};

bool TRIS_set_grid(
    int grid[9], 
    int pos,
    int player
){
    if(pos < 0 && pos > 8){
        printf("Posizione non valida! \n");
        return false; 
    }
    // controllo posizione vuota
    if(grid[pos] == -1)
    {
        grid[pos] = player;
        return true;
    }
    else
    {
        printf("Impossibile popolare una posizione gia popolata! \n");
        return false;
    }
}

int TRIS_winning_player(
    int grid[9]
){
    // cerca in tutti i pattern
    for(int i = 0; i < 9; i++){
        if(
            grid[winPatternsA[i]] == grid[winPatternsB[i]] && 
            grid[winPatternsB[i]] == grid[winPatternsC[i]]
        ){
            // se trovato uno vincente ritorna il codice giocatore
            return grid[winPatternsA[i]];
        }
    }
    return -1;
}