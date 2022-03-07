;Copyright 2021 Lo Mele Vittorio
;
;Licensed under the Apache License, Version 2.0 (the "License");
;you may not use this file except in compliance with the License.
;You may obtain a copy of the License at
;
;    http://www.apache.org/licenses/LICENSE-2.0
;
;Unless required by applicable law or agreed to in writing, software
;distributed under the License is distributed on an "AS IS" BASIS,
;WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;See the License for the specific language governing permissions and
;limitations under the License.
;-------------------------------------------------------------------------
;Caricare un vettore di N elementi ad una cifra
;con N<=20, permetta di sommarli tra loro e quindi 
;di farne la media e visualizzare il vettore al contrario

TITLE esercitazione vettori 3
DATA SEGMENT
    N DB 0        ;Valore del vettore
    DIECI DB 10
    VET DB 20 DUP(0)
    SOMMA DB 0
    MEDIA DB 0 
    MSG1 DB 13,10,'dimensioni vettore: $'
    MSG2 DB 13,10,'inserisci elemento: $'
    MSG3 DB 13,10,'elemento contenuto: $'
    MSG4 DB 13,10,'visualizza vettore: $'
    MSG5 DB 13,10,'valore d controllo: $'
DATA ENDS
CODE SEGMENT
ASSUME  CS:CODE, DS:DATA
START:  MOV AX, DATA
        MOV DS, AX
        
        ;############# Input della dimensione del vettore #############
ARRAY:  LEA DX, MSG1
        MOV AH, 9
        INT 21H
        ;----- Prima cifra di N -----
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MUL DIECI
        MOV N, AL
        ;----- Seconda cifra di N -----
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        ADD N, AL  
        
        ;############# Verifica delle dimensioni del vettore #############
        CMP N, 20
        JA ARRAY
        LEA DX, MSG5
        MOV AH, 9
        INT 21H   
        ;----- Modifica degli indici -----
        MOV CL, N
        MOV CH, 0
        MOV SI, 0

        ;############# Contatore #############
        ;----- Messaggio di caricamento ------
ALOAD:  LEA DX, MSG2
        MOV AH, 9
        INT 21H
        ;----- Caricamento -----
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV [VET+SI], AL  
        ;----- Somma e conteggio -----
        ADD SOMMA, AL 
        ;----- Ciclo ------
        INC SI : SI = SI+1
        LOOP ALOAD
        ;
        ;
        ; DA FINIRE
        ;
        ;

CODE ENDS
END START