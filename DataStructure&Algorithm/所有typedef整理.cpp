#include<iostream> 
using namespace std;
#define m0 100
/*
���� 
*/
typedef int vector[m0];
/*
��ջ 
*/
typedef struct SeqStack
{
	int top = 0;
	char data[m0];	
}SeqStack;
/*
���� 
*/
typedef struct SeqQueue
{
	char data[m0];
	int front = 0;
	int rear = 0;
}SeqQueue;
/*
���� 
*/
typedef struct Node
{
	struct Node * nextNode;
	char  data;	
}Node;
/*
˫������ 
*/
typedef struct dNode
{
	struct dNode * next;
	struct dNode * prior;
	char data;
}dNode;
/*
������  ����洢 
*/
typedef char sqbtree[m0]; 
/*
������  ��ʽ�洢 
*/
typedef struct btNode
{
	char data;
	struct btNode * left;
	struct btNode * right;
}btNode; 
/*
ͼ  
*/
typedef struct vexnode 
{
	char vexdata;
	char * otherinfo;
}vexnode;
/*
��������
*/ 
typedef vexnode vex[m0];
/*
�ڽӾ���
*/
typedef int adjmatrix[m0][m0];
/*
���ӱ� 
*/
typedef struct adjnode
{
	int vexnum;//ÿһ���㶼�б�� 
	int weight;//ÿһ�����Ȩ 
	struct adjnode *next;//��һ�� 
} adjnode;//�����ڽӽڵ� 
typedef struct vexnode
{
	char vexdata;
	adjnode * link;
}vexnode;//�����ͷ�ڵ� 
typedef vexnode A[m0];//�����ͷ ���� 

int main()
{

	vector a;
	SeqStack s;
	SeqQueue q;
	dNode d;
	cout<<s.top;
	cout<<q.front<<q.rear;
	static int x = 100;
	cout<<endl<<endl<<x;
}
