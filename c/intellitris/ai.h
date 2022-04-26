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

#ifndef AI
#define AI

#include "stdbool.h"
#include "stdio.h"

/*
 * Function: TRIS_ai_wrapper
 * ----------------------------
 *   A partire da una situazione esistente, calcola la prossima mossa
 *   in base al livello di difficolta selezionato.
 *
 *   selectedBot: bot selezionato (livello di difficolta)
 *   grid: array contenente la griglia
 *
 *   returns: (bool) success / fail
 */
int TRIS_ai_wrapper
(
    int selectedBot, 
    int grid[9]
);

// internal functions
int TRIS_internal_aiv1 (int grid[9]);
int TRIS_internal_aiv2 (int grid[9]);
int TRIS_internal_aiv3 (int grid[9]);

#endif