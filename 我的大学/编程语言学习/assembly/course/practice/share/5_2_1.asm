data segment
msg1 db 0ah,0dh,'IT IS A DIGITAL$'
msg2 db 0ah,0dh,'IT IS A LOWCASE LETTER$'
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
    mov ds,ax
prog0:mov ah,1
    int 21h
    cmp al,0dh
    je next
    cmp al,30h
    jb prog0
    cmp al,3ah
    jb prog1
    cmp al,41h
    jb prog0
    cmp al,5bh
    jb prog2
    cmp al,61h
    jb prog0
    cmp al,7bh
    jb prog2
    jmp prog0
prog1:mov dx,offset msg1
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