#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class CMy_add
{
	int & num; // num ������Ϊ���� 
	public :
	CMy_add ( int & n):num(n){};// my_sum���� n , n ���� m;  
	void operator ()(int t)
	{
		num = num + t % 8;
	}
};
int main(int argc, char* argv[]) {
        int v, my_sum=0;
        vector<int> vec;
        cin>>v;
        while ( v ) {
                vec.push_back(v);
                cin>>v;
        }
        for_each(vec.begin(), vec.end(), CMy_add(my_sum));//CMy_add(my_sum)Ϊһ������ 
        cout<<my_sum<<endl;
        return 0;
}
