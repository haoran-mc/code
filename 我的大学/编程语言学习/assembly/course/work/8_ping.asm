data segment
hang db 30,?,30 dup(?),'$'
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov cx,15
    mov bx,0
store:
    mov ax,3820h
    mov word ptr hang[bx],ax
    inc bx
    inc bx
    loop store
    mov ch,0fh
lie:
    mov cl,0fh
    sub cl,ch
    jz output
    jnz blank
blank:
    mov dl,20h
    int 21h
    dec cl
    jnz blank
output:
    mov dx,offset hang
    mov ah,09h
    int 21h
    dec ch 
    mov dl,0ah
    mov ah,02h
    int 21h
    jnz lie
    mov ah,4ch
    int 21h
code ends
end start