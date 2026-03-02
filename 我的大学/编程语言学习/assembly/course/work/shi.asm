.MODEL SMALL
.DATA
RESULT DW 2A3CH
.CODE
start:
    mov AX,@DATA
    MOV DS,AX
    MOV AX,RESULT
    MOV CX,0
    MOV DX,0
    MOV BX,10
AGAIN:
    DIV BX  ;(AX)=(DX.AX)/10 的商
    PUSH DX ;(DX)=(DX,AX)/10 的余数
    INC CX
    CMP AX,0
    JE DISP
    MOV DX,0
    JMP AGAIN
DISP:
    POP DX
    ADD DL,'0'
    MOV AH,02H
    INT 21H
    LOOP DISP
    ret
END start