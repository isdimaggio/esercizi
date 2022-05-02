/*
Copyright 2021 Vinciguerra Antonello

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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char arr[3][3];
int i, j, win, loop=1;

void stampa()
{
    printf("\n 0    1    2 \n");
    printf("0  %c | %c | %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("  ----------- \n");
    printf("1  %c | %c | %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("  ----------- \n");
    printf("2  %c | %c | %c \n", arr[2][0], arr[2][1], arr[2][2]);
}

void vittoriax()
{
    for(int i=0; i<3; i++)
    {
        if(arr[i][0]=='x' && arr[i][1]=='x' && arr[i][2]=='x' )
        {
            win=1;
        }
        if(arr[0][i]=='x' && arr[1][i]=='x' && arr[2][i]== 'x')
        {
            win=1;
        }
        if(arr[0][0]=='x' && arr[1][1]=='x' && arr[2][2]=='x')
        {               
            win=1;
        }
        if(arr[0][2]=='x' && arr[1][1]=='x' && arr[2][0]=='x')
        {               
            win=1;
        }
    }
    if(win==1)
    {
        printf("la cpu ha vinto!");
        stampa();
        exit(0);
    }
}

void vittoriao()
{
    for(int i=0; i<3; i++)
    {
        if(arr[i][0]=='o' && arr[i][1]=='o' && arr[i][2]=='o' )
        {
            win=1;
        }
        if(arr[0][i]=='o' && arr[1][i]=='o' && arr[2][i]== 'o')
        {
            win=1;
        }
        if(arr[0][0]=='o' && arr[1][1]=='o' && arr[2][2]=='o')
        {               
            win=1;
        }
        if(arr[0][2]=='o' && arr[1][1]=='o' && arr[2][0]=='o')
        {               
            win=1;
        }
    }
    if(win==1)
    {
        printf("giocatore, hai vinto!");
        stampa();
        exit(0);
    }
}

void cpu()      //funge
{
    int k, w;
    srand(time(NULL));
    do
    {
        k=(rand()%3);
        w=(rand()%3);
        if(arr[k][w]==' ')
        {
            arr[k][w]='x';
            break;
        }
    } while(loop==1);
}
void giocatore()    //funge
{
    do
    {
        stampa();
        printf("Giocatore (o), è il tuo turno! \n");

        int temp1, temp2, i, j;

        do 
        {
            // inserisci i
            printf("I: ");
            temp1 = scanf("%d", &i);
            if(temp1 == 0 || i < 0 || i > 2)
            {
                scanf("%*[^\n]"); // pulisci buffer
                printf("Inserisci numero valido. \n");
            }
        }
        while (temp1 == 0 || i < 0 || i > 2);
        
        do 
        {
            // inserisci j
            printf("J: ");
            temp2 = scanf("%d", &j);
            if(temp2 == 0 || j < 0 || j > 2)
            {
                scanf("%*[^\n]"); // pulisci buffer
                printf("Inserisci numero valido. \n");
            }
        }
        while (temp2 == 0 || j < 0 || j > 2);

        if(arr[i][j]==' ')
        {
           arr[i][j]='o';
            break;
        }
    }while (loop==1);
    vittoriao();
}

void blocco()
{
    do
    {
        //blocchi su 00
        if(arr[0][1]=='o' && arr[0][2]=='o' && arr[0][0]==' ')
        {
            arr[0][0]='x';
            break;
        }
        if(arr[1][1]=='o' && arr[2][2]=='o' && arr[0][0]==' ')
        {
            arr[0][0]='x';
            break;
        }
        if(arr[1][0]=='o' && arr[2][0]=='o' && arr[0][0]==' ')
        {
            arr[0][0]='x';
            break;
        }
        //blocchi su 01
        if(arr[0][1]=='o' && arr[0][2]=='o' && arr[0][1]==' ')
        {
            arr[0][1]='x';
            break;
        }
        if(arr[1][1]=='o' && arr[2][1]=='o' && arr[0][1]==' ')
        {
            arr[0][1]='x';
            break;
        }
        //blocchi su 02
        if(arr[0][0]=='o' && arr[0][1]=='o' && arr[0][2]==' ')
        {
            arr[0][2]='x';
            break;
        }
        if(arr[1][1]=='o' && arr[2][0]=='o' && arr[0][2]==' ')
        {
            arr[0][2]='x';
            break;
        }
        if(arr[1][2]=='o' && arr[2][2]=='o' && arr[0][2]==' ')
        {
            arr[0][2]='x';
            break;
        }
        //blocchi su 10
        if(arr[0][0]=='o' && arr[2][0]=='o' && arr[1][0]==' ')
        {
            arr[1][0]='x';
            break;
        }
        if(arr[1][1]=='o' && arr[1][2]=='o' && arr[1][0]==' ')
        {
            arr[1][0]='x';
            break;
        }
        //blocchi su 11
        if(arr[1][0]=='o' && arr[1][2]=='o' && arr[1][1]==' ')
        {
            arr[1][1]='x';
            break;
        }
        if(arr[0][1]=='o' && arr[2][1]=='o' && arr[1][1]==' ')
        {
            arr[1][1]='x';
            break;
        }
        if(arr[0][0]=='o' && arr[2][2]=='o' && arr[1][1]==' ')
        {
            arr[1][1]='x';
            break;
        }
        if(arr[0][2]=='o' && arr[2][0]=='o' && arr[1][1]==' ')
        {
            arr[1][1]='x';
            break;
        }
        //blocchi su 12
        if(arr[1][0]=='o' && arr[1][1]=='o' && arr[1][2]==' ')
        {
            arr[1][2]='x';
            break;
        }
        if(arr[0][2]=='o' && arr[2][2]=='o' && arr[1][2]==' ')
        {
            arr[1][2]='x';
            break;
        }
        //blocchi su 20
        if(arr[0][0]=='o' && arr[1][0]=='o' && arr[2][0]==' ')
        {
            arr[2][0]='x';
            break;
        }
        if(arr[1][1]=='o' && arr[0][2]=='o' && arr[2][0]==' ')
        {
            arr[2][0]='x';
            break;
        }
        if(arr[2][1]=='o' && arr[2][2]=='o' && arr[2][0]==' ')
        {
            arr[2][0]='x';
            break;
        }
        //blocchi su 21
        if(arr[0][1]=='o' && arr[1][1]=='o' && arr[2][1]==' ')
        {
            arr[2][1]='x';
            break;
        }
        if(arr[2][0]=='o' && arr[2][2]=='o' && arr[2][1]==' ')
        {
            arr[2][1]='x';
            break;
        }
        //blocchi su 22
        if(arr[0][2]=='o' && arr[1][2]=='o' && arr[2][2]==' ')
        {
            arr[2][2]='x';
            break;
        }
        if(arr[0][0]=='o' && arr[1][1]=='o' && arr[2][1]==' ')
        {
            arr[2][1]='x';
            break;
        }
        if(arr[2][0]=='o' && arr[2][1]=='o' && arr[2][1]==' ')
        {
            arr[2][1]='x';
            break;
        }
    cpu();
    break;
    }while(loop==1);
}

void triscpu()
{
    do
    {
        //blocchi su 00
        if(arr[0][1]=='x' && arr[0][2]=='x' && arr[0][0]==' ')
        {
            arr[0][0]='x';
            break;
        }
        if(arr[1][1]=='x' && arr[2][2]=='x' && arr[0][0]==' ')
        {
            arr[0][0]='x';
            break;
        }
        if(arr[1][0]=='x' && arr[2][0]=='x' && arr[0][0]==' ')
        {
            arr[0][0]='x';
            break;
        }
        //blocchi su 01
        if(arr[0][1]=='x' && arr[0][2]=='x' && arr[0][1]==' ')
        {
            arr[0][1]='x';
            break;
        }
        if(arr[1][1]=='x' && arr[2][1]=='x' && arr[0][1]==' ')
        {
            arr[0][1]='x';
            break;
        }
        //blocchi su 02
        if(arr[0][0]=='x' && arr[0][1]=='x' && arr[0][2]==' ')
        {
            arr[0][2]='x';
            break;
        }
        if(arr[1][1]=='x' && arr[2][0]=='x' && arr[0][2]==' ')
        {
            arr[0][2]='x';
            break;
        }
        if(arr[1][2]=='x' && arr[2][2]=='x' && arr[0][2]==' ')
        {
            arr[0][2]='x';
            break;
        }
        //blocchi su 10
        if(arr[0][0]=='x' && arr[2][0]=='x' && arr[1][0]==' ')
        {
            arr[1][0]='x';
            break;
        }
        if(arr[1][1]=='x' && arr[1][2]=='x' && arr[1][0]==' ')
        {
            arr[1][0]='x';
            break;
        }
        //blocchi su 11
        if(arr[1][0]=='x' && arr[1][2]=='x' && arr[1][1]==' ')
        {
            arr[1][1]='x';
            break;
        }
        if(arr[0][1]=='x' && arr[2][1]=='x' && arr[1][1]==' ')
        {
            arr[1][1]='x';
            break;
        }
        if(arr[0][0]=='x' && arr[2][2]=='x' && arr[1][1]==' ')
        {
            arr[1][1]='x';
            break;
        }
        if(arr[0][2]=='x' && arr[2][0]=='x' && arr[1][1]==' ')
        {
            arr[1][1]='x';
            break;
        }
        //blocchi su 12
        if(arr[1][0]=='x' && arr[1][1]=='x' && arr[1][2]==' ')
        {
            arr[1][2]='x';
            break;
        }
        if(arr[0][2]=='x' && arr[2][2]=='x' && arr[1][2]==' ')
        {
            arr[1][2]='x';
            break;
        }
        //blocchi su 20
        if(arr[0][0]=='x' && arr[1][0]=='x' && arr[2][0]==' ')
        {
            arr[2][0]='x';
            break;
        }
        if(arr[1][1]=='x' && arr[0][2]=='x' && arr[2][0]==' ')
        {
            arr[2][0]='x';
            break;
        }
        if(arr[2][1]=='x' && arr[2][2]=='x' && arr[2][0]==' ')
        {
            arr[2][0]='x';
            break;
        }
        //blocchi su 21
        if(arr[0][1]=='x' && arr[1][1]=='x' && arr[2][1]==' ')
        {
            arr[2][1]='x';
            break;
        }
        if(arr[2][0]=='x' && arr[2][2]=='x' && arr[2][1]==' ')
        {
            arr[2][1]='x';
            break;
        }
        //blocchi su 22
        if(arr[0][2]=='x' && arr[1][2]=='x' && arr[2][2]==' ')
        {
            arr[2][2]='x';
            break;
        }
        if(arr[0][0]=='x' && arr[1][1]=='x' && arr[2][1]==' ')
        {
            arr[2][1]='x';
            break;
        }
        if(arr[2][0]=='x' && arr[2][1]=='x' && arr[2][1]==' ')
        {
            arr[2][1]='x';
            break;
        }
    cpu();
    break;
    }while(loop==1);
}

//gioco del tris
int main() 
{
    //caricamento array
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j]=' ';
        }
    }

    //primo turno: la cpu posiziona la x al centro
    arr[1][1]='x';

    //secondo turno: il giocatore inserisce la o
    giocatore();

    //terzo turno: la cpu controlla se gli angoli sono liberi, in caso inserisce la x
    do
    {
        if(arr[0][0]==' ')
        {
            arr[0][0]='x';
            break;
        }
        if(arr[0][2]==' ')
        {
            arr[0][2]='x';
            break;
        }
        break;
    }while (loop==1);

    //quarto turno: il giocatore inserisce la o
    giocatore();
    
    //quinto turno: la cpu blocca una possibile vittoria del giocare, in caso contrario, inserisce la x
    triscpu();
    blocco();
    vittoriax();

    //sesto turno: il giocatore inserisce la o
    giocatore();
    vittoriao();

    //settimo turno: la cpu inserisce una x
    triscpu();
    blocco();
    vittoriax();

    //ottavo turno: il giocatore inserisce la o
    giocatore();
    vittoriao();

    //nono turno: la cpu inserisce la x
    triscpu();
    blocco();
    vittoriax();
}
