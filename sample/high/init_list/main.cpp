#include <iostream>
using namespace std;


class Person{
    public:
        int p_A, p_B, p_C;
    
    public:
        // 传统有参构造函数
        // Person(int a, int b, int c)
        // {
        //     p_A = a;
        //     p_B = b;
        //     p_C = c;
        // }
        // 初始化列表构造函数, 注意有冒号
        Person(int a, int b, int c): p_A(a), p_B(b), p_C(c)
        {

        }
};

void test1()
{
    Person p(3, 2, 1);
    // Person p;
    cout << "a, b, c的值为: " << p.p_A << p.p_B << p.p_C << endl;
}

int main()
{
    test1();
    return 0;
}