#ifndef SSTABLE_H
#define SSTABLE_H
#endif 
#include<iostream>
using namespace std;
template <class ElemType>
class BSTable : public SSTable<ElemType>    //��SSTable������BSTable  
{
	public:
		BSTable ( int n): SSTable<ElemType> (n)
		{
			cout<<"��ʼ����"<<endl;                //�ڹ��캯����������� 
			int i, j;
			ElemType temp;
		    for (j = 0; j < this->length - 1; j++)
		        for (i = 0; i < this->length - 1 - j; i++)
		        {
		            if(this->elem[i] > this->elem[i + 1])
		            {
		                temp = this->elem[i];
		                this->elem[i] = this->elem[i + 1];
		                this->elem[i + 1] = temp;
		            }
		        }
			cout<<"�������,��ǰ����Ԫ��Ϊ:";
			for (int i = 0; i < this->length; i++)
			{
				cout << this->elem[i]<<' ';
			}
			cout<<endl;
		};
		int Search_Bia( auto key )   //�۰���ң�ʹ��auto���������ղ�ͬ���Ͳ���,����Ԫ���ڱ��е��±꣬0Ϊ��ʼ.
		{
			int low = 0;
			int high = this->length; 
			while(low <= high)
	        {
	            int mid = (low+high) / 2;
	            if( this->elem [mid] > key )
	                high = mid-1;
	            else if ( this->elem[mid] < key )
	            	low = mid+1;
	            else
				{
					cout << "Ԫ�����ҵ���λ��Ϊ";
					cout << mid <<endl; 
					return mid;
				}
	                
	        }
	        cout<<"Ԫ��δ�ҵ���"<<endl;
    		return -1;
		}
	
}; 
