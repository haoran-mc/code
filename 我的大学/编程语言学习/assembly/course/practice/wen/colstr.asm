;6-1.asm 在5行16列上用写显存方法显示多彩字符串。
data segment
a1 db 'Hello world!'
a2 db 0
data ends
code segment
assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	mov dh,5				;行 
	mov dl,16				;列
	mov bl,4				;属性
	mov si,0
show_str:
	mov ax,0b800h			;显存首址
	mov es,ax
	mov ax,160	
	mul dh					;行号*160
	mov di,ax				;起始行位置
	sal dl,1
	mov dh,0
	add di,dx				;+列号
	mov cx,a2-a1			;字符串长度
let1: 
	mov al,[si]				;循环写字符和属性到显存
	mov es:[di],al
	mov byte ptr es:[di+1],bl
	inc si
	inc bl
	add di,2				;写完即显示完
	loop let1	
	mov ah,4ch
	int 21h
code ends
end start
