data segment
    array dw 1,2,3,4,5,6,7,8,9,0
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax

    lea si,array
    lea di,array+2
    mov cx,5
    mov ah,0
jia:
    add ah,[si]
    add ah,[di]
    inc si
    inc si
    inc si
    inc si
    inc di
    inc di
    inc di
    inc di
    ;add si,4
    ;add di,4
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