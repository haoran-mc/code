;----------------------------------------------------
data segment
    input db 'PLEASE INPUT THE PASSWORD:',0ah,0dh,'$'
    array db 'hello world!'
    count equ $-array
    match db 0ah,0dh,'MATCH! CONGRATULATION$'
    no_match db 0ah,0dh,'NOMATCH!$'
    wrong db 'YOU CANNOT OPEN IT!$'
    enter db 0ah,0dh,'$'
    buffer db 20,?,20 dup(?)
data ends
;----------------------------------------------------
stack segment
    db 100 dup(?)
    tos label word
stack ends
;----------------------------------------------------
extra segment
extra ends
;----------------------------------------------------
code segment
main proc far
assume cs:code,ds:data,es:extra,ss:stack
start:
    mov ax,stack
    mov ss,ax
    mov sp,offset tos
    push ds
    xor ax,ax
    push ax
    mov ax,data
    mov ds,ax
    mov es,ax
    mov cx,3
    lea dx,input    ;提示输入
    mov ah,9
    int 21h
lop:
    push cx     ;入栈cx，串处理时会用到cx
    lea di,buffer
    mov dx,di   ;输入
    mov ah,10
    int 21h
    mov bl,buffer[1]    ;比较是否输入字符串与预留密码串字符个数相同
    cmp bl,count
    jnz prog_no_match
    add di,2    ;把输入串首地址放在目的变址寄存器
    lea si,array
    mov cx,count
    cld
    repe cmpsb
    jnz prog_no_match
    jcxz prog_match
prog_no_match:
    lea dx,no_match
    mov ah,9
    int 21h
    call pro_enter
    pop cx
    loop lop
    jmp prog_lock
prog_match:
    lea dx,match
    mov ah,9
    int 21h
    jmp next
prog_lock:
    lea dx,wrong
    mov ah,9
    int 21h
    jmp next
next:
    mov ah,4ch
    int 21h
main endp
;子程序，换行
pro_enter proc near
    lea dx,enter
    mov ah,9
    int 21h
    ret
pro_enter endp

code ends
end start