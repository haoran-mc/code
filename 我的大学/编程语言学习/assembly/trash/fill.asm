;这是一个完整的程序
;1.有堆栈段，附加段
;2.使用main主程序
;注意堆栈段的定义

data segment
    bit db '1010010110100101'
data ends
extra segment
extra ends
stack segment
    dw 100 dup(?)
    tos label word
stack ends
code segment
main proc far
assume cs:code,ss:stack,es:extra,ds:data
start:
    mov ax,stack
    mov ss,ax
    mov sp,offset tos
    push ds
    sub ax,ax
    push ax
    mov ax,data
    mov ds,ax



    mov ah,4ch
    int 21h
main endp
code ends
end start