#include <iostream>
#include"SSTable.h"
#include "BSTable.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	cout<<"--------------------------SSTable ����--------------------------"<<endl; 
	SSTable<int> s1(5);   //�������С�ɱ仯 
	int target;
	cout << "�����������Ԫ��:"; 
	cin >> target;
    s1.Search_Seq(target);	
	cout<< "--------------------------BSTable ����--------------------------"<<endl;
	BSTable<int> s2(5);    //�������С�ɱ仯
	cout << "�����������Ԫ��:"; 
	cin >> target;
	cout<<"˳����ң�"<<endl; 
    s2.Search_Seq( target );  //s2�̳и���� Search_Seq
    cout<<"�۰���ң�"<<endl;
    s2.Search_Bia( target );  
	
	return 0;
}
