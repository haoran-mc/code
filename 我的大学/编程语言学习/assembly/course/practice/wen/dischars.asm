.model small
.data
char db 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
col db 0
row db 10
flgs db 0ffh
.code
main proc far
	mov ax, @data
	mov ds,ax
	
	mov ah,0
	mov al,06h
	int 10h
LOP1: lea bx,char
		push bx
		mov dl,col
		mov cx,26
LOP2: 	mov ah,2
		mov bh,0
		mov dl,row
		inc dl
		int 10h
		pop bx
		mov al,[bx]
		inc bx
		push bx
		push cx
		mov ah,10
		mov bh,0
		mov cx,1
		int 10h
		pop cx
		loop LOP2
		pop bx
		mov ah,0
		int 16h
		not flgs
		cmp flgs,0
		jne quit
		mov ah,0
		mov al,3
		int 10h
		jmp LOP1

quit:	mov ah,4ch
	int 21h
main endp

end