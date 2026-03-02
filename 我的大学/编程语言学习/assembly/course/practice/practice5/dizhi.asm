data segment
	table dw prog0,prog1,prog2,progo0
	mess1 db 0ah,Odh,'input0-2:$'
	mess2 db Oah,Odh,'z=x+y=$'
	x db 3
	y db 6
	z db ?
data ends
code segment
assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
let0:
	mov dx,offset mess1
	mov ah,9
	int 21h
	mov ah,1
	int 21h
	and al,03h
	mov ah,0
	shl ax,1
	mov bx.ax
	jmp table[bx]
prog1:
	mov dx,offset mess2
	moy ah.9
	int 21h
	mov al,x
	add al,y
	mov z,al
	add al,30h
	moy dl,al
	mov ah,2
	int 21h
	jmp let0
prog2:
	mov dl,0ah
	mov ah,2
	int 2lh
	mov ah,1
	int 2lh
	test al,20h
	jz transfer
	and al,0dfh
	jmp display
transfer:
	or al,20h
display:
	moy dl,al
	mov ah,2
	int 21h
	jmp let0
prog0:
	mov ah,4ch
	int 21h
code ends
end start