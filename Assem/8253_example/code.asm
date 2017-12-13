data segment
music dw 1518,1805,1805,1704,2027,2027,2275,2027,1805,1704,1518,1518,1518
count equ ($-music)/2
data ends

code segment
	assume cs:code,ds:data
	mov ax,data
	mov ds,ax
start:
	mov cx,count
	lea si,music
loop_:
	mov dx,0303H
	mov al,00001100B       ;PC6����
	out dx,al
	mov al,00000000B       ;PC0����
	out dx,al             
			      ;8255��ʼ��
	
	mov dx,0307H
	mov al,10110110B       ;10--������2  11--�ȶ�/д���ֽ� 011--��ʽ3 0--��������
	out dx,al
	                      ;8253��ʼ��
	mov ax,[si]
	mov dx,0306H
	out dx,al
	mov al,ah
	out dx,al       
			      ;����
	mov dx,0303H
	mov al,00001101B       ;PC6��1
	out dx,al
	mov al,00000001B
	out dx,al	      ;PC1��1
	
	call delay            ;�ӳ�
	inc si
	loop loop_
	
	mov ah,4ch
	int 21h

delay proc delay
	push cx
	mov bx,00ffH
delay_0:
	mov cx,0000H
delay_1:
	loop delay_1
 	dec bx
	jnz delay_0
	pop cx
	ret
delay endp


code ends
end start
	