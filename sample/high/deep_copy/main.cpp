#include <iostream>
using namespace std;

class Person
{
    public:
        int p_age;
        // 在堆中开辟一块内存, 用于存储身高数据
        int *p_height;
    
    public:
        Person()
        {
            cout << "无参构造函数" << endl;
        }

        Person(int age, int height)
        {
            p_age = age;
            // new关键字返回指针
            p_height = new int(height);
            // cout << p_height << endl;
            cout << "有参构造函数" << endl;
        }

        // 拷贝构造函数
        Person(const Person &p)
        {
            p_age = p.p_age;
            p_height = new int(*p.p_height);
        }

        ~Person()
        {
            cout << "析构函数" << endl;
            // 在析构函数中释放堆区数据, 释放前需使用拷贝构造函数重写为深拷贝
            if (p_height != NULL)
            {
                delete p_height;
            }
        }
};

void test1()
{
    Person p1(18, 170);
    cout << "p1年龄为: " << p1.p_age << " 体重为: " << *p1.p_height << endl;
    Person p2(p1);
    cout << "p2年龄为: " << p2.p_age << " 体重为: " << *p2.p_height << endl;
}

int main()
{
    test1();
    return 0;
}