;BLOCK MOV

data segment
	msg1 DB 09h,'enter string',0Ah,0Dh,'$'
	msg2 DB 0Dh,0Ah,'Reversed string is',0Ah,0Dh,'$'
	namepar label byte
	maxlen DB 20
	actlen DB ?
	namefld DB 20 dup(' ')
	RFLD DB 20 DUP(' ')
data ends

code segment
	assume cs:code,ds:data
start : mov Ax,data
	mov ds,Ax 
	lea dx,msg1
	mov ah,09h
	int 21h
	mov ah,0ah
	lea dx,namepar
	int 21h

	MOV SI,OFFSET NAMEFLD
	MOV DI,OFFSET RFLD
	XOR CX,CX
	MOV CL,ACTLEN
	ADD DI,CX
	DEC DI

L:	MOV DL,[SI]
	MOV [DI],DL 
	dec DI
	INC SI
	LOOP L

	mov bh,00h
	mov bl,actlen
	mov RFLD[bx+1],'$'
	lea dx,msg2
	mov ah,09h
	int 21h
	lea dx,RFLD
	mov ah,09h
	int 21h
	mov ah,4ch
	int 21h
code ends
end start
