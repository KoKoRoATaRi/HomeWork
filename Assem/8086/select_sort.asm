data segment
    BUF db 26,20,23,21,12,45,62,4,2,5,6,12
    count equ $-BUF
data ends     
code segment
    assume ds:data,cs:code
start:
    mov ax,data
    mov ds,ax
    mov cx,count
    lea si,buf
  
loop1:
    push cx
    push si
    mov al,[si]                    

loop2: 
    cmp al,[si]
    jb notchange
    mov al,[si]
    mov bx,si                      ;al���浱ǰֵ
notchange:                         ;bx����ȵ�ǰֵ��С��ƫ�Ƶ�ַ
    inc si
    loop loop2

    pop si
    xchg al,[si]                   ;ʹ��si,al,bx�ֱ𱣴� ��ǰֵ,��Сֵ,��Сֵλ��
    xchg al,[bx]                   ;��ɽ���
                                   ;�ָ�cx,si    
    pop cx                                         
    inc si
    loop loop1

    mov ah,4ch
    int 21h
code ends
end start