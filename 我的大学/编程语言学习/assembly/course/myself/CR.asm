;0dh  CR 回车，回到此行第一个字符处
;0ah  LF 换行，换到下一行

data segment
    enter0 db 'enter0',0ah,0dh,'$'
    enter1 db 'enter1',0ah,'$'
    enter2 db 'enter2',0dh,'$'
    enter3 db 'enter3',0dh,0ah,'$'
    enter4 db 'enter','$'
data ends
code segment
main proc far
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax

    call input      ;输入字符，立即换到下一行的行首
    mov dl,0ah
    mov ah,2
    int 21h
    call input      ;输入字符，光标停在输入的字符处

    mov dl,0dh
    mov ah,2
    int 21h
    call input      ;直接输入字符不使用回车符的话，会改变之前输入的字符，然后立即输出enter0之后立即跳到下一行行首

    lea dx,enter0
    mov ah,9
    int 21h
    call input      ;输入字符，立即输出enter1之后立即跳到下一行行首

    lea dx,enter1
    mov ah,9
    int 21h
    call input      ;输入字符后，光标停在此处，如果再次输入字符，会改变之前输入的字符，然后在下一行输出emter3

    lea dx,enter2
    mov ah,9
    int 21h
    call input

    lea dx,enter3
    mov ah,9
    int 21h
    call input      ;输入字符后，输出enter4，光标停在此行最后一个字符处

    lea dx,enter4
    mov ah,9
    int 21h
    call input      ;输入字符，显示在此行最后一个字符之后，然后换行返回c盘

    mov ah,4ch
    int 21h

main endp
input proc near
    mov ah,1
    int 21h
    ret
input endp
code ends
end start