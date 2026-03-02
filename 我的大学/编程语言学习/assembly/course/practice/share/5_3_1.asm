data segment
buffer db 20 dup(?)
mima db 'wo shi xingzhuo'
match db 'MATCH$'
no_match db 'NO MATCH!,PROGRAM TERMINATED!$'
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
    mov ds,ax
    mov si,offset mima
    mov cx,15
    lea dx,buffer
    mov ah,0ah
    int 21h
    lea di,buffer
scanf:cmp di,si
    jnz no
    inc di
    inc si
    loop scanf
yes:mov dx,offset match
    mov ah,9
    int 21h
    jmp next
no:mov dx,offset no_match
    mov ah,9
    int 21h
next:mov ah,4ch
    int 21h
code ends
end start