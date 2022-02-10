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

;programma che effettua la somma e differenza
;di due costanti
DATA SEGMENT
    NUM1 DB 10 ; db define byte,  dw define word per piu di 255
    NUM2 DB 4
    SOMM DB ?
    DIFF DB ?  ; punto interrogativo perch? non so il valore
DATA ENDS
CODE SEGMENT   
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX
        ; inizio programma
        MOV AX,   0
        MOV AL,   NUM1
        ADD AL,   NUM2
        MOV SOMM, AL
        MOV AL,   NUM1
        MOV BL,   NUM2
        SUB AL,   BL
        MOV DIFF, AL
        ; fine programma ritorno al DOS
MOV AH, 4CH
INT 21H
CODE ENDS
END start
; da 113 a 129
