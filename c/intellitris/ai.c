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

const int wpax[8] = WPA;
const int wpbx[8] = WPB;
const int wpcx[8] = WPC;

int TRIS_ai_wrapper
(
    int selectedBot, 
    int grid[9]
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

int TRIS_internal_aiv1 (int grid[9])
{
    // bot stupido, solo per testare wrapper e logica di gioco
    // inserisce il suo segno nel primo posto disponibile
    for(int i = 0; i < 9; i++)
    {
        if(grid[i] == 1)
        {
            return i;
        }
    }
}

int TRIS_internal_aiv2 (int grid[9])
{
    // Se UTENTE non ha mosso al centro CPU gioca al centro.
    if (grid[4] == 1)
    {
        return 4;
    }

    //CPU controlla se c’è possibilità di tris su una linea o una diagonale, 
    //se VERO gioca per bloccarla 
    for(int i = 0; i < 8; i++)
    {
        int compute = grid[wpax[i]] * grid[wpbx[i]] * grid[wpcx[i]];
        if(compute == 9) 
        {
            // trovata combinazione da bloccare
            if(grid[wpax[i]] == 1)
            {
                return wpax[i];
            }
            else
            {
                if(grid[wpbx[i]] == 1)
                    return wpbx[i];
                else
                    return wpcx[i];
            }
        }
    }

    // altrimenti CPU gioca su una cella libera (bot stupido)
    for(int i = 0; i < 9; i++)
    {
        if(grid[i] == 1)
        {
            return i;
        }
    }
}

int TRIS_internal_aiv3 (int grid[9])
{
    // Se UTENTE non ha mosso al centro CPU gioca al centro.
    if (grid[4] == 1)
    {
        return 4;
    }

    // CPU controlla se c’è possibilità di tris PER LUI su una linea o una diagonale, 
    // se VERO gioca per effettuarla immediatamente 
    for(int i = 0; i < 8; i++)
    {
        int compute = grid[wpax[i]] * grid[wpbx[i]] * grid[wpcx[i]];
        if(compute == 25) 
        {
            // trovata combinazione per vincere
            if(grid[wpax[i]] == 1)
            {
                return wpax[i];
            }
            else
            {
                if(grid[wpbx[i]] == 1)
                    return wpbx[i];
                else
                    return wpcx[i];
            }
        }
    }

    // CPU controlla se c’è possibilità di tris PER UTENTE su una linea o una diagonale, 
    // se VERO gioca per bloccarla 
    for(int i = 0; i < 8; i++)
    {
        int compute = grid[wpax[i]] * grid[wpbx[i]] * grid[wpcx[i]];
        if(compute == 9) 
        {
            // trovata combinazione avversaria da bloccare
            if(grid[wpax[i]] == 1)
            {
                return wpax[i];
            }
            else
            {
                if(grid[wpbx[i]] == 1)
                    return wpbx[i];
                else
                    return wpcx[i];
            }
        }
    }

    //  CPU controlla se c’è una riga con una sua singola giocata
    // nel caso ne aggiunge un altra
    for(int i = 0; i < 8; i++)
    {
        int compute = grid[wpax[i]] * grid[wpbx[i]] * grid[wpcx[i]];
        if(compute == 9) 
        {
            // trovata combinazione da bloccare
            if(grid[wpax[i]] == 1)
            {
                return wpax[i];
            }
            else
            {
                return wpcx[i];
            }
        }
    }

    // altrimenti CPU gioca su una cella libera
    for(int i = 0; i < 9; i++)
    {
        if(grid[i] == 1)
        {
            return i;
        }
    }
}