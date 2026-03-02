; 已知字数组定义如下：ARRAY  DW  12,78,55,4,125,96
; 					   MAX    DW   ?
;   编制程序求出该ARRAY数组中的最大数放入MAX单元。

.model small
.stack 100h
.data
    array dw 12,78,55,4,125,96
    max dw ?
.code
.startup
    mov bx,0
    mov ax,array[bx]
    mov cx,6
lop:
    add bx,2
    cmp ax,array[bx]
    jb below
    jne above
below:
    mov ax,array[bx]
above:
    loop lop
    mov max,ax
    mov dl,al
    mov ah,2
    int 21h
.exit 0
end