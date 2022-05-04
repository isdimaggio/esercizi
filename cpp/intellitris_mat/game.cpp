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

int wp1_i[8] = WP1_I;
int wp1_j[8] = WP1_J;

int wp2_i[8] = WP2_I;
int wp2_j[8] = WP2_J;

int wp3_i[8] = WP3_I;
int wp3_j[8] = WP3_J;

bool TRIS_set_grid(
    int grid[3][3], 
    int pos,
    int player
){
    // conversione da posizione a coordinata matrice
    int i, j;

    switch (pos)
    {
    case 1:
        i = 0;
        j = 0;
        break;
    case 2:
        i = 0;
        j = 1;
        break;
    case 3:
        i = 0;
        j = 2;
        break;
    case 4:
        i = 1;
        j = 0;
        break;
    case 5:
        i = 1;
        j = 1;
        break;
    case 6:
        i = 1;
        j = 2;
        break;
    case 7:
        i = 2;
        j = 0;
        break;
    case 8:
        i = 2;
        j = 1;
        break;
    case 9:
        i = 2;
        j = 2;
        break;
    default:
        std::cout << "[!] Posizione non valida" << std::endl; 
        return false; 
    }

    // controllo posizione vuota
    if(grid[i][j] == 1)
    {
        grid[i][j] = player;
        return true;
    }
    else
    {
        std::cout << "[!] Posizione già popolata" << std::endl;
        return false;
    }
}

int TRIS_winning_player(
    int grid[3][3]
){
    for (int i = 0; i < 8; i++)
    {
        // controlla vincitore
        int compute =
            grid[wp1_i[i]][wp1_j[i]] *
            grid[wp2_i[i]][wp2_j[i]] *
            grid[wp3_i[i]][wp3_j[i]];

        if (compute == 27)
        {
            return 3;
        }
        else if (compute == 125)
        {
            return 5;
        }
    }
    return 1;
}