
#include<iostream>
using namespace std; 

template <class ElemType>   // ģ���� 
class SSTable
{
	public:
		ElemType * elem;
		int length;
		void print()
		{
			cout << "���е�Ԫ����:";
			for( int i = 0 ; i < length ; i++)
				cout << elem [i] <<' ';
			cout<<endl;
			
		};
		SSTable ( int n):length(n)
		{
			elem = new 	ElemType [n];
			cout << "������"<<n<<"��Ԫ��:"; 
			for( int i = 0; i < length ;i++)
			{
				cin >> elem[i];
			}
			
			cout<<endl<<"������ϡ�";
		};
		virtual	~SSTable ()
		{
			delete []elem;
		}; 
		int Search_Seq( auto key  );
};

template <class ElemType>
int SSTable< ElemType >:: Search_Seq( auto key  )//ʹ��auto���������ղ�ͬ���Ͳ���,����Ԫ���ڱ��е��±꣬0Ϊ��ʼ 
{
	for ( int i =0 ; i < length; i++)
	{
		if( elem[i] == key)
		{
			cout<< "Ԫ�����ҵ���λ��Ϊ"; 
			cout<< i <<endl;
			return i;
		} 
	}
	cout << "Ԫ��δ�ҵ���"<<endl;
	return 0;
}

