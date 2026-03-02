;将BUF开始的10个单元中的二进制数转换成两位十六进制数的ASCII码在屏幕上显示出来
;要求码型转换通过子程序HEXAC实现,在转换过程中,通过子程序DISP实现显示。
;tmd 直接定义一个二进制数字吧


data segment
    buffer db '1','0','1','1','0','0','1','0'
    count equ $-buffer
data ends
code segment
main proc far
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    call pro_decimal
    call pro_hexac
    mov ah,4ch
    int 21h
main endp

pro_decimal proc near
    xor bx,bx
    xor ax,ax
    xor dx,dx
    mov cx,count
change:
    mov al,buffer[bx]
    sub al,30h
    xchg al,dh
    mov dl,2
    mul dl
    xchg al,dh
    add dh,al
    inc bx
    loop change
    ret
pro_decimal endp
pro_hexac proc near
    mov bh,dh
    mov ch,2
rotate:
    mov cl,4
    rol bh,cl
    mov al,bh
    and al,0fh
    add al,30h
    cmp al,3ah
    jl disp
    add al,7h
disp:
    call pro_disp
    dec ch
    jnz rotate
    ret
pro_hexac endp
pro_disp proc near
    mov dl,al
    mov ah,2
    int 21h
    ret
Pro_disp endp

code ends
end start



; haoran proc near
;     mov dl,0ah
;     mov ah,2
;     int 21h
;     mov cl,buffer[1]
;     mov ch,0
;     mov bx,cx
;     mov dl,'$'
;     mov buffer[bx+2],dl
;     lea dx,buffer+2
;     mov ah,9
;     int 21h
;     ret
; haoran endp