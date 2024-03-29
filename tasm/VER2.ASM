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
;Implementare un programma in assembly che permetta di calcolare il cubo
;di una variabile di nome CUBO fornita in input. Il valore del risultato
;deve essere memorizzato nella variabile RIS. (14-02-2022)
TITLE Esercizio verifica n.2
DATA SEGMENT
    CUBO DB ?
    RISU DB ?
    MSG1 DB 13,10,'Inserisci il lato: $'
    MSG2 DB 13,10,'Risultato: $'
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX
        ; inizio programma
        ; --- OUTPUT MSG1 ---
        LEA DX, MSG1
        MOV AH, 9
        INT 21H
        ; --- INPUT CUBO ---
        MOV AH, 1           ; servizio input
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV CUBO, AL        ; memorizziamo num1
        ; --- CALC CUBO ---
        MOV BL, AL          ; copia in BL del lato
        MUL BL              ; quadrato
        MUL BL              ; cubo
        ; --- OUTPUT MSG2 ---
        LEA DX, MSG2
        MOV AH, 9
        INT 21H
        ; --- OUTPUT RIS ---
        MOV DL, AL          ; carichiamo per visualizzazione
        ADD DL, 30H         ; numero -> ascii
        MOV AH, 2
        INT 21H
        ; --- FINE PROG ---
        MOV AH, 4CH
        INT 21H
CODE ENDS
END start
