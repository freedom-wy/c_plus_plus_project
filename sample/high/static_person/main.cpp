#include <iostream>
using namespace std;

class Person
{
    public:
        // 类成员变量
        int p_A;
        // 静态成员变量, 类内声明, 类外初始化
        static int p_B;
    
    public:
        static void func()
        {
            // p_A = 400; // 不能在静态方法中修改类成员变量, 编译器不知道到底要修改哪个实例的数据
            cout << "p_B的数据为: " << Person::p_B << endl;
        }
};

int Person::p_B = 100;

void test1()
{
    Person p1;
    cout << "p_B的数据为: " << p1.p_B << endl;
    Person p2;
    p2.p_B = 200;
    cout << "p_B的数据为: " << p1.p_B << endl;
    Person::p_B = 300;
    cout << "p_B的数据为: " << p1.p_B << endl;
}

void test2()
{
    Person p1;
    p1.func();
}

int main()
{
    test1();
    test2();
    return 0;
}
