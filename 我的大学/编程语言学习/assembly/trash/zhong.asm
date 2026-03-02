data segment
    w dw 1234h
    x dw 1234h
    y dw 1234h
    r dw 1234h
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov ax,w
    mov bx,0002
    imul bx
    add ax,x
    mov bx,y
    sub bx,0006
    idiv bx
    mov r,dx
    mov ah,4ch
    int 21h
code ends
end start