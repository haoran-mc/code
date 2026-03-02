data segment
    BLOCK dw  65, 66, 67, 68, 69, 70, 71, 72, 73, 74
   ;BLOCK dw 'A','B','C','D','E','F','G','H','I','J'
    enter db 0ah,0dh,'$'
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax

    mov dx,BLOCK+(3-1)*2    ;书上内容，把首地址为BLOCK的字数组的第六个字传送到DX寄存器
    mov ah,2
    int 21h
    mov dx,offset enter
    mov ah,09h
    int 21h

    mov dx,BLOCK+3
    mov ah,2
    int 21h
    mov dx,offset enter
    mov ah,09h
    int 21h

    mov dx,BLOCK+8      ;*******由此可知，在字数组中地址加一仍然是以字节加一的方式进行
    mov ah,2
    int 21h

    mov ah,4ch
    int 21h
code ends
end start
