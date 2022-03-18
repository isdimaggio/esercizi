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
;Caricare un vettore di N elementi ad una cifra
;con N<=20, permetta di sommarli tra loro e quindi 
;di farne la media e visualizzare il vettore al contrario

DATA SEGMENT
    DIMENSIONE  DB ?
    DIECI       DB 10
    VET         DB 20 DUP(0)
    SOMMA       DB 0
    MEDIA       DB 0 
    MSG1        DB 13, 10, 'Inserisci la dimensione del vettore: $'
    MSG2        DB 13, 10, 'vettore[$'
    MSG2PT2     DB         ']: $'
    MSG5        DB 13, 10, 'Vettore troppo grande! $'    
    MSG3        DB 13, 10, '--- Stampa al contrario ---$'
    MSG4        DB 13, 10, 'Somma: $'
    MSG6        DB 13, 10, 'Media: $'
    MSG7        DB 13, 10, 'Resto media: $' 
DATA ENDS
CODE SEGMENT
ASSUME  CS:CODE, DS:DATA
START:  MOV AX, DATA
        MOV DS, AX
        JMP SKIPMS              ; salta il messaggio di dimensione eccessiva
        
        ;############# Input della dimensione del vettore #############  
        ;----- Output messaggi -----
CHECK1: LEA DX, MSG5            ; messaggio dimensioni eccessive...       
        MOV AH, 9               ; ... mostrato solo se chiamato dal check
        INT 21H

SKIPMS: LEA DX, MSG1            ; inizio del programma con richiesta ...
        MOV AH, 9               ; ... dimensione vettore
        INT 21H
        
        ;----- Prima cifra della dimensione -----
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MUL DIECI
        MOV DIMENSIONE, AL
        ;----- Seconda cifra della dimensione -----
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        ADD DIMENSIONE, AL
          
        ;----- Verifica dimensioni vettore -----
        CMP DIMENSIONE, 20      ; se il vettore è troppo grande...
        JA CHECK1               ; ... chiedi di inserirlo di nuovo

        ;############# Caricamento del vettore #############
        ;----- Inizializzazione indici ------
        MOV CX, 0
        MOV CL, DIMENSIONE
        MOV SI, 0
        ;----- Parte iniziale messaggio ------
ALOAD:  LEA DX, MSG2
        MOV AH, 9
        INT 21H
        
        ;----- Output prima cifra posizione vettore ------  
        MOV AX, SI              ; carico posizione (16 bit, usiamo solo 8)
        DIV DIECI               ; RESTO in (A/B)H e QUOZIENTE in (A/B)L                     
        MOV BX, AX              ; salviamo tutti i valori che riutilizzeremo dopo
        MOV DL, AL              
        ADD DL, 30H             
        MOV AH, 2
        INT 21H
        ;----- Output seconda cifra posizione vettore ------
        MOV DL, BH              
        ADD DL, 30H             
        MOV AH, 2
        INT 21H 
        
        ;----- Parte finale messaggio ------
        LEA DX, MSG2PT2
        MOV AH, 9
        INT 21H
        
        ;----- Caricamento effettivo -----
        MOV AH, 1
        INT 21H
        SUB AL, 30H
        MOV [VET+SI], AL
          
        ;----- Somma e ciclo -----
        ADD SOMMA, AL 
        INC SI
        LOOP ALOAD 
        
        ;############# Output della somma #############
        LEA DX, MSG4
        MOV AH, 9
        INT 21H
        
        ;----- Prima cifra ------  
        MOV AL, SOMMA           ; carico posizione (16 bit, usiamo solo 8)
        MOV AH, 0               
        MOV DX, 0               ; aazzeriamo DX per bug divisione
        DIV DIECI               ; RESTO in (A/B)H e QUOZIENTE in (A/B)L                                
        MOV BX, AX              ; salviamo tutti i valori che riutilizzeremo dopo
        MOV DL, AL              
        ADD DL, 30H             
        MOV AH, 2
        INT 21H
        ;----- Seconda cifra ------
        MOV DL, BH              
        ADD DL, 30H             
        MOV AH, 2
        INT 21H
        
        ;############# Calcolo della media ############# 
        MOV AX, 0
        MOV AL, SOMMA
        MOV BL, DIMENSIONE
        ADD BL, 1
        DIV BL
        MOV MEDIA, AL
        
        ;############# Output della media #############
        ;----- Messaggio media ------
        LEA DX, MSG6
        MOV AH, 9
        INT 21H
        
        ;----- Media ------
        MOV DL, MEDIA
        ADD DL, 30H 
        MOV AH, 2
        INT 21H
                
        ;############# Stampa del vettore al contrario #############
        ;----- Inizializzazione indici ------
        MOV CX, 0
        MOV BX, 0
        MOV CL, DIMENSIONE
        ADD CL, 1               ; per far arrivare il conteggio fino a 0
        MOV BL, DIMENSIONE      ; carico in bh per usare l'intero registro
        MOV SI, BX              ; siccome SI è un registro a 16 bit
        
        ;----- Parte iniziale messaggio di stampa ------
APRINT: LEA DX, MSG2
        MOV AH, 9
        INT 21H
        
        ;----- Prima cifra posizione vettore ------  
        MOV AX, SI              ; carico posizione (16 bit, usiamo solo 8)
        MOV DX, 0               ; aazzeriamo DX per bug divisione
        DIV DIECI               ; RESTO in (A/B)H e QUOZIENTE in (A/B)L                     
        MOV BX, AX              ; salviamo tutti i valori che riutilizzeremo dopo
        MOV DL, AL              
        ADD DL, 30H             
        MOV AH, 2
        INT 21H
        ;----- Seconda cifra posizione vettore ------
        MOV DL, BH              
        ADD DL, 30H             
        MOV AH, 2
        INT 21H 
        
        ;----- Seconda parte messaggio di stampa ------
        LEA DX, MSG2PT2
        MOV AH, 9
        INT 21H
        
        ;----- Stampa valore -----
        MOV DL, [VET+SI]              
        ADD DL, 30H             
        MOV AH, 2
        INT 21H
          
        ;----- Ciclo -----
        DEC SI
        LOOP APRINT      
          
        ;############# Fine del programma #############
        MOV AH, 4CH
        INT 21H
CODE ENDS
END START