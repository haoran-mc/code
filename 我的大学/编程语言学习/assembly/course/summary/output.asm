code segment
assume cs:code
strat:
    mov ah,7
    int 21h
    cmp al,0dh
    jz exit
    mov dl,'*'
    mov ah,2
    int 21h
    jmp start
exit:
    mov ah,4ch
    int 21h
code ends
end start
