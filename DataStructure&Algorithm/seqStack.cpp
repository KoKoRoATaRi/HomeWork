#include<stdio.h> 
#include<stdlib.h>
#define m0 100
typedef struct SeqStack
{
	char data[m0];
	int top;
}SeqStack;

 SeqStack* Init_SeqStack()
{
	SeqStack *s;
	s=(SeqStack*)malloc(sizeof(SeqStack));
	s->top =0;
	return s;
 }
int Empty_SeqStack(SeqStack *s)
{
	if(s->top ==0)
	return 1;
	else return 0;
}
int Push_SeqStack(SeqStack *s,char x)
{
	if(s->top==m0)
	{
		printf("ջ��������ջ��\n");
		return 0;
	}
	else
	{
		s->data[s->top]=x;
		s->top++;
	}
}

int Pop_SeqStack(SeqStack *s, char &x)
{
	if(Empty_SeqStack(s))
	{
		printf("ջ�ղ��ܳ�ջ��\n");
		return 0;
	}
	else 
	{
		s->top--;
		x=s->data [s->top];
		return 1;
	}
}

char Top_SeqStack(SeqStack *s)
{
	if(Empty_SeqStack(s))
	return 0;
	else 
	return (s->data [--s->top ]);
}

int main()
{SeqStack *stack; char x;
 stack= Init_SeqStack();//��ʼ����ջ
 Push_SeqStack (stack,  'a');//a��b��c����Ԫ�������ջ
 Push_SeqStack (stack,  'b');
 Push_SeqStack (stack,  'c');
 x=Top_SeqStack(stack);//ȡջ��Ԫ�أ������
 printf("��ǰջ��Ԫ���ǣ�%c\n",x);
 stack->top++;
 printf("��ջ���У�"); //ջ��Ԫ�����γ�ջ
 Pop_SeqStack(stack, x);
 printf("%c",x);
 Pop_SeqStack(stack, x);
 printf("%c",x);
 Pop_SeqStack(stack, x);
 printf("%c",x);
}
 
