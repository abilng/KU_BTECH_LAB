DATA SEGMENT
	MSG1 DB 0AH,0DH,'ENTER THE 1-ST STRING :$',09H
	MSG2 DB 0AH,0DH,'ENTER THE 2-ND STRING :$',09H
	MSG3 DB 0AH,0DH,'AFTER REPLACEMENT :$',09H
	MSG4 DB 0AH,0DH,'STRING 1 :$',09H
	MSG5 DB 0AH,0DH,'STRING 2 :$',09H
	ENDCHR DB '$'
	namepar1 label byte
	maxlen1 DB 20
	actlen1 DB ?
	namefld1 DB 20 dup(' ')
	
	namepar2 label byte
	maxlen2 DB 20
	actlen2 DB ?
	namefld2 DB 20 dup(' ')
DATA ENDS
	
PRINTL MACRO A
	LEA DX,A
	MOV AH,09H
	INT 21H
ENDM
	
READL MACRO A
	LEA DX,A
	MOV AH,0AH
	INT 21H
ENDM
	
CODE SEGMENT
ASSUME CS:CODE,DS:DATA

START:	MOV AX,DATA
	MOV DS,AX
	PRINTL MSG1
	READL NAMEPAR1
	PRINTL MSG2
	READL NAMEPAR2
	MOV SI,OFFSET NAMEFLD1
	MOV DI,OFFSET NAMEFLD2
	XOR CX,CX
	MOV CL,ACTLEN1
	;CLD

MOVE:	MOV AL,[SI]
	MOV [DI],AL
	INC SI
	INC DI
	LOOP MOVE
	
	MOV AL,ENDCHR
	MOV [DI],AL
	MOV [SI],AL
	PRINTL MSG3
	PRINTL MSG4
	PRINTL NAMEFLD1
	PRINTL MSG5
	PRINTL NAMEFLD2
	MOV AH,4CH
	INT 21H
CODE ENDS
END START
