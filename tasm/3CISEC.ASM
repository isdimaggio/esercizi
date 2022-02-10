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

TITLE programma per calcolare l'area del triangolo dato in input base ed altezza
DATA SEGMENT
   BASE      DB 0
   ALTEZZA   DB 0
   RISULTATO DB ?
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX
        MOV AX, 0       ; puliamo il registro AX
                        ; inizio programma vero e proprio
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV BASE, AL
                        ; input altezza
        MOV AH, 1
        INT 21H
        SUB AL, 30H

        MOV ALTEZZA, AL
        MUL BASE        ; moltiplichiamo base per altezza (in al)
        MOV CL, 2
        DIV CL
        MOV RISULTATO, AL
                        ; fase di output
        MOV DX, 0       ; azzeriamo dx per sicurezza
        MOV DL, AL
        ADD DL, 30H
        MOV AH, 2
        INT 21H
                        ; ritorno al dos
        MOV AH, 4CH
        INT 21H
CODE ENDS
END start


