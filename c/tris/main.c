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
#include "console.h"


/*
 * Variable: TRIS_grid
 * ----------------------------
 *   Tabella di gioco organizzata nel seguente modo
 *      0  |  1  |  2
 *      3  |  4  |  5 
 *      6  |  7  | 8
 */
int TRIS_grid [9] = {1,0,1,0,1,0,1,0,1};

int main(
    void
){
    TRIS_setup_console();
    TRIS_print_header
    (
        0,
        "loris",
        5,
        0
    );
    TRIS_restore_console();
}