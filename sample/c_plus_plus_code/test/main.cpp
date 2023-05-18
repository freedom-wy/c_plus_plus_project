#include <iostream>
using namespace std;

class Person{
    public:
        Person()
        {
            cout << "默认构造方法" << endl;
        }
        ~Person()
        {
            cout << "析构" << endl;
        }
        Person(const Person& p)
        {
            cout << "拷贝构造" << endl;
            this->age = p.age;
            strcpy(this->name, p.name);
        }
    public:
        int age;
        char name[32];
    
    public:
        void setAge(int age)
        {
            this->age = age;
        }

        int getAge()
        {
            return this->age;
        }

        void setName(char* new_ame)
        {
            strcpy(this->name, new_ame);
        }

        char* getName()
        {
            return this->name;
        }
};

int main()
{
    Person p1;
    p1.setAge(10);
    char newName[32] = "zhangsan";
    p1.setName(newName);

    // 拷贝构造
    Person p2 = p1;
    // cout << "姓名为: " << p2.getName() << ", 年龄为: " << p2.getAge() << endl;
    
    // 拷贝构造
    Person p3(p2);
    cout << "姓名为: " << p3.getName() << ", 年龄为: " << p3.getAge() << endl;
    return 0;
}