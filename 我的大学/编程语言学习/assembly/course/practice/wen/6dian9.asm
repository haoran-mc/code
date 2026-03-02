data segment
    array_head dw 3,5,15,23,37,49,52,65,78,99
    array_end dw 105
    n dw 32
data ends
code segment
    assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov ax,n
    mov array_head-2,0ffffh
    mov si,0
compare:
    cmp array_end[si],ax
    jle insert
    mov bx,array_end[si]
    mov array_end[si+2],bx
    sub si,2
    jmp short compare
insert:
    mov array_end[si+2],ax
ret
code ends
    end start