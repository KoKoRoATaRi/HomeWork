#include<iostream>
#include<stdio.h>
#define m0 100
using namespace std;
typedef struct seqQueue
{
	char data[m0];
	int front,rear;
}seqQueue;

seqQueue* initSeqQueue()
{
	seqQueue *p;       //
	p=new seqQueue;
	p->front =0;
	p->rear =0;
	return p;
}

int emptySeqQueue(seqQueue *s)
{
	if(s->front ==s->rear )
	{
		return 1;
	}
	else 
		return 0;
}

int inSeqQueue(seqQueue *s,char x)
{
	if(s->rear -s->front >m0)
	{
		cout<<"�����������"; 
		return 0;
	}
	else 
	{
		s->data [s->rear]=x;
		s->rear++;
	}
//	while(s->front !=0)
//	{
//		for(int i=s->front ;i<=s->rear;i++)
//		{
//			s->data[s->front-1]=s->data[s->front ];
//		}
//		s->front --;
//		s->rear --;
//	}	//Ԫ��ǰ�ƣ���ʡ�ռ� ������� 
	
}
int outSeqQueue (seqQueue *s, char &x)
{
	if(emptySeqQueue(s))
	{
		printf("�ӿղ��ܳ��ӣ�\n");
		return 0;
	}
	else 
	{
		x=s->data [s->front];
		s->data [s->front++];
		return 1;
	}
}

char frontSeqQueue(seqQueue *s)
{
	if(emptySeqQueue(s))
	return 0;
	else 
	return (s->data [s->front]);
}	//�鿴��ͷԪ�� 

char rearSeqQueue(seqQueue *s)
{
	if(emptySeqQueue(s))
	return 0;
	else 
	return (s->data [(s->rear)-1]);
}	//�鿴��βԪ�� 
int main()
{
	seqQueue *p=initSeqQueue();//��ʼ��һ������ 
	inSeqQueue(p,'l');//����� l 
	inSeqQueue(p,'o');//����� o
	inSeqQueue(p,'v');//����� v
	inSeqQueue(p,'e');//����� e
	
	cout<<"��ͷԪ���ǣ�"<<frontSeqQueue(p)<<endl<<"��βԪ����"<<rearSeqQueue(p)<<endl;
	char x;
	cout<<"������:"<<endl;
	outSeqQueue(p,x);
	cout<<x<<endl;
	outSeqQueue(p,x);
	cout<<x<<endl;
	outSeqQueue(p,x);
	cout<<x<<endl;
	outSeqQueue(p,x);
	cout<<x<<endl;
	
	outSeqQueue(p,x);//������Ϊ��ʱ�������� 
}



