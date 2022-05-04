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

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Function: TRIS_setup_console
 * ----------------------------
 *   Se compilato per Windows, inizializza la console
 *   per supportare i caratteri ANSI, ovvero i colori.
 *
 *   returns: nothing
 */
void TRIS_setup_console(void);


/*
 * Function: TRIS_restore_console
 * ----------------------------
 *   Se compilato per Windows, ripristina le impostazioni
 *   della console a prima del setup, per evitare glitch
 *   grafici.
 *
 *   returns: nothing
 */
void TRIS_restore_console(void);

/*
 * Function: TRIS_delay
 * ----------------------------
 *   Pausa l'esecuzione del gioco per i millisecondi dati
 * 
 *   millisec: numero di millisecondi per cui fermarsi
 *
 *   returns: nothing
 */
void TRIS_delay(int millisec);