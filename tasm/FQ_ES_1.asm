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

; somma tra due costanti (3 e 5)
DATA SEGMENT
    CT1 DB 3
    CT2 DB 5
    RIS DB ?
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
start:  MOV AX, DATA
        MOV DS, AX
        MOV AH, 0
        ;start
        MOV AL, CT1
        ADD AL, CT2
        MOV RIS, AL
        ;end
        MOV AH, 4CH
        INT 21H
CODE ENDS
END start
