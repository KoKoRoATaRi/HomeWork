data segment
    abc db 43H                                                    
    abc1 db 0
data ends
CODE segment
    assume cs:CODE, ds:data
start:
    mov ax,data
    mov ds,ax                 ;�������ݶ�            
    mov bx,offset abc         ;��abc��ƫ������BX          BX = 0000    
    mov al, [bx]              ;ʹ��BX��Ϊ����ַ��DS�μ��Ѱַ��abc�洢��al��    AL = 43
    inc bx                    ;BX+1                       BX = 0001
    cmp al, 3ah               ;�Ƚ��޷�����abc��3a�Ĵ�С���ж���Ϊ���ֻ�����ĸ
    jc next                   ;43<3a ��˲�������ת  
    sub al,37h                ;43H - 37H��������al        AL = 0C
    jmp next1                 ;������ת����next1
next:
    sub al,30h
next1:
    mov [bx],al               ;��0CH�Լ��Ѱַ�ķ�ʽ������abc1 DS:0001 = 0C
    mov ah,4ch                ;
    int 21h                   ;����dos                    
    CODE ends
    end start