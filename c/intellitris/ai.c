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

int TRIS_ai_wrapper
(
    int selectedBot, 
    int grid[9]
){
    switch (selectedBot)
    {
    case 1:
        return ai1(grid);
        break;
    
    case 2:
        return ai2(grid);
        break;

    default:
        return ai1(grid);
        break;
    }
}

int ai1(int grid[9])
{
    // bot stupido
    // inserisce il suo segno nel primo posto disponibile
    for(int i = 0; i < 9; i++)
    {
        if(grid[i] == -1)
        {
            return i;
        }
    }
}

int ai2(int grid[9])
{
    return 5; // WIP
}