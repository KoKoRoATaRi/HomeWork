#include<vector>
#include<algorithm> 
#include<iostream>
using namespace std;
class A
{
	int v;
	public:
		A(int n):v(n){
		}
		
		bool operator <(const A& a2)const
		{
			cout<<v<<"<"<<a2.v<<"?"<<endl;
			return false;
		}
		//�涨����������Զ��������� 
		bool operator ==(const A& a2)const{
			cout<<v<<"=="<<a2.v <<"?"<<endl;
			return v==a2.v;
		}
};
int main()
{
	A a[]={A(1),A(2),A(3),A(4),A(5)};
	cout<<binary_search(a,a+4,A(9));
	 //���ֲ���
//	 3<9?
//	 2<9?
//	 1<9?
//	 9<1?
//	 �����ҵ�9 
}
