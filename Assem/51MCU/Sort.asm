org 0000H
mov 20H,#39
mov 21H,#27
mov 22H,#13
mov 23H,#44
mov 24H,#78
mov 25H,#22
mov 26H,#6
mov 27H,#51
Ljmp start
org 0030H
start:
	call sort
	sjmp $

sort:
mov r6,#7	   ;8�����ݣ��Ƚ�7��
s1:
	mov r0,#20H	;��ʼ��ַ
	mov b,r6
	mov r7,b
	clr psw.5
s2:
	mov b,@R0	;ȡ��ǰһ����
	inc r0
	mov a,@r0	;ȡ����һ����
	cjne a,b,s3	 ;��-ǰ
s3:
	jnc N_JH	;�������ý���
	mov @r0,B   ;����
	dec r0
	mov @r0,A
	inc r0
	setb psw.5	 ;����������־λ
N_JH:
	djnz r7,s2
	jnb psw.5,S_END	 ;û�н������ͽ���
	djnz r6,s1
S_END:
	ret
end