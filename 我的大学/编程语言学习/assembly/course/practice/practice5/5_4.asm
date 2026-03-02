data segment
    table dw prog1,prog2,prog3,prog4
    str_prog1 db '1.GUESS NUMBER GAME$'
    str_prog2 db '2.CHAR SELECTION PROGRAM$'
    str_prog3 db '3.PASSWORD PROGRAM$'
    str_prog4 db '4.PRESS  “ESC”  TO  QUIT$'
    info1 db 'Your selection is $'
    info2 db ',the program will execute $'
    info3 db 'will you continue program really？(Y:N)$'
    info4 db 'Please press ESC key to exit!$'
    enter db 0ah,0dh,'$'
    escpro db 'ESC'
    buffer2 db 20,?,20 dup(?)

    m db '5'
    input1 db 'INPUT A NUMBER CHAR:$'
    big db 0ah,0dh,'TOO BIG$'
    small db 0ah,0dh,'TOO SMALL$'
    right db 0ah,0dh,'YOU ARE RIGHT$'

    input2 db 'INPUT A CHAR:$'
    num db 0ah,0dh,'IT IS A DIGITAL$'
    letter db 0ah,0dh,'IT IS A LOWCASE LETTER$'

    input3 db 'INPUT A STRING',0ah,0dh,'$'
    buffer1 db 20,?,20 dup(?)
    string db 'Hello world!'
    y db 0ah,0dh,'MATCH$'
    n db 0ah,0dh,'NO MATCH!,PROGRAM TERMINATED!$'
data ends
extra segment
extra ends
code segment
assume cs:code,ds:data,es:extra
start:
    mov ax,data
    mov ds,ax
    mov es,ax
menu:
    mov dx,offset str_prog1
    mov ah,09h
    int 21h
    mov dx,offset enter
    mov ah,09h
    int 21h
    mov dx,offset str_prog2
    mov ah,09h
    int 21h
    mov dx,offset enter
    mov ah,09h
    int 21h
    mov dx,offset str_prog3
    mov ah,09h
    int 21h
    mov dx,offset enter
    mov ah,09h
    int 21h
    mov dx,offset str_prog4
    mov ah,09h
    int 21h
    mov dx,offset enter
    mov ah,09h
    int 21h
    mov dx,offset info1
    mov ah,09h
    int 21h
    mov ah,1
    int 21h
    mov ah,0
    push ax
    add al,30h
    mov dl,al
    mov ah,2
    int 21h
    mov dx,offset info2
    mov ah,09h
    int 21h
    cmp al,'1'
    jz out1
    cmp al,'2'
    jz out2
    cmp al,'3'
    jz out3
    cmp al,'4'
    jz out4
out1:
    mov dx,offset str_prog1
    mov ah,09h
    int 21h
    jmp transfer
out2:
    mov dx,offset str_prog2
    mov ah,09h
    int 21h
    jmp transfer
out3:
    mov dx,offset str_prog3
    mov ah,09h
    int 21h
    jmp transfer
out4:
    mov dx,offset str_prog4
    mov ah,09h
    int 21h
    jmp transfer
transfer:
    pop bx
    dec bx
    jmp table[bx]
prog1:
        mov dx,offset enter
        mov ah,09h
        int 21h
        mov dx,offset input1
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
        jmp select1
    big0:
        mov dx,offset big
        mov ah,9
        int 21h
        jmp select1
    small0:
        mov dx,offset small
        mov ah,9
        int 21h
        jmp select1
    select1:
        mov dx,offset enter
        mov ah,09h
        int 21h
        mov dx,offset info3
        mov ah,09h
        int 21h
        mov dx,offset enter
        mov ah,09h
        int 21h
        mov ah,1
        int 21h
        cmp al,'N'
        jz menu
        jmp prog1
prog2:
        mov dx,offset enter
        mov ah,09h
        int 21h
    input0:
        mov dx,offset input2
        mov ah,9
        int 21h
        mov ah,1
        int 21h
        cmp al,0dh
        je select2
        cmp al,30h
        jb input0
        cmp al,3ah
        jb num0
        cmp al,41h
        jb input0
        cmp al,5bh
        jb letter0
        cmp al,61h
        jb input0
        cmp al,7bh
        jb letter0
        jmp input0
    num0:
        mov dx,offset num
        mov ah,9
        int 21h
        jmp select2
    letter0:
        mov dx,offset letter
        mov ah,9
        int 21h
        jmp select2
    select2:
        mov dx,offset enter
        mov ah,09h
        int 21h
        mov dx,offset info3
        mov ah,09h
        int 21h
        mov dx,offset enter
        mov ah,09h
        int 21h
        mov ah,1
        int 21h
        cmp al,'N'
        jz menu
        jmp prog2
PROG3:
        mov dx,offset enter
        mov ah,09h
        int 21h
        mov dx,offset input3
        mov ah,09h
        int 21h
        mov si,offset string
        mov cx,12
        lea dx,buffer1
        mov ah,0ah
        int 21h
        lea di,buffer1[2]
        cld
        repe cmpsb
        jz mtc
        jmp nmtc
    mtc:
        mov dx,offset y
        mov ah,9
        int 21h
        mov dx,offset enter
        mov ah,09h
        int 21h
        jmp select3
    nmtc:
        mov dx,offset n
        mov ah,9
        int 21h
        mov dx,offset enter
        mov ah,09h
        int 21h
    select3:
        mov dx,offset info3
        mov ah,09h
        int 21h
        mov dx,offset enter
        mov ah,09h
        int 21h
        mov ah,1
        int 21h
        cmp al,'N'
        jz menu
        jmp prog3
prog4:
    mov dx,offset info4
    mov ah,09h
    int 21h
    mov si,offset escpro
    mov cx,3
    mov dx,offset buffer2
    mov ah,0ah
    int 21h
    lea di,buffer2[2]
    cld
    repe cmpsb
    jz exit
    jmp prog4
exit:
    mov ah,4ch
    int 21h
code ends
end start