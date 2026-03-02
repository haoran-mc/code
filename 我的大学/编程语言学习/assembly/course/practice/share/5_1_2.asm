data segment
mess1 db 0ah,0dh,'too big$'
mess2 db 0ah,0dh,'too small$'
mess3 db 0ah,0dh,'your are right$'
m db '5'
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
    mov ds,ax
    mov ah,1
    int 21h
    cmp al,m
    je prog1
    ja prog3
    jmp prog2
prog1:lea dx,mess3
    mov ah,9
    int 21h
    jmp prog4
prog2:lea dx,mess2
    mov ah,9
    int 21h
    jmp prog4
prog3:lea dx,mess1
    mov ah,9
    int 21h
    jmp prog4
prog4:mov ah,4ch
    int 21h
code ends
end start
