data segment
	string db 'I am a student!$'
	COUNT equ $-string
data ends
code segment
assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	mov cx,COUNT	;设置循环次数
	mov si,offset string
	xor bx,bx	;bx = 0,记录空格数
	jcxz done	;如果长度为零,退出
	mov al,20h
again:
	cmp al,[si]
	jnz next	;非空格,转移
	inc bx	;是空格,个数加一
next:
	inc si
	loop again	;字符个数减一,不为0继续循环
		;dec cx
		;jnz again
done:
	mov ah,4ch
	int 21h
code ends
end start