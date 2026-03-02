;设有一段英文，其字符变量名为ENG,并以$字符结束
;试编写一程序，统计其中单词的个数，并查出单词SUN在该文中的出现次数
;并以格式“SUN:××××”显示出次数。

data segment
    eng db 'You are the little sun in my heart, shining wherever I go.$'
    buffer db 10 dup(?)
    words db 'word:$'
    sun db 'sun:$'
    enter db 0ah,0dh,'$'
data ends
code segment
main proc far
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    call pro_count_word
    call pro_count_sun
    mov ah,4ch
    int 21h
main endp
pro_count_word proc near
    xor bx,bx
    xor ax,ax
    mov cl,' '    ;空格，比较
    mov ch,'$'
    dec bx
lop:
    inc bx
    cmp eng[bx],cl
    jnz judge1
    inc al
judge1:
    cmp eng[bx],ch
    jnz lop
    inc al
    lea dx,words
    mov ah,9
    int 21h
output2:
    cmp al,10
    push ax
    jl output1
    mov dl,'1'
    mov ah,2
    int 21h
    pop ax      ;*****************************************************************************
    sub al,10
    jmp output2
output1:
    add al,30h
    mov dl,al
    mov ah,2
    int 21h
    lea dx,enter
    mov ah,9
    int 21h
    ret
pro_count_word endp
pro_count_sun proc near
    ret
pro_count_sun endp
code ends
end start