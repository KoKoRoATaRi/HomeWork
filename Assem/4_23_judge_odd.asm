DATA SEGMENT
	NUM1 DB 45H
	NUM2 DB 0AEH
	DATA1 DB 0
	DATA2 DB 0
DATA ENDS

CODE SEGMENT
	ASSUME CS:CODE,DS:DATA

BEGIN:
	MOV AX, DATA
	MOV DS, AX
	MOV AL, NUM1
	MOV AH, NUM2
	TEST AL, 01H       ;45H��01H����,�����ȫΪ0(����),ʹZF = 0
	JNZ NEXT1          ;��ALΪ������ת��NEXT1
	TEST AH, 01H       ;AE��01����
	JNZ NEXT2          ;��Ϊ����,��ת��NEXT2
	INC AL             ;��AL,AHͬΪż��,AL+1
	INC AH             ;AH+1
	JMP ENDO           ;��ת��ENDO
	
NEXT2:
	XCHG AL,AH         ;��������
	JMP ENDO
NEXT1:
	TEST AH,01H        ;��AHΪż��,AF��ֵ��01����,ZF = 1
	JZ ENDO            ;��AHΪż����ת��endo
	DEC AL             ;����AL -1, AH-1
	DEC AH
ENDO:                  
    MOV DATA1,AL       ;����͸�data1    DS:0002 = 45      
    MOV DATA2,AH       ;����͸�data2    DS:0003 = AE
    
    MOV AH,4CH         ;����DOS
    INT 21H
CODE ENDS
    END BEGIN
