code segment
    assume cs:code     
start:
    mov AX, -1234H
    cmp ax, 0		    ;�Ƚ�ax��0�Ĵ�С		
    jge next            ;��ax>0,��תnext
    neg ax              ;��ax<0,����
next:
    mov bx, ax          ;�����������bx        BX = 1234
next1:
    mov ah, 4ch		;����dos
    int 21h
code ends
end start