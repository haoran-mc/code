;请编写一个程序来实现简单的程序菜单显示。(采用多模块程序设计方法)
;显示一个菜单要求用户从下表中选择：
;（1）	HEXAC  NUMBER  GAME 　　　　　         （对应－－>程序1）
;（2）	CHAR  STATISTICS PROGRAM　　　　（对应－－>程序２）
;（3）	PRESS  “ESC”  TO  QUIT
;用户作出选择1~3时，显示输出要执行操作的名字，如“Your selection is 1,the program will execute HEXAC NUMBER GAME!”然后转向相应的程序去执行
;执行结束前进行退出的判断，显示一个提示信息“will you continue program really？(Y:N)”
;要求用户从键盘键入字符，若是“Y”键，则继续程序的执行,若是“N”键，则返回到菜单
;若用户选择3，要求程序显示提示信息“Please press ESC key to exit!”,并能按要求正确退出。

;---------------------source module 1-------------------------
extrn pro2:far,pro3:far

data1 segment
    menu1 db '(1) HEXAC NUMBER GAME$'
    menu2 db '(2) CHAR STATSTICS PROGRAM$'
    menu3 db '(3) PRESS "ESC" TO QUIT$'
    enter db 0ah,0dh,'$'
    select db 'Please choose the program:$'
    info1 db 'Your selection is $'
    info2 db ',the program will execute $'
    info3 db ' !$'
    info4 db 'Will you continue program really?(Y:N) $'
    info5 db 'please press ESC key to exit!$'
    flag db ?
data1 ends
code1 segment
main proc far
assume cs:code1,ds:data1
start:
    mov ax,data1
    mov ds,ax
menu:
    mov dx,offset menu1
    mov ah,9
    int 21h
    call Pro_enter
    mov dx,offset menu2
    mov ah,9
    int 21h
    call pro_enter
    mov dx,offset menu3
    mov ah,9
    int 21h
    call pro_enter
again:
    mov dx,offset select
    mov ah,9
    int 21h
    mov ah,1
    int 21h
    call pro_enter
    mov cl,al
    cmp al,'1'
    jz prog1
    cmp al,'2'
    jz prog2
    cmp al,'3'
    jz prog3
    jmp again
prog1:
    call pro_info
    call pro_enter
    call far ptr pro2
    call pro_stop
    mov al,flag
    cmp al,1
    jz prog1
    jmp menu
prog2:
    call pro_info
    call pro_enter
    call far ptr pro3
    call pro_stop
    mov al,flag
    cmp al,1
    jz prog2
    jmp menu
prog3:
    call pro_info
    call pro_enter
    mov dx,offset info5
    mov ah,9
    int 21h
    mov ah,1
    int 21h
    call pro_enter
    cmp al,27
    jnz menu

    mov ah,4ch
    int 21h
main endp
pro_enter proc near
    mov dx,offset enter
    mov ah,9
    int 21h
    ret
pro_enter endp
pro_info proc near
    mov dx,offset info1
    mov ah,9
    int 21h
    mov dl,cl
    mov ah,2
    int 21h
    mov dx,offset info2
    mov ah,9
    int 21h
    cmp cl,'1'
    jz hex
    cmp cl,'2'
    jz char
    cmp cl,'3'
    jz quit
hex:
    mov dx,offset menu1+5
    mov ah,9
    int 21h
    jmp next
char:
    mov dx,offset menu2+5
    mov ah,9
    int 21h
    jmp next
quit:
    mov dx,offset menu3+5
    mov ah,9
    int 21h
next:
    mov dx,offset info3
    mov ah,9
    int 21h
    ret
pro_info endp
pro_stop proc near
    call pro_enter
    mov dx,offset info4
    mov ah,1
    int 21h
    cmp al,'Y'
    jz yes
    cmp al,'N'
    jz no
    call pro_stop
yes:
    mov al,1
    mov flag,al
    ret
no:
    mov al,0
    mov flag,al
    ret
pro_stop endp
code1 ends
end start