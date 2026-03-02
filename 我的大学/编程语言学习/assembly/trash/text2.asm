;dw 'AB'    与 db 'A','B'   的区别
;输出char的方法

data segment
    org 66
    char1 dw 'CD'
    char2 dw 6768    ;总之这样命名就是不对，不能输出CD
    ;char2 dw 67,68     这样就可以输出C，所以应该判断当使用char2 dw 6768 时，不能判断分界线的位置
    char3 db 67,68
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax

    lea dx,char1     ;会乱码
    ;mov dx,offset char1
    mov bl,dh   ;交换次序，以达到先输出dh中的内容后输出dl中的内容
    mov dh,dl
    mov dl,bl
    mov ah,2    ;这里不输出，因为dh中是00
    int 21h
    mov dl,dh
    mov ah,2    ;这里输出B，不是因为char中第二个是B的ASCII码，而是char的首地址为0066
    int 21h

    mov dx,char1
    mov bl,dh
    mov dh,dl
    mov dl,bl
    mov ah,2
    int 21h
    mov dl,dh
    mov ah,2
    int 21h

    mov dx,char2
    mov bl,dh
    mov dh,dl
    mov dl,bl
    mov ah,2
    int 21h
    mov dl,dh
    mov ah,2
    int 21h

    mov dl,char3
    mov ah,2
    int 21h
    mov dl,char3+1
    mov ah,2
    int 21h

    mov ah,4ch
    int 21h
code ends
end start