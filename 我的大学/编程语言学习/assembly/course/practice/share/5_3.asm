data segment
    buffer db 20,?,20 dup(?)
    string db 'Hello world!'
    y db 0ah,0dh,'MATCH$'
    n db 0ah,0dh,'NO MATCH!,PROGRAM TERMINATED!$'
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov si,offset string
    mov cx,12
    lea dx,buffer
    mov ah,0ah
    int 21h
    lea bx,buffer[2]
compare:
    cmp bx,si
    jnz nmtc
    inc bx
    inc si
    loop compare
mtc:
    mov dx,offset y
    mov ah,9
    int 21h
    jmp exit
nmtc:
    mov dx,offset n
    mov ah,9
    int 21h
exit:
    mov ah,4ch
    int 21h
code ends
end start