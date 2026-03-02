code segment
main proc far
assume cs:code
start:
    mov ax,0
    mov cs,ax
    mov ah,4ch
    int 21h
main endp
code ends
end start