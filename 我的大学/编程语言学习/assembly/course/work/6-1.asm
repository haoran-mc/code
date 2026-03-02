DATA SEGMENT
    crlf db 0ah,0dh,'$'
DATA ENDS
CODES SEGMENT
    ASSUME CS:CODES, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    mov cx,1
    push cx  
    mov bx,0;存放行数
outputspace:
    mov dl,20h;输出空格
    mov ah,2
    int 21h
    loop outputspace
    pop cx
    inc cx;增加下一行空格数
    push cx     
    mov cx,6  
output8:
    mov dl,38h
    mov ah,2
    int 21h
    mov dl,20h
    mov ah,2
    int 21 
    loop output8
    lea dx,crlf;换行
    mov ah,9
    int 21h
    pop cx    
    inc bx
    cmp bx,6;判断是否满了6行
    jb outputspace
    MOV AH, 4CH
    INT 21H
CODES ENDS
END START