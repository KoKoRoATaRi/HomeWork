/*����

�������� n ( 0 <=n<= 2^30) , �Լ�����i,j(0 <= i,j <31,i < j-1), �������k(��ʮ������������ )��k�ĵ�iλ��n��ͬ����jλ��n��ͬ��i,j֮���λ��1, ����λ����0�������ᵽ�����е�λ��ָ�Ķ��Ƕ�����λ�����ұ����0λ��

����

��һ�������� t����ʾ����������

ÿ������������һ�У��������� n,i��j��

���

��ÿ���������ݣ���ʮ��������������*/
#include <iostream>
using namespace std;
int main()
{
    int counts;
    cin >> counts;
    while(counts--)
    {
        int n, i, j;
        cin >> n >> i >>j;
        int result = 0;
        if (n & (1 << i))//n�ĵ�iλΪ1
        {
            result |= 1 << i;
        }
        if (!(n & (1 << j)))//n�ĵ�jλΪ0
        {
            result |= 1 << j;
        }
        for (int k = i+1; k < j; k++)
        {
            result |= 1 << k;
        }
        cout << hex << result << endl;
    }
    return 0;
}
