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
    call pro1
    call far ptr pro2
    mov ah,4ch
    int 21h
main endp

pro1 proc near
    lea dx,buffer
    mov ah,10
    int 21h
    ret
pro1 endp
code ends

code1 segment
    pro2 proc far
        lea dx,buffer
        mov ah,9
        int 21h
        ret
    pro2 endp
code1 ends
end start