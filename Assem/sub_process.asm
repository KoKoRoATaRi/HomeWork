data segment
ARY dw 3,1,2,-3
sum dw 0
data ends
code segment
	assume ds:data,cs:code
start:
	mov ax,data
	mov ds,ax
	call sum_ 
	mov sum,ax
	mov ah,4ch
	int 21h
	hlt
sum_ proc near          ;����ӳ���
	push cx        ;��� ARY
	push si        ;���� AX
	push bx
	mov cx,ARY
	lea si,ARY 
	mov ax,0000H
	
loop_:  
	add si,2
	mov bx,[si]
	cmp bx,0
	jnl abs
	neg bx
	abs:
	add ax,bx
	loop loop_ 
	pop bx
	pop si
	pop cx 
	ret 
code ends
end start