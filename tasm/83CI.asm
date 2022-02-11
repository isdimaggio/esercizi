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

TITLE somma tra due valori a due cifre (con messaggi)
DATA SEGMENT
    NUM1 DB ?
    NUM2 DB ?
    SOM DB ?
    MSG1 DB 13,10,'Inserire il primo numero: ,$'
    MSG2 DB 13,10,'Inserire il secondo numero: ,$'
    MSG3 DB 13,10,'La somma è: ,$'
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
Start:  MOV AX, DATA
        MOV DS, AX
        ; ////// output MSG1 //////
        LEA DX, MSG1
        MOV AH, 9
        INT 21H
        ; ////// Input di NUM1 //////
        ; prima cifra num1
        MOV AH, 1
        INT 21H
        SUB AL, 30H ; convertiamo da ASCII a numero reale
        MOV AH, 0 ; ripuliamo AH
        MOV BL, 10 ; costante moltiplicazione per prima cifra
        MUL BL ; moltiplichiamo prima cifra x10
        MOV BL, AL ; memorizziamo la prima cifra
        MOV AX, 0 ; ripiuliamo il registro per sicurezza
        ; seconda cifra num1
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV AH, 0 ; ripuliamo AH
        ADD AL, BL ; sommiamo il valore reale della prima cifra alla seconda appena acquisita
        MOV VAL1, AL ; memorizziamo
        ; ////// output di MSG2 //////
        LEA DX, MSG2
        MOV AH, 9
        INT 21H
        ; ////// Input di  NUM2 //////
        ; prima cifra num1
        MOV AH, 1
        INT 21H
        SUB AL, 30H ; convertiamo da ASCII a numero reale
        MOV AH, 0 ; ripuliamo AH
        MOV BL, 10 ; costante moltiplicazione per prima cifra
        MUL BL ; moltiplichiamo prima cifra x10
        MOV BL, AL ; memorizziamo la prima cifra
        MOV AX, 0 ; ripiuliamo il registro per sicurezza
        ; seconda cifra num1
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV AH, 0 ; ripuliamo AH
        ADD AL, BL ; sommiamo il valore reale della prima cifra alla seconda appena acquisita
        MOV VAL2, AL ; memorizziamo
        ; ////// Addizione dei due valori appena memorizzati //////
        MOV BL, VAL1 ; carichiamo in BL il valore 1
        ADD AL, BL ; sommiamo il valore precedente caricato con quello del secondo addendo
                   ; già presente in AL
        MOV SOM, AL ; carichiamo in SOM la somma dei due valori appena calcolata
        ; ////// output di MSG3 //////
        LEA DX, MSG3
        MOV AH, 9
        INT 21H
        ; ////// output del valore sommato //////
        MOV BL, 10 ; costante divisione
        MOV AH, 0
        MOV DX, 0 ; azzeriamo registro DX altrimenti la div non funziona
        DIV BL ; dividiamo per separare le due cifre
        ; RESTO in (A)H e QUOZIENTE in (A)L
        MOV BX, AX ; salviamo tutti i valori che riutilizzeremo dopo
        MOV DL, AL ; caricando cifra piu significativa in registro di stampa
        ADD DL, 30H ; convertendo in ASCII la cifra piu significativa
        MOV AH, 2
        INT 21H
        ; prima cifra stampata, stampare la seconda
        MOV DL, BH ; caricando cifra meno significativa
        ADD DL, 30H ; convertendo in ASCII la cifra piu significativa
        MOV AH, 2
        INT 21H
        ; fine programma ritorno al DOS
        MOV AH, 4CH
        INT 21H
CODE ENDS
END Start