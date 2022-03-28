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
;--------------------------------------------------------------------
; Vittorio Lo Mele 3Ci - Traccia B Esercizio 2 

data segment
    dieci       db 10
    v1          db 13 dup(0)
    v2          db 13 dup(0)    
    n           db ? ; dimensione del vettore 
    risu        db ? ; risultato punto 3
    msg1        db 13, 10, 'Inserisci dimensione vettore: $'
    msg2        db 13, 10, 'Carica nel primo vettore: $'
    msg3        db 13, 10, 'Carica nel secondo vettore: $'  
    msg4        db 13, 10, 'Visualizza il primo vettore: $'
    msg5        db 13, 10, 'Visualizza il secondo vettore: $'  
    msg6        db 13, 10, 'Risultato: $' 
data ends
code segment
assume cs:code ds:data
start:      mov ax, data
            mov ds, ax  
            
            ; messaggio dimensione vettore
inputdim:   lea dx, msg1            
            mov ah, 9               
            int 21h
            
            ;input due cifre dimensione vettore
            mov ah, 1
            int 21h
            sub al, 30h
            mul dieci
            mov n, al 
            mov ah, 1
            int 21h
            sub al, 30h
            add n, al
            
            ; controllo validita dimensione    
            cmp n, 13     
            ja inputdim 
                        
            ; reset indici
            mov cx, 0
            mov cl, n
            mov si, 0
                          
            ; messaggio primo vettore
carica:     lea dx, msg2
            mov ah, 9
            int 21h 
               
            ; input a 2 cifre primo vettore                                           
            mov ah, 1
            int 21h
            sub al, 30h
            mul dieci
            mov bl, al 
            mov ah, 1
            int 21h
            sub al, 30h
            add bl, al                                              
                                                          
            mov [v1+si], bl                                             
            
            ; messaggio secondo vettore
            lea dx, msg3
            mov ah, 9
            int 21h 
               
            ; input a 2 cifre secondo vettore                                           
            mov ah, 1
            int 21h
            sub al, 30h
            mul dieci
            mov bl, al 
            mov ah, 1
            int 21h
            sub al, 30h
            add bl, al                                              
                                                          
            mov [v2+si], bl 
            
            ; somma elementi
            mov al, [v1+si]
            add al, [v2+si]  
            
            cmp cl, n       ; se NON prima iterazione
            jne sottrai     ; salta alla differenza
            mov risu, al    ; altrimenti carica primo elemento senza sottrarre 
            jmp skip        ; e vai avanti
            
sottrai:    sub risu, al    ; sottrai agli esistenti l'ultimo calcolato
            
            ; loop caricamento
skip:       inc si
            loop carica
            
            ; reset indici
            mov cx, 0
            mov cl, n
            mov si, 0
                                        
            ; messaggio visualizzazione primo vettore
visualizza: lea dx, msg4
            mov ah, 9
            int 21h             
            
            ; output a 2 cifre del primo vettore   
            mov al, [v1+si]
            mov ah, 0
            div dieci                     
            mov bx, ax
            mov dl, al             
            add dl, 30h             
            mov ah, 2
            int 21h
            mov dl, bh              
            add dl, 30h             
            mov ah, 2
            int 21h
            
            ; messaggio visualizzazione secondo vettore
            lea dx, msg5
            mov ah, 9
            int 21h             
            
            ; output a 2 cifre del secondo vettore   
            mov al, [v2+si]
            mov ah, 0
            div dieci                     
            mov bx, ax
            mov dl, al             
            add dl, 30h             
            mov ah, 2
            int 21h
            mov dl, bh              
            add dl, 30h             
            mov ah, 2
            int 21h
            
            ; loop visualizzazione
            inc si
            loop visualizza 
                 
            ; messaggio risultato
            lea dx, msg6            
            mov ah, 9               
            int 21h    
             
            ; visualizzazione risultato punto 3      
            mov al, risu
            mov ah, 0
            div dieci                     
            mov bx, ax
            mov dl, al             
            add dl, 30h             
            mov ah, 2
            int 21h
            mov dl, bh              
            add dl, 30h             
            mov ah, 2
            int 21h
            
            ; fine programma
            mov ah, 4ch
            int 21h
code ends
end start