#include <iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n): num(n) {
    }
// �ڴ˴�������Ĵ���
	Number operator + (Number &t)
	{
		num = num+t.num ; 
		return *this;
	}
	int& value()
	{
		return num;
	} //������������������ã�ʹ��a.value() = 8���� 
};
int main() {
    Number a(2);
    Number b = a;
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a+b;
    cout << a.value() << endl;
    return 0;
}
