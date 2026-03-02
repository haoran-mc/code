code segment
main proc far
assume cs:code
start:
    call input
    call crlf
    call hex
    call crlf
    jmp start
main endp
;--------------------------------输入字符
input proc near
    mov bx,0
newchar:
    mov ah,1        ;输入字符数串
    int 21h
    sub al,30h
    jl exit     ;此时比较的是al？********
    cmp al,9
    jg exit
    cbw

;之前输入乘十加之后输入字符
;在此之前需要ASCII码减30h，在ASCII码的基础上操作
    xchg ax,bx
    mov cx,10
    mul cx
    xchg ax,bx
    add bx,ax

    jmp newchar
exit:
    ret
input endp
;--------------------------------将输入的字符转换成十六进制
hex proc near
    mov ch,4
rotate:
    mov cl,4
;在上一个子程序中，输入的字符在计算机中以ASCII码十进制的形式放在bx中
;接下来是将bx中最高的四位放在al的最低的四位上
    rol bx,cl
    mov al,bl
    and al,0fh

    add al,30h          ;输出十六进制数
    cmp al,3ah
    jl printit
    add al,7h           
;假如此时al中是3ah，那么希望屏幕上输出a或A，
;A的ASCII码是41h，所以需要加7h。
;如果需要输出a，需要加27h
printit:
    mov dl,al
    mov ah,2
    int 21h
    dec ch
    jnz rotate      ;循环将bx中每四位输出，所以会输出四个字符
    ret
hex endp
;--------------------------------回车
crlf proc near
    mov dl,0dh
    mov ah,2
    int 21h
    mov dl,0ah
    mov ah,2
    int 21h
    ret
crlf endp
;--------------------------------
code ends
end start