#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
    Person(const char* name, int age)
    {
        this->m_Name = new char[20];
        memset(this->m_Name, 0, 20);
        strcpy_s(this->m_Name, strlen(name)+1, name);
        this->m_Age = age;
    }
    ~Person()
    {
        if (this->m_Name != NULL)
        {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }
    void GetPersonInfo()
    {
        cout << "名字为: " << this->m_Name << ", 年龄为: " << this->m_Age << endl;
    }
public:
    char* m_Name;
    int m_Age;
};

// 普通函数模板
template<class T>
bool myCompare(T& a, T& b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<> bool myCompare(Person& p1, Person& p2)
{
    if (strcmp(p1.m_Name, p2.m_Name)==0 && p1.m_Age == p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test1()
{
    Person p1("hello", 10);
    p1.GetPersonInfo();
    int a = 1;
    int b = 2;
    bool ret1 = myCompare(a, b);
    if (ret1)
    {
        cout << "a==b" << endl;
    }
    else
    {
        cout << "a!=b" << endl;
    }

    Person p2("hello", 10);
    bool ret2 = myCompare(p1, p2);
    if (ret2)
    {
        cout << "a==b" << endl;
    }
    else
    {
        cout << "a!=b" << endl;
    }
    cout << "hello world" << endl;
}


int main()
{
    test1();
    return 0;
}