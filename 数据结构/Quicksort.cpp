#include<iostream>
#include<vector>
using namespace std; 
void Qsort(int a[], int low, int high )
{
    if(low >= high)
    {
        return ;
    }
    int first = low;
    int last = high;
    int key = a[first];/*���ֱ�ĵ�һ����¼��Ϊ����*/
 
    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }
 
        a[first] = a[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/
 
        while(first < last && a[first] <= key)
        {
            ++first;
        }
         
        a[last] = a[first];    
/*���ȵ�һ������Ƶ��߶�*/
    }
    a[first] = key;/*�����¼��λ*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}
int main()
{
	int a[] = {49,38,65,97,76,13,27,49};
	
	Qsort(a,0,sizeof(a)/sizeof(a[0])-1);
	for(int i = 0; i <sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << endl;
	}
}


