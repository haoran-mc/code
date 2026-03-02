data segment
    array dw 10,10,10,11,0,9,0,0,0,0
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax

    lea si,array
    mov cx,10
    mov ah,0
jia:
    add ah,[si]
    add si,2
    loop jia

    ;dec cx
    ;cmp cx,0
    ;jnz jia

    mov dl,ah
    mov ah,2
    int 21h

    mov ax,4c00h
    int 21h
code ends
end start