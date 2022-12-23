#include <iostream>
using namespace std;

class Person
{
    public:
        int age;
    // 在public权限下
    public:
        // 构造函数, 无参构造
        Person()
        {
            cout << "无参构造函数" << endl;
        }
        // 有参构造
        Person(int age_value)
        {
            age = age_value;
            cout << "有参构造函数" << endl;
        }

        // 拷贝构造函数, const用于限定, 不能修改源, 将传入的人身上所有的属性, 拷贝到自己身上
        Person(const Person &p)
        {
            age = p.age;
            cout << "拷贝构造函数" << endl;
        }

        // 析构函数
        ~Person()
        {
            cout << "析构函数" << endl;
        }
};

// 值传递会拷贝出一个副本, 因此不会影响外部数据 
void doWork(Person p)
{

}

void test()
{
    // Person p; // 无参构造函数不能写括号
    // doWork(p); // 函数值传递时会调用拷贝构造函数
    // 有参构造
    Person p1(10);
    cout << "p1的年龄为" << p1.age << endl;
    // Person p2 = Person(p1);
    Person p2(p1);
    cout << "p2的年龄为" << p2.age << endl;
    // 匿名对象
    // Person(10);
}

int main()
{
    test();
    // Person p;
    // system("read");
}