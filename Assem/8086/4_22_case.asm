data segment
    x db -12H
    result dw  0000H
data ends

code segment
    assume cs:code, ds:data
start:
    mov ax, data
    mov ds, ax            ;�������ݶ�
    mov al, x             ;ȡx��al
    test al , 0FFH        ;al��FFH����,�ı�SF��־λ��(��ĸ��ͷ��0)
    js next               ;����λSFΪ1(����)����ת��next
    mov bl, al            ;����x���Ƶ�bl
    imul bl               ;����(x^2)������ax  
    add ax,1              ;����(x^2+1) ������ax
    jmp next1             ;��ת��next1
next:
    mov bl, 02H           
    imul bl               ;����(2*x)������ax  
    add ax, 0005H         ;����(2*x+5)������ax
next1:
    mov result, ax        ;������͸�result      DS:0001 = FFE1 
    
    mov ah,4cH            ;����dos
    int 21H               ;
code ends

end start
