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

TITLE esercizio con ciclo
DATA SEGMENT
    DIECI DB 10
	DUE DB 2
	QUOZ DB 0
	RESTO DB 0
	VET DB 20 DUP(0)
    MSG1 DB 13,10,'inserisci numero: $'
    MSG2 DB 13,10,'numero pari: $'
    MSG3 DB 13,10,'numero dispari: $'
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
Start:  MOV AX, DATA
        MOV DS, AX
		; programma
		MOV CX, 20			; INIT CICLO LOOP
		MOV SI, 0
Ciclo:	LEA DX, MES1
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
		INC SI : SI = SI+1
		LOOP Ciclo
		MOV CX, 20
		MOV SI, 0
Ciclo1:	MOV AL, [VET+SI]
		MOV AH, 0
		DIV DUE
		MOV RESTO, AH
		CMP RESTO, 1
		JE Dispari
Pari:	LEA DX, MES2
		MOV AH, 9
		INT 21H
		MOV AL, [VET+SI]
		MOV AH, 0
		DIV DIECI
		MOV QUOZ, AL
		MOV RESTO, AH
		MOV AH, 2
		MOV DL, QUOZ
		INT 21H
		ADD RESTO, 30H
		MOV AH, 2
		MOV DL, RESTO
		INT 21H
		JMP Fine
Dispari:LEA DX, MES3
		MOV AH, 9
		INT 21H
		MOV AL, [VET+SI]
		MOV AH, 0
		DIV DIECI
		MOV QUOZ, AL
		MOV RESTO, AH
		MOV AH, 2
		MOV DL, QUOZ
		INT 21H
		ADD RESTO, 30H
		MOV AH, 2
		MOV DL, RESTO
		INT 21H	
Fine: 	INC SI
		; fine programma ritorno al DOS
        MOV AH, 4CH
        INT 21H
CODE ENDS
END Start