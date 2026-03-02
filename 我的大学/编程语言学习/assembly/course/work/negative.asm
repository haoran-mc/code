data segment
    value db -5,-4,-3,-2,-1,0,-1h,-2h,-3h,-4h,-5h,1,2,3,4,5,1h,2h,3h,4h,5h
    N dw 21
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov cx,N
    xor si,si
    xor bx,bx
negative:
    cmp value[si],0
    jnl next
    inc bl
next:
    inc si
    loop negative
    mov ah,4ch
    int 21h
code ends
end start