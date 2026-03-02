;---------------------source module 3-------------------------
public pro3

data3 segment
    table db 20 dup(?)
    sum db ?
data3 ends
stack segment
    db 100 dup(?)
    tos label word
stack ends
code3 segment
pro3 proc far
assume cs:code3,ds:data3,ss:stack
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
    ret
pro3 endp
code3 ends
code4 segment
assume cs:code4
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
code4 ends
end
