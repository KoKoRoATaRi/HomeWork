#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<map>
// �������ַ��� T,ʹ���ַ��� A �� 'a' - 'z' �滻Ϊ T�е� 1-26 �����滻��� A�� B��ͬ ����� A �� B���ơ�
//��A�й��ж��ٸ���B���Ƶ��Ӵ��� 
//�������� 
 //ababcb
//xyx
//������� 
// 3  
//˵����ԭ�� -> ӳ��
//aba ->xyx    bab -> xyx   bcb -> yxy
using namespace std;
/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ 
******************************��ʼд����******************************/
map<char,char> m; 
int solve(string S, string T) {
	int cnt = 0;
    for(int i=0; i <= S.size() - T.size() ;i++)
    {
    	bool flag = true;
        string tmp = S.substr(i,T.size());
        for(int j = 0;j < tmp.size() ;j ++)
        {
            if(!m.count(T[j]))
            {
            	m[T[j]] = tmp[j]; 
			}
			else if(m[T[j]] == tmp[j] )
			{
				continue;
			}
			else
			{
				flag = false;
				break;
			}
        }
        if(flag)
            cnt++;
        m.clear();
    }
    cout << cnt << endl;
    return cnt;

}
/******************************����д����******************************/


int main() {
    int res;

    string _S;
    getline(cin, _S);
    string _T;
    getline(cin, _T);
    
    res = solve(_S, _T);
    cout << res << endl;
    
    return 0;

}

