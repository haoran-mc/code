data segment
buffer db 20 dup(?)
mess1 db 'NCU'
mess2 db 0ah,0dh,'MATCH$'
mess3 db 0ah,0dh,'NO MATCH!,PROGRAM TERMINATED!$'
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
    mov ds,ax
    lea si,mess1
    mov cx,3
    lea dx,buffer
    mov ah,0ah
    int 21h
    lea bx,buffer
prog1:cmp bx,si
    jnz prog2
    inc bx
    inc si
    loop prog1
    lea dx,mess2
    mov ah,9
    int 21h
    jmp prog3
prog2:lea dx,mess3
    mov ah,9
    int 21h
prog3:mov ah,4ch
    int 21h
code ends
end start