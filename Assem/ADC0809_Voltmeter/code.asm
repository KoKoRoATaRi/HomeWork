data segment
dat db ?,?,?,?                                             ;�����ÿһλ������,���������ݶ�,���������չ
count equ ($-dat)
TableDot db  40H,79H,24H,30H,19H,12H,02H,78H,00H,10H       ;�����ܴ�С����0-9
Table    db  0C0H,0f9H,0a4H,0b0H,99H,92H,82H,0f8H,80H,90H  ;�����ܲ���С����0-9
Vrefp db 5                                                 ;�ο���ѹֵ
data ends

stack segment
db 100 dup(0)
stack ends

code segment
assume cs:code,ds:data,ss:stack
start:
	mov ax,data
	mov ds,ax
	mov ax,stack
	mov ss,ax
	mov sp,100
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;��ʼ��
                         ;1111111111000XX0
	mov dx,0FFC6H        ;8255��ַ���ƿ�           
	mov al,10011000B     ;1-����λ  00-A��ʽ0  1-A���� 1-CH���� 0-B��ʽ0 0-B��� 0-CL���   
	out DX,al            ;д�������      

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;����ģ��ת������������
again:	
	mov dx,0FFC8H        ;����ADC0809                     1111111111001XX0          
	mov al,11111000B     ; ADDA ADDB ADDC��ѡ��ͨ��0      XXXXX000
	out dx,al
	
	mov dx,0FFC4H      
	mov al,11100000B
	out dx,al             ;8255C��״̬����,�ٴ�8255��C��
		
	
ready:
	in al,dx
	cmp al,11110000B 
	jnz ready            ;�ȴ�ADC0809ת������,����ѭ�����
	mov dx,0FFC8H          
	in al,dx             ;��ȡת������

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;��������
	lea bx,dat
	mov cx,count
	mov ah,Vrefp  	
	mul ah               ;(VrefP * ��ȡ����)/255
	mov dl,0FFH	
loop_:
	div dl           
	mov [bx],al          ;���õ������ݱ�������
	mov al,ah            ;�õ���������al
	mov ah,10
	mul ah               ;������10
	inc bx
loop loop_
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;��λ��Ҫ��С����,��˵�������
	xor bx,bx
	mov bl,dat
	mov dx,0FFC2H        ;8255B��
	mov al,TableDot[bx]
	out dx,al            ;�����B��
	mov dx,0FFC4H       
	mov al,00000001B
	out dx,al           
	call delay
	mov al,00H
	out dx,al	         ;Ϩ��

	mov si,1
	mov cx,count
	dec cx
	mov ah,00000010B
;;;;;;;;;;;;;;;;;;;;;;;;;;;;ʮ��λ���ٷ�λ��ǧ��λ.....ѭ������
loop__:
	xor bx,bx            ;bx����
	mov bl,dat[si]       ;�����ݶ�ȡ����
	mov dx,0FFC2H        ;8255B��
	mov al,Table[bx]     ;�ڹ��������ҵ�����ܵ�ƽ����
	out dx,al            ;�����B��
	mov dx,0FFC4H              
	mov al,ah
	out dx,al	         ;8255C�ڵ��������
	call delay           ;��ʱһ��ʱ��
	mov al,00H
	out dx,al	         ;Ϩ��
	inc si
	shl ah,1
loop loop__
	
	jmp again
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

delay proc near
	push cx
	mov cx,00FFH
	loop $
	pop cx
	ret
delay endp
code ends
end start
