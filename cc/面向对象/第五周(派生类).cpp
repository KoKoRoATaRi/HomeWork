//дһ��MyString �࣬ʹ�����������������ǣ�
//
//1. abcd-efgh-abcd-
//
//2. abcd-
//
//3.
//
//4. abcd-efgh-
//
//5. efgh-
//
//6. c
//
//7. abcd-
//
//8. ijAl-
//
//9. ijAl-mnop
//
//10. qrst-abcd-
//
//11. abcd-qrst-abcd- uvw xyz
//
//about
//
//big
//
//me
//
//take
//
//abcd
//
//qrst-abcd-
//
//Ҫ ��MyString������Ǵ�C++�ı�׼��string��������������ʾ1����������������� "MyString" ��"string" �滻����ô��Ŀ�ĳ����г�����������������޷�ͨ���⣬������䶼û�����⣬���������ǰ����Ľ���Ǻϡ�Ҳ����˵��MyString��� string��Ĺ�������ֻ�������������������档��ʾ2: string����һ����Ա���� string substr(int start,int length); �ܹ���� startλ�ÿ�ʼ������Ϊlength���Ӵ�
//
//����
//
//    #include <iostream>
//    #include <cstring>
//    #include <cstdlib>
//    using namespace std;
//
//// �ڴ˴�������Ĵ���
//
//    int CompareString( const void * e1, const void * e2) {
//        MyString * s1 = (MyString * ) e1;
//        MyString * s2 = (MyString * ) e2;
//        if( *s1 < *s2 )     return -1;
//        else if( *s1 == *s2 ) return 0;
//        else if( *s1 > *s2 ) return 1;
//    }
//    int main() {
//        MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
//        MyString SArray[4] = {"big","me","about","take"};
//        cout << "1. " << s1 << s2 << s3<< s4<< endl;
//        s4 = s3;    s3 = s1 + s3;
//        cout << "2. " << s1 << endl;
//        cout << "3. " << s2 << endl;
//        cout << "4. " << s3 << endl;
//        cout << "5. " << s4 << endl;
//        cout << "6. " << s1[2] << endl;
//        s2 = s1;    s1 = "ijkl-";
//        s1[2] = ��A�� ;
//        cout << "7. " << s2 << endl;
//        cout << "8. " << s1 << endl;
//        s1 += "mnop";
//        cout << "9. " << s1 << endl;
//        s4 = "qrst-" + s2;
//        cout << "10. " << s4 << endl;
//        s1 = s2 + s4 + " uvw " + "xyz";
//        cout << "11. " << s1 << endl;
//        qsort(SArray,4,sizeof(MyString), CompareString);
//        for( int i = 0;i < 4;++i )
//            cout << SArray[i] << endl;
//        //���s1���±�0��ʼ����Ϊ4���Ӵ�
//        cout << s1(0,4) << endl;
//        //���s1���±�Ϊ5��ʼ����Ϊ10���Ӵ�
//        cout << s1(5,10) << endl;
//        return 0;
//    }
//˼·��
//
//���������Ѿ��ɹ���������һ���죬���컹�и�ħ�޵��⣬����д���˷��ɻ�����������������ս����
//
//��Ϊһ�����̳к���������Ԫ����ҵ����⣬��ȷ�ǰ����֪ʶ�浽�����ˣ������������˵���ǳ�ȫ���ۺϵĿ����˶�string��̳еķ�������
//
//��Щ���ֵ�˼·�ڴ������Ѿ�����ע�ͣ�����Щû˵�ĵ����ó���˵һ�£�
//
//����operator+����������أ�������C++�ٷ��ĵ��ϻ�ȡ��operator+��3�����ܻᱻ�����õ������غ���
//
//string operator+ (const string& lhs, const string& rhs);//a
//string operator+ (const string& lhs, const char*   rhs);//b
//string operator+ (const char*   lhs, const string& rhs);//c
//Ȼ�����������������г��ֹ�+�ĵط�
//
//��1��
//
//s3 = s1 + s3;
//�Ȳ�˵��=��������+����������ȫ���Ե��ø����е�a����ʵ��
//
//��2��
//
//s4 = "qrst-" + s2;
//ͬ��������=�����������+�Ĳ�������ͨ��������c����ʵ��
//
//��3��
//
//s1 = s2 + s4 + " uvw " + "xyz";
//��������ͨ��b����ʵ��
//
//OK����Ȼ���������ڸ����ж�����Ӧ�ĳ�Ա��������ʵ�֣�����Ϊʲô��Ҫ�Լ�����ȥ��д�أ�������Ϊ���ķ���ֵ�����������ģ�1����2����3������������У�ÿһ���ڽ�����ӷ�������û�н��������ǽ��Ž����˸�ֵ�Ĳ�����������ǹؼ��㣬��������+����ֵ����һ��MyString��Ķ���Ҳ����һ�����࣬���������ͨ�����������operator+ȥ�������ǵĽ��������ֵ��һ�����༴string��Ķ��󣬶�����Ķ������޷���ֵ��������ȥ�ġ��������Ҫ��д�����е�������operator+����ʵҲֻ��Ҫ�����ǵķ���ֵ������Ӧ�ĸı�ͺá�
//
// 
//
//Ȼ����˵һ��string���е�c_str()�������ȿ���C++Reference�ж����Ķ���
//
//const char* c_str() const noexcept;
//The pointer returned points to the internal array currently used by the string object to store the characters that conform its value.
//
//˵���˾��ǰ�string�д洢�����ݸ��ŵ�һ��char�����У�Ȼ�󷵻����������׵�ַ��const char* ����
//
//��������������дoperator+�ķ���ֵҪ����MyString���͵ģ�������return��ʱ��Ҫ����MyString��Ķ��󣬶������вι��캯����ֻ�ܽ���const char*���͵Ĳ��������������б�Ҫ������ôһ��ת����
//
// 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class MyString : public string
{
public:
    MyString() {};
    //1.0�̳���̳и������еĳ�Ա�����ͳ�Ա�����������̳й��캯������������ 
    //1.1�̳�����޲ι��캯��������ʽ���ø�����޲ι��캯�� 
    MyString(const char * st) :string(st) {};
    //1.2�̳�����вι��캯�����������Ҳ���вι��캯�����������ʾ������ 
    //2.0����Ĳ�������reference������ѡ�񣬴˴�������const char*,"xxx"��������const char* 
    MyString(const MyString& s):string(s){}
    //1.3�̳���ĸ��ƹ��캯������Ҫ��ʾ�ĵ��ø���ĸ��ƹ��캯������Ȼ�ͻ�Ĭ�ϵ��ø�����޲ι��캯�� 
    MyString operator +(MyString & op2)
    {
        string s1 = *this;
        string s2 = op2;
        string s = s1 + s2;
        return *new MyString(s.c_str());
    }
    MyString & operator +(const char * cs2)
    {
        string str1 = *this;
        string s = str1 + cs2;
        return *new MyString(s.c_str());
    }
    
    MyString & operator()(int s, int l)
    {
        string str = substr(s, l);
        return *new MyString(str.c_str());
    }
};

MyString operator+(const char * op1, MyString & op2)
{
    string st2 = op2;
    string s = op1 + st2;
    return *new MyString(s.c_str());
}

int CompareString(const void * e1, const void * e2)
{
    MyString * s1 = (MyString *)e1;
    MyString * s2 = (MyString *)e2;
    if (*s1 < *s2) return -1;
    else if (*s1 == *s2) return 0;
    else if (*s1 > *s2) return 1;
}
int main()
{
    MyString s1("abcd-"), s2, s3("efgh-");
    MyString s4(s1);
    //Q1�����ƹ��캯���ǲ����̳еģ�Ϊʲô��������Բ�д����ĸ��ƹ��캯������Ĭ���ø���ĸ��ƹ��캯���� 
    MyString SArray[4] = { "big","me","about","take" };
    //Q2����MyString�ĳ�ʼ��Ϊʲô������const char*����const string& 
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    //3.0 operator=����ֱ����string������� 
    s3 = s1 + s3;
    s1+s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = ��A��;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; ++i)
        cout << SArray[i] << endl;
    cout << s1(0, 4) << endl;
    cout << s1(5, 10) << endl;
    return 0;
}
