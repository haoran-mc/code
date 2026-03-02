data segment
    yjw db 'hello!$'
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov cx,6
    mov bl,0
    lea si,yjw
    mov al,'l'
qqq:
    cmp al,[si]
    jnz next
    inc bl
next:
    inc si
    loop qqq
    mov dl,bl
    mov ah,2
    int 21h
    mov ah,4ch
    int 21h
code ends
end start
