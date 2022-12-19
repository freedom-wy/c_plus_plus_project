#include <iostream>
using namespace std;

class Person{
    // 可以通过友元解决类外使用private权限属性问题, 也可以修改为public
    friend Person operator+(Person &p1, Person &p2);
    friend void test1();
    friend ostream& operator<<(ostream &out, Person &p);
    private:
        int p_A;
        int p_B;
    public:
        Person() {};
        Person(int a, int b)
        {
            p_A = a;
            p_B = b;
        }

        void operator()(string test)
        {
            cout << test << endl;
        }

        int operator()(int a, int b)
        {
            return a + b;
        }

        // // 重载加法运算符
        // Person operator+(Person &p)
        // {
        //     Person temp;
        //     temp.p_A = this->p_A + p.p_A;
        //     temp.p_B = this->p_B + p.p_B;
        //     return temp;
        // }
};

// 全局函数重载加法运算符
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.p_A = p1.p_A + p2.p_A;
    temp.p_B = p1.p_B + p2.p_B;
    return temp;
}

// 全局函数重载左移运算符
ostream& operator<<(ostream &out, Person &p)
{
    out << "a: " << p.p_A << " ,b: " << p.p_B;
    return out;
}

int * myAdd(int a, int b)
{
    int c = a + b;
    return &c;
}

void test1()
{
    // Person p1(10, 10);
    // cout << p1 << endl;
    // Person p2(20, 20);

    // Person p3 = p1 + p2;
    // cout << p3 << endl;
    // cout << "p3的属性值为: " << p3.p_A << "," << p3.p_B << endl;
    // Person p4;
    // p4("hello world");
    // Person()("hello world");
    // Person p5;
    // int val = p5(1, 2);
    // cout << val << endl;
    // cout << val << endl;
    int * c = myAdd(1, 2);
    cout << *c << endl;
    cout << *c << endl;
    cout << *c << endl;
    cout << *c << endl;
    cout << *c << endl;
}

int main()
{
    test1();
    return 0;
}