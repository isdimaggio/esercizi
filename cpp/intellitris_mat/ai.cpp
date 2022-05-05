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

#include "ai.h"
#include "winpatterns.h"

int wp1_i_ai[8] = WP1_I;
int wp1_j_ai[8] = WP1_J;

int wp2_i_ai[8] = WP2_I;
int wp2_j_ai[8] = WP2_J;

int wp3_i_ai[8] = WP3_I;
int wp3_j_ai[8] = WP3_J;

TRIS_coords TRIS_ai_wrapper
(
    int selectedBot, 
    int grid[3][3]
){
    switch (selectedBot)
    {
    case 1:
        return TRIS_internal_aiv1(grid);
        break;
    
    case 2:
        return TRIS_internal_aiv2(grid);
        break;

    case 3:
        return TRIS_internal_aiv3(grid);
        break;

    default:
        return TRIS_internal_aiv1(grid);
        break;
    }
}

TRIS_coords TRIS_internal_aiv1 (int grid[3][3])
{
    // bot stupido, solo per testare wrapper e logica di gioco
    // inserisce il suo segno nel primo posto disponibile
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == 1) 
            {
                return TRIS_coords(i, j);
            }
        }
    }
}

TRIS_coords TRIS_internal_aiv2 (int grid[3][3])
{
    // bot stupido, solo per testare wrapper e logica di gioco
    // inserisce il suo segno nel primo posto disponibile
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == 1) 
            {
                return TRIS_coords(i, j);
            }
        }
    }
}

TRIS_coords TRIS_internal_aiv3 (int grid[3][3])
{
    // bot stupido, solo per testare wrapper e logica di gioco
    // inserisce il suo segno nel primo posto disponibile
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == 1) 
            {
                return TRIS_coords(i, j);
            }
        }
    }
}