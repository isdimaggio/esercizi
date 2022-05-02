/*
Copyright 2021 Vinciguerra Antonello, Lo Mele Vittorio

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WtabellaANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// combinazioni di vincita per matrici
int wp1_i[8] = {0, 0, 0, 0, 1, 2, 0, 2};
int wp1_j[8] = {0, 1, 2, 0, 0, 0, 0, 0};

int wp2_i[8] = {1, 1, 1, 0, 1, 2, 1, 1};
int wp2_j[8] = {0, 1, 2, 1, 1, 1, 1, 1};

int wp3_i[8] = {2, 2, 2, 0, 1, 2, 2, 0};
int wp3_j[8] = {0, 1, 2, 2, 2, 2, 2, 2};

int tabella[3][3];

// UTENTE X  -> 3,  CPU O  -> 5
// inizia sempre l'utente
int giocatore = 3;

void switchGiocatore()
{
    if (giocatore == 3)
    {
        giocatore = 5;
    }
    else
    {
        giocatore = 3;
    }
}

char giocatoreToChar(int simbolo)
{
    if (simbolo == 3)
    {
        return 'X';
    }
    else if (simbolo == 5)
    {
        return 'O';
    }
    else
    {
        return '-';
    }
}

void stampaTabella()
{
    printf("+-1-+-2-+-3-+\n");
    printf(
        "| %c | %c | %c |\n",
        giocatoreToChar(tabella[0][0]),
        giocatoreToChar(tabella[0][1]),
        giocatoreToChar(tabella[0][2]));
    printf("+-4-+-5-+-6-+\n");
    printf(
        "| %c | %c | %c |\n",
        giocatoreToChar(tabella[1][0]),
        giocatoreToChar(tabella[1][1]),
        giocatoreToChar(tabella[1][2]));
    printf("+-7-+-8-+-9-+\n");
    printf(
        "| %c | %c | %c |\n",
        giocatoreToChar(tabella[2][0]),
        giocatoreToChar(tabella[2][1]),
        giocatoreToChar(tabella[2][2]));
    printf("+---+---+---+\n\n");
}

bool inserisciSimbolo(
    int i,
    int j)
{
    // controllo posizione vuota
    if (tabella[i][j] == 1)
    {
        tabella[i][j] = 3;
        return true;
    }
    else
    {
        printf("Impossibile popolare una posizione gia popolata! \n");
        return false;
    }
}

bool posToMatrice(
    int posizione)
{
    int i, j;

    switch (posizione)
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
        printf("Posizione non valida! \n");
        return false;
    }

    bool r = inserisciSimbolo(i, j);
    return r;
}

void cpuPlay()
{
    // Se UTENTE non ha mosso al centro CPU gioca al centro.
    if (tabella[1][1] == 1)
    {
        tabella[1][1] = 5;
        return;
    }

    // CPU controlla se c’è possibilità di tris PER LUI su una linea o una diagonale,
    // se VERO gioca per effettuarla immediatamente
    for (int i = 0; i < 8; i++)
    {
        int moltiplicazione =
            tabella[wp1_i[i]][wp1_j[i]] *
            tabella[wp2_i[i]][wp2_j[i]] *
            tabella[wp3_i[i]][wp3_j[i]];

        if (moltiplicazione == 25)
        {
            // trovata combinazione per vincere
            if (tabella[wp1_i[i]][wp1_j[i]] == 1)
            {
                tabella[wp1_i[i]][wp1_j[i]] = 5;
                return;
            }
            else
            {
                if (tabella[wp2_i[i]][wp2_j[i]] == 1)
                {
                    tabella[wp2_i[i]][wp2_j[i]] = 5;
                    return;
                }
                else
                {
                    tabella[wp3_i[i]][wp3_j[i]] = 5;
                    return;
                }
            }
        }
    }

    // CPU controlla se c’è possibilità di tris PER UTENTE su una linea o una diagonale,
    // se VERO gioca per bloccarla
    for (int i = 0; i < 8; i++)
    {
        int moltiplicazione =
            tabella[wp1_i[i]][wp1_j[i]] *
            tabella[wp2_i[i]][wp2_j[i]] *
            tabella[wp3_i[i]][wp3_j[i]];

        if (moltiplicazione == 9)
        {
            // trovata combinazione per bloccare
            if (tabella[wp1_i[i]][wp1_j[i]] == 1)
            {
                tabella[wp1_i[i]][wp1_j[i]] = 5;
                return;
            }
            else
            {
                if (tabella[wp2_i[i]][wp2_j[i]] == 1)
                {
                    tabella[wp2_i[i]][wp2_j[i]] = 5;
                    return;
                }
                else
                {
                    tabella[wp3_i[i]][wp3_j[i]] = 5;
                    return;
                }
            }
        }
    }

    // altrimenti CPU gioca su una cella libera
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabella[i][j] == 1) 
            {
                tabella[i][j] = 5;
                return;
            }
        }
    }
}

void controllaVincita()
{
    for (int i = 0; i < 8; i++)
    {
        // controlla vincitore
        int moltiplicazione =
            tabella[wp1_i[i]][wp1_j[i]] *
            tabella[wp2_i[i]][wp2_j[i]] *
            tabella[wp3_i[i]][wp3_j[i]];

        if (moltiplicazione == 27)
        {
            stampaTabella();
            printf("Vince l'utente! \n");
            exit(0);
        }
        else if (moltiplicazione == 125)
        {
            stampaTabella();
            printf("Vince la CPU! \n");
            exit(0);
        }
    }
}

int main(
    int argc,
    char *argv[])
{
    // inizializzazione matrice
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabella[i][j] = 1;
        }
    }

    // per tutte le giocate possibili
    for (int i = 0; i < 9; i++)
    {
        // stampa tabella
        stampaTabella();

        if (giocatore == 3)
        {
            // gioca il player
            int posizione;

            do
            {
                int risultato_scanf;

                do
                {
                    printf("Dove inserisco X?: ");
                    risultato_scanf = scanf("%d", &posizione);
                    if (risultato_scanf == 0)
                    {
                        scanf("%*[^\n ]"); // ripulisci buffer
                        printf("Posizione non valida! \n");
                    }
                } 
                while (risultato_scanf == 0);
            } 
            while (!posToMatrice(posizione));
        }
        else
        {
            // gioca il pc
            printf("Gioca il bot! \n");
            cpuPlay();
        }

        controllaVincita();
        switchGiocatore();
    }

    // finisce in pareggio
    printf("La partita termina in pareggio :( \n");
}