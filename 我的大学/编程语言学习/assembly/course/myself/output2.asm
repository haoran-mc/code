data segment
    buffer db 10,?,10 dup(?)
data ends
stack segment
    db 100 dup(?)
    tos label word
stack ends
extra segment
extra ends
code segment
main proc far
assume cs:code,ds:data,es:extra,ss:stack
start:
    mov ax,stack
    mov ss,ax
    push ds
    xor ax,ax
    push ax
    mov ax,data
    mov ds,ax
    mov ax,extra
    mov es,ax

    lea dx,buffer
    mov ah,10
    int 21h
    mov ah,9
    int 21h

    mov ah,4ch
    int 21h
main endp

code ends
end start