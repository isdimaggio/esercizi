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

;programma che effettua la moltiplicazione
;di due costanti
DATA SEGMENT
    NUM1 DB 3
    NUM2 DB 5
	NUM3 DB 4
    RIS DB ?
DATA ENDS
CODE SEGMENT   
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX
        MOV AH, 0
		; inizio programma
		MOV AL, NUM1
		ADD AL, NUM2
		MUL NUM3
		MOV RIS, AL        
        ; fine programma ritorno al DOS
MOV AH, 4CH
INT 21H
CODE ENDS
END start