data segment
    mes1 db 13,10,'inserisci numero n cifre: $'    
    dieci db 10
    num db 0
    tmp db 0
data ends
code segment
assume cs:code ds:data
start:      mov ax, data
            mov ds, ax
            
            lea dx, mes1
            mov ah, 9
            int 21h
            
inser:      mov ah, 1               ; carica cifra
            int 21h
            
            cmp al, 13              ; se invio (13) salta alla fine
            je fine
            
            sub al, 30h             ; ascii -> numero
            mov tmp, al             ; salva cifra inserita
            mov al, num
            mul dieci
            mov num, al
            mov al, tmp
            add num, al
                        
            jmp inser
            
fine:       mov ah, 4ch
            int 21h
            
code ends
end start