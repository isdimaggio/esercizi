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

TITLE programma che calcola l'espressione : (A*B+C)/2
DATA SEGMENT
    A DB ?
    B DB ?
    C DB ?
    RIS DB ?
DATA ENDS
CODE SEGMENT   
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX
        MOV AH, 0
		; inizio del programma
		; input di A
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV A, AL
		; input di B
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV B, AL
		; input di C
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV C, AL
		; calcolo espressione
        MOV AL, A
        MUL B
        ADD AL, C
        MOV BL, 2 
        DIV BL
        MOV RIS, AL
		; output
        MOV DL, RIS
        ADD DL, 30H
        MOV AH, 2
        INT 21H
		; fine programma ritorno al DOS
        MOV AH, 4CH
        INT 21H
CODE ENDS
END start