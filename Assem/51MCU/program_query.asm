ORG 0000H
ajmp start
org 0030H
start:
   clr EA
   clr ET0
   mov tmod,#00H
s_call:
	acall service
loop:
   jb TF0,s_call
   ajmp loop
;�ӳ���
service:
   mov TH0,	#0E0H	 ;����������ֵ
   mov TL0,	#18H	 ;
   setb TR0			 ;����������
   clr tf0			 ;�жϱ�־λ����
   cpl p1.0		
   ret

end
;����12MHZ,��������=1/12M*(12)=1us
;1ms,��ֵ=2^13-1ms/1us=7192=1110000011000
;��8λ=E0H,��5λ=18H