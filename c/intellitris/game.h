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

#ifndef GAMELOGIC
#define GAMELOGIC

#include "stdbool.h"
#include "stdio.h"

/*
 * Function: TRIS_set_grid
 * ----------------------------
 *   Inserisce nella griglia il simbolo del giocatore
 *   nella posizione specificata
 *
 *   grid: array contenente la griglia
 *   pos: posizione da inserire
 *   player: giocatore inserente
 *
 *   returns: (bool) success / fail
 */
bool TRIS_set_grid(
    int grid[9], 
    int pos,
    int player
);

/*
 * Function: TRIS_winning_player
 * ----------------------------
 *   Controlla la griglia per tutti i pattern vincenti
 *   se trovato ritorna il numero del player, se non trovato
 *   ritorna -1
 *
 *   grid: array contenente la griglia
 *   debug_enabled: se abilitare i messaggi di debug
 *
 *   returns: (int) numero player
 */
int TRIS_winning_player(
    int grid[9],
    bool debug_enabled
);

#endif