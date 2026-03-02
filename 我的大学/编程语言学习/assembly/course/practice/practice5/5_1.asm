;猜数程序,程序中预设一数字字符M，(如：‘5’)从键盘输入一个数字字符N
;若N <M,在屏幕上显示输出字符串“TOO BIG”
;若N >M 则显示“TOO SMALL”
;否则显示“YOUR ARE RIGHT”。
data segment
m db '5'
input db 'INPUT A NUMBER CHAR:$'
big db 0ah,0dh,'TOO BIG$'
small db 0ah,0dh,'TOO SMALL$'
right db 0ah,0dh,'YOU ARE RIGHT$'
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov dx,offset input
    mov ah,9
    int 21h
    mov ah,1
    int 21h
    cmp al,m
    je right0
    jb small0
    jmp big0
right0:
    mov dx,offset right
    mov ah,9
    int 21h
    jmp exit
big0:
    mov dx,offset big
    mov ah,9
    int 21h
    jmp exit
small0:
    mov dx,offset small
    mov ah,9
    int 21h
    jmp exit
exit:
    mov ah,4ch
    int 21h
code ends
end start
