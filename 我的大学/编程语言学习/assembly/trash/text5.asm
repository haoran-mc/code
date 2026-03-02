data segment
    x db 25
    y db 30
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov al,x
    sub al,y
    jb qufan
    jnb print
qufan:
    neg al
print:
    mov dl,al
    mov ah,2
    int 21h
    mov ah,4ch
    int 21h
code ends
end start