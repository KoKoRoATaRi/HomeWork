#include <iostream>
using namespace std;
// �ڴ˴�������Ĵ���
int sum(int *a, int n ,int (*f)(int) )
{
	int t = 0;
	for( int i = 0; i < n; i ++)
	{
		t = t + f( a[i] );
	}	
	return t; 
} //����ָ����÷� 
int sqr(int n) {
    return n * n;
}
int main() {
    int t, n, a[0x100];
    cin >> t;
    for (int c = 0; c < t; ++c) {
        cin >> n;
    for (int i = 0; i < n; ++i) 
	cin >> a[i];
    cout << sum(a, n, sqr) << endl;
    }
    return 0;
}
