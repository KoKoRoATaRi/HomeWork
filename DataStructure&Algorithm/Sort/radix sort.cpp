#include<iostream>
#include<vector>
#include<list>
using namespace std;
template<class T>
void ShellSort(T *data , int len)
{
	
} 


int main()
{
	list<int>n[10];//���������10��Ͱ 
	int b[10] = { 278, 109, 063, 930, 589, 184, 505, 269, 8, 83 };//�������� 
	list<int> temp; //��ʱ���� 
	for( int i = 0 ;i <10 ; i++ )
	{
			n[ b[i]%10 ].push_front( b[i] );//�Ը�λ��Ϊ��׼����� 
	}
		
	for(int i = 9 ; i >= 0 ;i--)
		{
			while( !n[i].empty() )
			{
				temp.push_front( n[i].front() );
				n[i].pop_front(); 
			}
		}
		while(!temp.empty())
		{
			cout<< temp.front()<<endl;
			temp.pop_front();
		}
		//���������һ����δ����� 
}
