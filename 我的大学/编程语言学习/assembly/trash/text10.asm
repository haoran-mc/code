data segment
    string1 db 'geiyepa'
    count equ $-string1
    string2 db 'MATCH!CONGRATULATION$',0ah,0dh,'$'
    string3 db 'NOMATCH!',0ah,0dh,'$'
    string4 db 'zhuaba$'
    buffer db 20,?,20 dup(?)
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov ax,3
input:
    push ax
    lea dx,buffer
    mov ah,0ah
    int 21h
    mov bl,count
    cmp buffer[1],bl
    jnz wrong
    lea si,string1
    lea di,buffer[2]
    xor bx,bx
    mov cx,count-1
compare:
    mov dx,[di+bx]
    cmp dx,[si+bx]
    jnz wrong
    inc bx
    loop compare
right:
    lea dx,string2
    mov ah,9
    int 21h
    jmp realend
wrong:
    lea dx,string3
    mov ah,9
    int 21h
    pop ax
    dec ax
    cmp ax,0
    jnz input
endd:
    lea dx,string4
    mov ah,9
    int 21h
realend:
    mov ah,4ch
    int 21h
code ends
end start