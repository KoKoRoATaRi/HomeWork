#include<stdio.h> 
#include<iostream>
using namespace std;
typedef struct loopNode
{
	int password, num;
	struct loopNode * nextNode;
} loopNode;

loopNode * creatNode( int m ) //�������� 
{
	loopNode * head, * p, *s;  
	head = new loopNode;
	p = head;
	for( int i=0; i<m ; i++ )
	{
		s = new loopNode;
		scanf( "%d,%d", &s-> num, &s-> password);
		p-> nextNode = s;
		p = s;
	}
	p-> nextNode = head-> nextNode;
	return head;
}

void outList(loopNode * p )//������� 
{
	loopNode * head = p;
	p = p-> nextNode;
	do
	{
		cout<< p->num <<","<< p->password <<"->";
		p = p-> nextNode;
	}
	while( p != head-> nextNode );
	cout << "ѭ�ص���һ���ڵ�!" << endl; 
}

void outQuee( loopNode *q, int m ) //������� 
{
	loopNode *p = q-> nextNode;
	while( p-> nextNode != p )
	{
		for( int i = 0 ;i < m-1 ; i++ )
		{
			p = p-> nextNode ;
			q = q-> nextNode ;
		}
		cout << p-> num << ',' ;
		m = p-> password ;
		q-> nextNode = p-> nextNode ;
		p = p-> nextNode ;
	}
	cout << p-> num <<endl;	
}
int main()
{
	int m = 0;
	cout << endl << "������μ�����:" ;
	cin >> m; 
	cout << endl;
	cout << "���ȣ�����Լɪ�򻷣������õ�ѭ������洢�ṹ��" << endl; 
	loopNode * p = creatNode( m );
	cout << "Լɪ��Ϊ:" << endl;
	outList( p );
	cout << "��������ʼ����ֵ:"; 
	cin >> m;
	cout << endl;
	cout << "���ֳ���������:";
	outQuee( p , m);
}
