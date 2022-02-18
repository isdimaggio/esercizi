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
;Implementare un programma in assembly che, a partire dalle variabili
;A,B,C,D fornite in input permetta di calcolare l'espressione (A-B)/(C+D)
;e permetta anche la visualizzazione del quoziente e resto (14-02-2022)

TITLE Esercizio verifica n3
DATA SEGMENT
    NUMA DB ?
    NUMB DB ?
    NUMC DB ?
    NUMD DB ?
    RISU DB ?
    QUOZ DB ?
    MSGA DB 13,10,'Inserire la variabile A: $'
    MSGB DB 13,10,'Inserire la variabile B: $'
    MSGC DB 13,10,'Inserire la variabile C: $'
    MSGD DB 13,10,'Inserire la varaibile D: $'
    MSGR DB 13,10,'Risultato espressione: $'
    MSGQ DB 13,10,'Quoziente espressione: $'
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX

        ; --- Output MSGA ---
        LEA DX, MSGA
        MOV AH, 9
        INT 21H

        ; --- Input NUMA ---
        ; Prima cifra NUMA
        MOV AH, 1
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV AH, 0
        MOV BL, 10          ; costante moltiplicazione
        MUL BL              ; moltiplichiamo prima cifra x10
        MOV BL, AL          ; memorizziamo la prima cifra
        MOV AX, 0
        ; Seconda cifra NUMA
        MOV AH, 1
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV AH, 0
        ADD AL, BL          ; somma cifra appena acquisita insieme alla precedente
        MOV NUMA, AL        ; memorizziamo

        
        ; --- Output MSGB ---
        LEA DX, MSGB
        MOV AH, 9
        INT 21H
        
        ; --- Input NUMB ---
        ; Prima cifra NUMB
        MOV AH, 1
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV AH, 0
        MOV BL, 10          ; costante moltiplicazione
        MUL BL              ; moltiplichiamo prima cifra x10
        MOV BL, AL          ; memorizziamo la prima cifra
        MOV AX, 0
        ; Seconda cifra NUMB
        MOV AH, 1
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV AH, 0
        ADD AL, BL          ; somma cifra appena acquisita insieme alla precedente
        MOV NUMB, AL        ; memorizziamo

        
        ; --- Output MSGC ---
        LEA DX, MSGC
        MOV AH, 9
        INT 21H
        
        ; --- Input NUMC ---
        ; Prima cifra NUMC
        MOV AH, 1
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV AH, 0
        MOV BL, 10          ; costante moltiplicazione
        MUL BL              ; moltiplichiamo prima cifra x10
        MOV BL, AL          ; memorizziamo la prima cifra
        MOV AX, 0
        ; Seconda cifra NUMC
        MOV AH, 1
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV AH, 0
        ADD AL, BL          ; somma cifra appena acquisita insieme alla precedente
        MOV NUMC, AL        ; memorizziamo
    
        ; --- Output MSGD ---
        LEA DX, MSGD
        MOV AH, 9
        INT 21H
        
        ; --- Input NUMD ---
        ; Prima cifra NUMD
        MOV AH, 1
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV AH, 0
        MOV BL, 10          ; costante moltiplicazione
        MUL BL              ; moltiplichiamo prima cifra x10
        MOV BL, AL          ; memorizziamo la prima cifra
        MOV AX, 0
        ; Seconda cifra NUMD
        MOV AH, 1
        INT 21H
        SUB AL, 30H         ; ascii -> numero
        MOV AH, 0
        ADD AL, BL          ; somma cifra appena acquisita insieme alla precedente
        MOV NUMD, AL        ; memorizziamo

        MOV AX, 0           ; ripuliamo i registri
        MOV BX, 0           ; per i calcoli

        ; --- CALCOLI ---
        ; prima parte
        MOV AL, NUMA        ; carico A
        SUB AL, NUMB        ; sottrazione
        MOV BL, AL          ; memorizziamo prima parte
        MOV AL, NUMC        ; carico C
        ADD AL, NUMD        ; addizione
        MOV BH, AL          ; memorizziamo seconda parte
        MOV AL, BL          ; ricarico prima parte
        MOV DX, 0           ; azzeriamo DX per bug divisione
        MOV AH, 0           ; azzeriamo AH
        ; RESTO CALCOLI IN AH E QUOZIENTE CALCOLI AL
        DIV BH              ; dividiamo per seconda parte
        
        ; --- SALVATAGGIO CALOLI ---
        MOV RISU, AL
        MOV QUOZ, AH

        ; --- Output MSGR ---
        LEA DX, MSGR
        MOV AH, 9
        INT 21H

        ; --- OUTPUT PRIMA CIFRA RIS --- 
        ; in AL già presente risultato  
        MOV AL, RISU        ; carico risultato
        MOV BL, 10          ; costante divisione
        MOV AH, 0
        MOV DX, 0           ; aazzeriamo DX per bug divisione
        DIV BL              ; dividiamo per separare le due cifre
        ; RESTO in (A/B)H e QUOZIENTE in (A/B)L
        MOV BX, AX          ; salviamo tutti i valori che riutilizzeremo dopo
        MOV DL, AL          ; caricando cifra piu significativa in registro di stampa
        ADD DL, 30H         ; numero -> ascii
        MOV AH, 2
        INT 21H

        ; --- SECONDA CIFRA RIS ---
        MOV DL, BH          ; caricando cifra meno significativa
        ADD DL, 30H         ; convertendo in ASCII la cifra piu significativa
        MOV AH, 2
        INT 21H

        ; --- Output MSGQ ---
        LEA DX, MSGQ
        MOV AH, 9
        INT 21H

        ; --- Quoziente espressione ---
        MOV DL, QUOZ
        ADD DL, 30H 
        MOV AH, 2
        INT 21H

        ; --- FINE PROG ---
        MOV AH, 4CH
        INT 21H
CODE ENDS
END Start