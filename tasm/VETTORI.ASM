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
;realizzare un programma che permetta di leggere
;20 numeri a due cifre visualizzando anche i numeri
;pari e i numeri dispari

TITLE esercitazione vettori
DATA SEGMENT
        VET DB 20 DUP(0)
        DIECI DB 10
        QUOZ DB 0
        RESTO DB 0
        DUE DB 2
        MES1 DB 13,10,'inserire il numero: $'
        MES2 DB 13,10,'numero pari: $'
        MES3 DB 13,10,'numero dispari: $'
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
inizio: MOV AX, DATA
        MOV DS, AX
        ; inizio programma vero e proprio
        MOV CX, 20 ; inizializzazione ciclo LOOP
        MOV SI, 0
ciclo:  LEA DX, MES1
        MOV AH, 9
        INT 21H
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MUL DIECI
        MOV [VET+SI], AL
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        ADD [VET+SI], AL
        INC SI ; SI=SI+1
        LOOP ciclo
        MOV CX, 20
        MOV SI, 0
ciclo1: MOV AL, [VET+SI]
        MOV AH, 0
        DIV DUE
        MOV RESTO, AH
        CMP RESTO, 1
        JE dispari
        LEA DX, MES2
        MOV AH, 9
        INT 21H
        MOV AL, [VET+SI]
        MOV AH, 0
        DIV DIECI
        MOV QUOZ, AL
        MOV RESTO, AH
        ADD QUOZ, 30H
        MOV AH, 2
        MOV DL, QUOZ
        INT 21H
        ADD RESTO, 30H
        MOV AH, 2
        MOV DL, RESTO
        INT 21H
        JMP fine
dispari:LEA DX, MES3
        MOV AH, 9
        INT 21H
        MOV AL, [VET+SI]
        MOV AH, 0
        DIV DIECI
        MOV QUOZ, AL
        MOV RESTO, AH
        ADD QUOZ, 30H
        MOV AH, 2
        MOV DL, QUOZ
        INT 21H
        ADD RESTO, 30H
        MOV AH, 2
        MOV DL, RESTO
        INT 21H
fine:   INC SI
        LOOP ciclo1
        MOV AH, 4CH
        INT 21H
        CODE ENDS
END inizio
