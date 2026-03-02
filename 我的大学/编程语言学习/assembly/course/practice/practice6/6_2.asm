; 编写程序完成如下功能：预留字符串口令,输入口令串与预留密码串比较。若匹配则显示“MATCH！CONGRATULATION”,否则显示“NOMATCH!”,并让用户重新输入，程序能对口令进行测试，但测试次数最多3次，若3次输入密码皆错，给出相应的提示信息，程序退出。
;问题分析：本题中当进行口令检查时，若要求不把用户从键盘上键入的密码串显示在屏幕上而只挨个显示“ * ”号,如何修改程序？

.model small
.stack 100h
.data
    array db 'hello world!'
    match db 'MATCH! CONGRATULATION$'
    no_match db 'NOMATCH!$'
    wrong db 'YOU CANNOT OPEN IT!$'
    enter db 0ah,0dh,'$'
    buffer db 20,?,20 dup(?)
.code
.startup
    mov cx,3
lop:
    push cx
    lea di,buffer
    mov dx,di
    mov ah,10
    int 21h
    lea dx,enter
    mov ah,9
    int 21h
    add di,2
    lea si,array
    mov cx,12
    cld
    repe cmpsb
    jnz prog_no_match
    jcxz prog_match
prog_no_match:
    lea dx,no_match
    mov ah,9
    int 21h
    lea dx,enter
    mov ah,9
    int 21h
    pop cx
    loop lop
    jmp prog_lock
prog_match:
    lea dx,match
    mov ah,9
    int 21h
    jmp prog_open
prog_lock:
    lea dx,wrong
    mov ah,9
    int 21h
    jmp next
prog_open:
    lea dx,enter
    mov ah,9
    int 21h
next:
    xor ax,ax
.exit 0
end