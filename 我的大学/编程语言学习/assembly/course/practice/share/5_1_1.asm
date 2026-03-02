data segment
m db '5'
msg1 db 0ah,0dh,'TOO BIG$'
msg2 db 0ah,0dh,'TOO SMALL$'
msg3 db 0ah,0dh,'YOUR ARE RIGHT$'
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
    mov ds,ax
    mov ah,1
    int 21h
    cmp al,m
    je prog1
    jb prog2
    jmp prog3
prog1:mov dx,offset msg3
    mov ah,9
    int 21h
    jmp next
prog3:mov dx,offset msg1
    mov ah,9
    int 21h
    jmp next
prog2:mov dx,offset msg2
    mov ah,9
    int 21h
    jmp next
next:mov ah,4ch
    int 21h
code ends
end start
