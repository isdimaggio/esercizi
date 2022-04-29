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
#include "winpatterns.h"

const int wpa[8] = WPA;
const int wpb[8] = WPB;
const int wpc[8] = WPC;

bool TRIS_set_grid(
    int grid[9], 
    int pos,
    int player
){
    if(pos < 0 || pos > 8){
        printf("Posizione non valida! \n");
        return false; 
    }
    // controllo posizione vuota
    if(grid[pos] == 1)
    {
        if(player == 0)
        {
            grid[pos] = 3;
        }
        else if (player == 1)
        {
            grid[pos] = 5;
        }
        else
        {
            grid[pos] = 1;
        }
        
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
    for(int i = 0; i < 8; i++)
    {
        int compute = grid[wpa[i]] * grid[wpb[i]] * grid[wpc[i]];
        if(compute == 27) 
        {
            return 0;
        }
        else if (compute == 125)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}