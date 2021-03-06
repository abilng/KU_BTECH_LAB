DATA SEGMENT
MSG1 DB 0AH,0DH,"ENTER THE 1-ST NO:$"
MSG2 DB 0AH,0DH,"ENTER THE 2-ND NO:$"
MSG3 DB 0AH,0DH,"RESULT IS:$"
NUM1 DB 8 DUP(?)
NUM2 DB 8 DUP(?)
SUM DB 9 DUP(?)
DIFF DB 8 DUP(?)
DATA ENDS 


CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:MOV AX,DATA
	MOV DS,AX
	XOR BX,BX	
	MOV AH,09H
	LEA DX,MSG1
	INT 21H
	MOV CL,08H
	MOV SI,OFFSET NUM1
LOOP1:	MOV AH,01H
	INT 21H
	XOR AH,AH
	SUB AL,30H
	MOV [SI],AL
	INC SI
	DEC CL
	JNZ LOOP1
	MOV AH,09H
	LEA DX,MSG2
	INT 21H
	MOV CL,08H
	MOV SI,OFFSET NUM2
LOOP2	:MOV AH,01H
	INT 21H
	XOR AH,AH
	SUB AL,30H
	MOV [SI],AL
	INC SI
	DEC CL
	JNZ LOOP2
	XOR AH,AH
	MOV AL,OFFSET NUM1
	ADD AL,07H
	MOV DI,AX
	MOV AL,OFFSET NUM2
	ADD AL,07H
	XOR AH,AH
	MOV SI,AX
	MOV CL,08H
	MOV DL,09H
	MOV DH,00H
LOOP3:	XOR AH,AH
	MOV AL,[DI]
	XOR BH,BH
	MOV BL,[SI]
	SUB AL,BL
	SUB AL,DH
	DAA
	CMP AL,DL
	JG CARRY
	MOV [DI],AL
	MOV DH,00H
	JMP NEXT
CARRY:SUM AL,0AH
	MOV [DI],AL
	MOV DH,01H
	NEXT:DEC SI
	DEC DI
	DEC CL
	JNZ LOOP3
	MOV AH,09H
	LEA DX,MSG3
	INT 21H
	MOV DL,DH
	XOR AH,AH
	ADD DL,30H
	MOV AH,02H
	INT 21H
	MOV CL,08H
	MOV SI,OFFSET NUM1

CONVERT:XOR AH,AH
	MOV AL,[SI]
	ADD AL,30H
	MOV DL,AL
	XOR DH,DH
	MOV AH,02H
	INT 21H
	INC SI
	DEC CL
	JNZ CONVERT
	MOV AH,4CH
	INT 21H
CODE ENDS
	END START
