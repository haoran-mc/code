;编写一个程序，判别键盘上输入的字符
;若是0-9字符，则显示“IT IS A DIGITAL”
;若为A-Z或a-z字符，均显示“IT IS A LOWCASE LETTER”
;若是回车字符(其ASCII码为0DH)，则结束程序
;若为其它字符则不显示，继续等待新的字符输入。
data segment
input db 'INPUT A CHAR:$'
num db 0ah,0dh,'IT IS A DIGITAL$'
letter db 0ah,0dh,'IT IS A LOWCASE LETTER$'
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
input0:
    mov dx,offset input
    mov ah,9
    int 21h
    mov ah,1
    int 21h
    cmp al,0dh
    je exit
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
    jmp exit
letter0:
    mov dx,offset letter
    mov ah,9
    int 21h
    jmp exit
exit:
    mov ah,4ch
    int 21h
code ends
end start