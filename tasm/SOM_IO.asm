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

TITLE somma di due variabili con I/O
DATA SEGMENT
    N1 DB 7
    N2 DB 4
    SO DB ?
DATA ENDS
CODE SEGMENT   
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX
        ; inizio
        ; input di n1
        MOV AH, 1       ; chiamata interrupt
        INT 21H         ; chiamata interrupt
        SUB AL, 30H     ; sottraendo 30 pos per prelevare la cifra
        MOV N1, AL      ; spostiamo la cifra ottenuta nella memoria
        ; input di n2
        MOV AH, 1       ; chiamata interrupt
        INT 21H         ; chiamata interrupt
        SUB AL, 30H     ; sottraendo 30 pos per prelevare la cifra
        MOV N2, AL      ; spostiamo la cifra ottenuta nella memoria
        ; somma
        ADD AL, N1      ; somma tra n1 e quello appena scritto
        MOV SOM, AL     ; memorizziamo la somma
        ; output
        MOV DL, SOM     ; spostando somma nel registro dell'output
        ADD DL, 30H     ; aggiungiamo 30 posizioni per la tabella ascii
        MOV AH, 2       ; carichiamo in ah l'interrupt 2
        INT 21H         ; interrupt
        ; ritorno al DOS
		MOV AH, 4CH
		INT 21H
CODE ENDS
END start