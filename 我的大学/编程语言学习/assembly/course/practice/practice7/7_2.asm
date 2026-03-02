
;编写一个主程序,从键盘接收若干个字符,然后用远调用的方法,调用子程序统计字符串中小写字符’x’的个数
;子程序的参数是字符串的首地址TABLE,字符串长度N及字符”x”.子程序返回字符＂x”的个数
;参数传送采用堆栈实现.主程序在子程序返回后,显示字符”x”及其个数(设为一位十六进制数)。

data segment
    table db 20 dup(?)
    sum db ?
data ends
stack segment
    db 100 dup(?)
    tos label word
stack ends
extra segment
extra ends
code1 segment
main proc far
assume cs:code1,ds:data,ss:stack,es:extra
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

    mov bx,0
    mov cx,0
newchar:
    mov ah,1
    int 21h
    mov table[bx],al
    inc bx
    inc cx
    cmp al,0dh
    jnz newchar
    mov bx,offset table
    push bx
    mov bx,offset sum
    push bx
    call far ptr pro_sum
    mov dl,'x'
    mov ah,2
    int 21h
    mov dl,':'
    mov ah,2
    int 21h
    mov al,sum
    add al,30h
    cmp al,39h
    jbe print
    add al,27h
print:
    mov dl,al
    mov ah,2
    int 21h
    mov ah,4ch
    int 21h
main endp
code1 ends
code2 segment
assume cs:code2
    pro_sum proc far
        mov bp,sp
        mov si,[bp+6]
        mov di,[bp+4]
        ;cx也可以不pop出来，因为更改好像也没事
        ;si中存放着tabel地址
        ;di中存放着sum的地址
        ;此时的任务就是看cx中存放的是输入的字符数，还是需要再加一个空格数
        ;然后记录x的个数
        ;注意堆栈中的变化
        mov bx,0
        mov dl,'x'
        mov al,0
    compare:
        cmp [si+bx],dl
        jnz lop
        inc al
    lop:
        inc bx
        loop compare
        mov [di],al
        ret
    pro_sum endp
code2 ends
end start