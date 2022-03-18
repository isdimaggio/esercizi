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
;caricare un vettore di N elementi (N<=20) a due cifre
;che conti quante volte un numero fornito in input 
;sia contenuto in esso

TITLE esercitazione vettori 2
DATA SEGMENT
    NUM DB ?
    N DB ?          ;Dimensione del vettore
    VOLTE DB ?

    VET DB 20 DUP(0)
    MSG1 DB 13,10,'Dimensione del vettore:  $'
    MSG2 DB 13,10,'Inserisci elemento:  $'
    MSG3 DB 13,10,'Elemento contenuto $' 
    MSG4 DB 13,10,' volte  $'
    MSG5 DB 13,10,'Valore da controllare:  $'
    MSG6 DB 13,10,'VISUALIZZAZIONE VETTORE INSERITO:  $'
    DIECI DB 10
DATA ENDS
CODE SEGMENT
ASSUME  CS:CODE, DS:DATA
Inizio: MOV AX, DATA
        MOV DS, AX    
        ;Inizio programma ver e proprio
        ;Input della dimensione del vettore
Rip:    LEA DX, MSG1
        MOV AH, 9
        INT 21H
        ;Input prima cifra di N
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MUL DIECI
        MOV N, AL   
        ;Input seconda cifra di N  
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        ADD N, AL 
        ;Controllo
        CMP N, 20 
        JA Rip      ;Jump if above  
        LEA DX, MSG5
        MOV AH, 9
        INT 21H
        ;Input numero da controllare
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV NUM, AL
        ;Inizializzazione degli indici
        MOV CL, N
        MOV CH, 0
        MOV SI, 0
        MOV BL, 0   ;Contatore
Carica: LEA DX, MSG2
        MOV AH, 9
        INT 21H
        ;Caricamento degli elementi nel vettore
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV [VET+SI], AL
        ;Controllo se NUM e' contenuto in VET
        CMP NUM, AL     ;Contiene ancora il valore del vettore
        JE  Count
        JMP Count1
        ;Conteggio
Count:  INC BL          ;Incremento di BL(BL++)
        MOV VOLTE, BL
Count1: INC SI
        LOOP Carica
        ;Output del vettore
        LEA DX, MSG6
        MOV AH, 9
        INT 21H
        ;Inizializzazione indici   
        MOV CL, N
        MOV CH, 0
        MOV SI, 0
Ciclo1: MOV DL, 13      ;Torna a capo
        MOV AH, 2         
        INT 21H
        MOV DL, 10      ;Inizio dalla prima colonna
        MOV AH, 2
        INT 21H
        MOV DL, [VET+SI];Inizio output
        ADD DL, 30H
        MOV AH, 2
        INT 21H
        INC SI
        LOOP Ciclo1     ;Fine output
        ;Output di VOLTE
        LEA DX, MSG3
        MOV AH, 9
        INT 21H
        MOV DL, VOLTE
        ADD DL, 30H
        MOV AH, 2
        INT 21H
        ;Visualizzazione di MSG4
        LEA DX, MSG4
        MOV AH, 9
        INT 21H
        ;Fine programma e ritorno al DOS
        MOV AH, 4CH
        INT 21H
CODE ENDS
END Inizio