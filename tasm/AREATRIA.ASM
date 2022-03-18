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

TITLE calcolo area triangolo
DATA SEGMENT
    BASE DB 7
    ALTEZZA DB 4
    AREA DB ?
DATA ENDS
CODE SEGMENT   
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX
        MOV AH, 0
		MOV AL, BASE
        MUL ALTEZZA
        MOV BL, 2 
        DIV BL
		MOV AH, 4CH
		INT 21H
CODE ENDS
END start