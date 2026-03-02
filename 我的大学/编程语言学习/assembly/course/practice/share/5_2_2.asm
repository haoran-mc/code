data segment
mess1 db 0ah,0dh,'it is a digital$'
mess2 db 0ah,0dh,'it is a lowcase letter$'
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
    mov ds,ax
prog0:mov ah,1
    int 21h
    cmp al,0dh
    je prog3
    cmp al,30h
    jb prog0
    cmp al,3ah
    jb prog2
    cmp al,41h
    jb prog0
    cmp al,5bh
    jb prog1
    cmp al,61h
    jb prog0
    cmp al,7bh
    jb prog1
    jmp prog0
prog1:mov dx,offset mess2
    mov ah,9
    int 21h
    jmp prog3
prog2:mov dx,offset mess1
    mov ah,9
    int 21h
    jmp prog3
prog3:mov ah,4ch
    int 21h
code ends
end start