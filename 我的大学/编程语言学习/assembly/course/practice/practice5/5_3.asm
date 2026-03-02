;预留字符串口令,输入口令串与预留密码串比较
;若匹配则显示“MATCH”
;否则显示“NOMATCH!,PROGRAM TERMINATED!”
data segment
    input db 'INPUT A STRING',0ah,0dh,'$'
    buffer db 20,?,20 dup(?)
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
    mov dx,offset input
    mov ah,09h
    int 21h
    mov si,offset string    ;lea si,string
    mov cx,12
    lea dx,buffer
    mov ah,0ah
    int 21h
    lea di,buffer[2]
    cld
    repe cmpsb
    jz mtc
    jmp nmtc
mtc:
    mov dx,offset y
    mov ah,9
    int 21h
    jmp exit
nmtc:
    mov dx,offset n
    mov ah,9
    int 21h
exit:
    mov ah,4ch
    int 21h
code ends
end start