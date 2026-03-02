data segment
    num db '3','2','4','9','7','0','1','6','5','8'
    count equ $-num
    temp db ?
data ends
code segment
main proc far
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    call pro_compare
    call pro_output
    mov ah,4ch
    int 21h
main endp
pro_compare proc near
    mov cx,count
    dec cx
row:
    push cx
    xor bx,bx
    mov si,bx
    mov al,num[bx]
line:
    cmp al,num[bx+1]
    jb change
    jmp store
change:
    mov al,num[bx+1]
    mov si,bx
    add si,1
store:
    cmp cx,1
    jnz continue_line
    mov temp,al
    mov al,num[bx+1]
    mov num[si],al
    mov al,temp
    mov num[bx+1],al
continue_line:
    inc bx
    loop line
continue_row:
    pop cx
    loop row
    ret
pro_compare endp
pro_output proc near
    xor bx,bx
    mov cx,count
next:
    mov dl,num[bx]
    mov ah,2
    int 21h
    mov dl,0
    mov ah,2
    int 21h
    inc bx
    loop next
    ret
pro_output endp
code ends
end start