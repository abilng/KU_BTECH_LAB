;PALINDROME MOV
	
data segment
	msg1 DB 09h,'enter string',0Ah,0Dh,'$'
	msg2 DB 0Dh,0Ah,'PALINDROME',0Ah,0Dh,'$'
	msg3 DB 0Dh,0Ah,'NOT PALINDROME',0Ah,0Dh,'$'
	namepar label byte
	maxlen DB 20
	actlen DB ?
	namefld DB 20 dup(' ')
		
data ends

code segment
assume cs:code,ds:data

start : 
	mov Ax,data
	mov ds,Ax 
	lea dx,msg1
	mov ah,09h
	int 21h
	mov ah,0ah
	lea dx,namepar
	int 21h
	
	
	
	MOV SI,OFFSET NAMEFLD
	MOV DI,OFFSET NAMEFLD
	XOR CX,CX
	MOV CL,ACTLEN
	
	
	ADD DI,CX
	DEC DI
	
L:
	MOV DL,[SI]
	CMP [DI],DL 
	JNE L2
	dec DI
	INC SI
	LOOP L
	
	lea dx,msg2
	mov ah,09h
	int 21h
	JMP L1
L2:
	lea dx,msg3
	mov ah,09h
	int 21h
L1:
	mov ah,4ch
	int 21h

code ends
end start
