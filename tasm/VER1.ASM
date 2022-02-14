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
;Implementare un programma in linguaggio assembly che effettui la somma tra
;due valori dati in input. (14-02-2022)
TITLE Esercizio verifica n.1
DATA SEGMENT
    NUM1 DB ?
    NUM2 DB ?
    RISU DB ?
    MSG1 DB 13,10,'Inserisci il primo numero: $'
    MSG2 DB 13,10,'Inserisci il secondo numero: $'
    MSG3 DB 13,10,'Risultato: $'
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
        ; --- INPUT NUM1 ---
        MOV AH, 1           ; servizio input
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV NUM1, AL        ; memorizziamo num1
        ; --- OUTPUT MSG2 ---
        LEA DX, MSG2
        MOV AH, 9
        INT 21H
        ; --- INPUT NUM2 ---
        MOV AH, 1           ; servizio input
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV NUM2, AL        ; memorizziamo num2
        ; --- SOMMA ---
        MOV AH, NUM1        ; recuperiamo num1 e carichiamolo in AH
        ADD AL, AH          ; somma
        ; --- OUTPUT MSG3 ---
        LEA DX, MSG3
        MOV AH, 9
        INT 21H
        ; --- OUTPUT RIS ---
        MOV DL, AL          ; spostiamo nel registro output
        ADD DL, 30H         ; numero -> ascii
        MOV AH, 2
        INT 21H
        ; --- FINE PROG ---
        MOV AH, 4CH
        INT 21H
CODE ENDS
END start
