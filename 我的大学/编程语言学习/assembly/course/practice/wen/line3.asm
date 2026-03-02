.model small
.data
mode db ?               ;保存当前显示模式
str  db 'END!$'
.code
main proc far
		mov ax, @data
		mov ds,ax

		mov ah,0fh
		int 10h
		mov mode,al             ;保存当前显示模式，在程序结束前恢复

		mov ah,0
		mov al,13h
		int 10h                 ;设置256色320* 200的图形显示模式

		mov dx, 0       
		mov al,01h              ;cx=线所在列，dx=线所在的行，AL=线的颜色
draw: 	call vline
		inc al
		inc dx
		cmp dx,200           ;从上到下画200条横线
		jl draw
		mov ah,0
		int 16h                 ;等待一个按键

		mov al,mode
		mov ah,0
		int 10h                 ;恢复原来的屏幕显示模式

		lea dx, str
		mov ah,9
		int 21h

	mov ah,4ch
	int 21h
main endp
vline proc near 
    push ax
	push bx
	push dx
	mov cx,0                    ;（CX，DX）=图形坐标列（x）、行（Y）。
	mov bh,0                    ; BH = 页码
	mov ah,0ch                 ;写图形像素
line:
	int 10h
	inc cx
	cmp cx,320
	jl line
	pop dx
	pop bx
	pop ax
	ret
vline endp
end