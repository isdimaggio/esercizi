data segment
    dieci       db 10
    n           db ?
    vetprimo    db 13 dup(0)
    vetsecondo  db 13 dup(0)
    somma       db 0
    tmp_primo   db ?
    tmp_vp      db ?
    tmp_vs      db ?
    m_dim       db 13, 10, 'inserisci dimensione <=11 : $'    
    m_insprimo  db 13, 10, 'inserisci elemento primo vettore : $'
    m_inssec    db 13, 10, 'inserisci elemento secondo vettore : $'
    m_vinsprimo db 13, 10, 'visualizza elemento primo vettore : $'
    m_vinssec   db 13, 10, 'visualizza elemento secondo vettore : $'
    m_risu      db 13, 10, 'risultato : $'
data ends
code segment
assume cs:code, ds:data
start:          mov ax, data            ; inizio programma
                mov ds, ax                 
e_dim:          lea dx, m_dim           ; punto 1            
                mov ah, 9               
                int 21h  
                
                mov ah, 1
                int 21h
                sub al, 30h
                mul dieci
                mov n, al 
                mov ah, 1
                int 21h
                sub al, 30h
                add n, al
                
                cmp n, 11      
                ja e_dim 
                
                mov cx, 0               ; carico il primo           
                mov cl, n
                mov si, 0     
                
e_load:         lea dx, m_insprimo      ; inserisci primo vet
                mov ah, 9
                int 21h 
                
                mov ah, 1
                int 21h
                sub al, 30h
                mul dieci
                mov bl, al 
                mov ah, 1
                int 21h
                sub al, 30h
                add bl, al
                
                mov [vetprimo+si], bl 
                mov tmp_primo, bl
                
                lea dx, m_inssec           ; inserisci secondo vet
                mov ah, 9
                int 21h 
                
                mov ah, 1
                int 21h
                sub al, 30h
                mul dieci
                mov bl, al 
                mov ah, 1
                int 21h
                sub al, 30h
                add bl, al
                
                mov [vetsecondo+si], bl
          
                mov al, tmp_primo
                mul bl
                add somma, al
                
                inc si
                loop e_load
                
                mov cx, 0         
                mov cl, n
                mov si, 0     
                
e_vis:          lea dx, m_vinsprimo      ; visualizzazione
                mov ah, 9
                int 21h
                
                mov al, [vetprimo+si]
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
                
                lea dx, m_vinssec        ; visualizzazione
                mov ah, 9
                int 21h
                
                mov al, [vetsecondo+si]
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
                
                ; fai le visualizzazioni
                
                inc si
                loop e_vis
                
                ; visualizza la somma 
                
                lea dx, m_risu
                mov ah, 9
                int 21h
                
                mov al, somma    
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
                
                mov ah, 4ch             ; fine programma
                int 21h
code ends
end start