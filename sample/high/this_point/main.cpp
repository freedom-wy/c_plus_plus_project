#include <iostream>
using namespace std;


class Person
{
    public:
        int age;
    
    public:
        Person(int age)
        {
            // 当形参和成员变量同名时, 可用this指针来区分
            this->age = age;
        }

        // 必须返回引用类型
        Person& PersonAddPerson(Person p)
        {
            this->age = this->age + p.age;
            // 返回解指针, 即返回对象本体
            return *this;
        }     
};

void test1()
{
    Person p1 = Person(2);
    cout << "年龄为: " << p1.age << endl;
}

void test2()
{
    Person p1(10);
    Person p2 = Person(10);
    // 链式调用
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "年龄为: " << p2.age << endl;
}



int main()
{
    // test1();
    test2();
    return 0;
}