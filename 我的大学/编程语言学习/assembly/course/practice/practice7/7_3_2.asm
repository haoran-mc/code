;---------------------source module 2-------------------------
public pro2

;程序一
data2 segment
    buffer db '1','0','1','1','0','0','1','0'
    count equ $-buffer
data2 ends
code2 segment
pro2 proc far
assume cs:code2,ds:data2
    mov ax,data2
    mov ds,ax
    call pro_decimal
    call pro_hexac
    ret
pro2 endp

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
code2 ends
end
