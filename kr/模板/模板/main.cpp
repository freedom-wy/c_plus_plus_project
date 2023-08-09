#include <iostream>
#include <cstring>
using namespace std;

//class Person1
//{
//public:
//    Person1() 
//    {
//        cout << "person1的默认构造方法" << endl;
//        this->m_Name = NULL;
//        this->m_Age = 0;
//    }
//    Person1(const char* name, int age)
//    {
//        this->m_Name = new char[20];
//        memset(this->m_Name, 0, 20);
//        strcpy_s(this->m_Name, strlen(name)+1, name);
//        this->m_Age = age;
//    }
//
//    Person1& operator=(const Person1& obj)
//    {
//        if (this->m_Name != NULL)
//        {
//            delete[] this->m_Name;
//        }
//        this->m_Name = new char[20];
//        memset(this->m_Name, 0, 20);
//        strcpy_s(this->m_Name, strlen(obj.m_Name) + 1, obj.m_Name);
//        this->m_Age = obj.m_Age;
//        return *this;
//    }
//
//    /*Person1(string name, int age)
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    }*/
//
//    ~Person1()
//    {
//        cout << "Person1析构" << endl;
//        delete[] this->m_Name;
//        this->m_Name = NULL;
//        this->m_Age = 0;
//    }
//    void GetPersonInfo()
//    {
//        cout << "名字为: " << this->m_Name << ", 年龄为: " << this->m_Age << endl;
//    }
//public:
//    //string m_Name;
//    char* m_Name;
//    int m_Age;
//};

//// 普通函数模板
//template<class T>
//bool myCompare(T& a, T& b)
//{
//    if (a == b)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//template<> bool myCompare(Person1& p1, Person1& p2)
//{
//    if (strcmp(p1.m_Name, p2.m_Name)==0 && p1.m_Age == p2.m_Age)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//void test1()
//{
//    Person1 p1("hello", 10);
//    p1.GetPersonInfo();
//    int a = 1;
//    int b = 2;
//    bool ret1 = myCompare(a, b);
//    if (ret1)
//    {
//        cout << "a==b" << endl;
//    }
//    else
//    {
//        cout << "a!=b" << endl;
//    }
//
//    Person1 p2("hello", 10);
//    bool ret2 = myCompare(p1, p2);
//    if (ret2)
//    {
//        cout << "a==b" << endl;
//    }
//    else
//    {
//        cout << "a!=b" << endl;
//    }
//    cout << "hello world" << endl;
//}
//
////void test2()
////{
////    float ret = Add(1.1f, 1);
////    cout << "hello world" << endl;
////}
//
//class CInteger
//{
//public:
//    CInteger()
//    {
//        cout << "无参构造" << endl;
//    }
//
//    CInteger(int val)
//    {
//        cout << "有参构造" << endl;
//        this->m_n = val;
//    }
//
//    CInteger operator+(const CInteger& obj)
//    {
//        CInteger temp(this->m_n + obj.m_n);
//        return temp;
//    }
//private:
//    int m_n;
//};
//
//template<class T1, class T2>
//T1 Add(T1 val1, T2 val2)
//{
//    return val1 + val2; // 调用类的运算符重载
//}
//
//void test3()
//{
//    CInteger ret = Add<CInteger, CInteger>(CInteger(1), CInteger(2));
//    cout << "hello world" << endl;
//}
//
//// 类模板
//template<class AgeType>
//class Person
//{
//private:
//    char* name;
//    AgeType age;
//public:
//    Person(const char* name, AgeType age)
//    {
//        // 构造方法
//        this->name = new char[strlen(name)+1];
//        memset(this->name, 0, strlen(name) + 1);
//        strcpy_s(this->name, strlen(name)+1, name); //strcpy_s拷贝时,第二个参数为strlen+1
//        this->age = age;
//    }
//
//    void SetAge(AgeType age)
//    {
//        this->age = age;
//    }
//
//    void SetName(const char* name)
//    {
//        this->name = new char[strlen(name)+1];
//        memset(this->name, 0, strlen(name) + 1);
//        strcpy_s(this->name, strlen(name)+1, name); //strcpy_s拷贝时,第二个参数为strlen+1
//    }
//
//    void showPerson()
//    {
//        cout << "name: " << this->name << ", age: " << this->age << endl;
//    }
//};
//
//void printPerson1(Person<int>& p)
//{
//    p.showPerson();
//}
//
//template<class T1>
//void printPerson2(Person<T1>& p)
//{
//    p.showPerson();
//}
//
//template<class T>
//void printPerson3(T& p)
//{
//    // 整个类模板化
//    p.showPerson();
//}
//
//void test4()
//{
//    /*Person<int>p1("hello", 18);
//    p1.showPerson();*/
//    Person<int>p1("hello", 18);
//    printPerson1(p1);
//    printPerson2(p1);
//    printPerson3(p1);
//}

//template<class T>
//class MyArray
//{
//private:
//    T* pAddress;
//    int m_Capacity;
//    int m_Size;
//public:
//    MyArray(int capacity)
//    {
//        this->m_Capacity = capacity;
//        this->m_Size = 0;
//        this->pAddress = new T[this->m_Capacity];
//    }
//
//    MyArray(MyArray& obj)
//    {
//        cout << "拷贝构造" << endl;
//        if (this->pAddress != NULL)
//        {
//            delete[] this->pAddress;
//            this->pAddress = NULL;
//            this->m_Size = 0;
//            this->m_Capacity = 0;
//        }
//
//        this->pAddress = new T[obj.getCapacity()];
//        for (int i = 0; i < obj.getSize(); i++)
//        {
//            this->pAddress[i] = obj.pAddress[i];
//        }
//        this->m_Size = obj.m_Size;
//        this->m_Capacity = obj.m_Capacity;
//    }
//
//    ~MyArray()
//    {
//        cout << "析构" << endl;
//        if (this->m_Capacity != NULL)
//        {
//            delete[] this->pAddress;
//            this->pAddress = NULL;
//            this->m_Capacity = 0;
//            this->m_Size = 0;
//        }
//    }
//
//    // 添加数据
//    void Push_back(const T& val)
//    {
//        if (this->m_Capacity == this->m_Size)
//        {
//            return;
//        }
//        else {
//            this->pAddress[this->m_Size] = val;
//            this->m_Size++;
//        }
//    }
//
//    // 删除数据
//    void Pop_back()
//    {
//        if (this->m_Size == 0)
//        {
//            return;
//        }
//        this->m_Size--;
//    }
//
//    int getCapacity()
//    {
//        return this->m_Capacity;
//    }
//
//    int getSize()
//    {
//        return this->m_Size;
//    }
//
//    T& operator[](int index)
//    {
//        return this->pAddress[index];
//    }
//};

//void printIntArray(MyArray<int>& obj)
//{
//    for (int i = 0; i < obj.getSize(); i++)
//    {
//        cout << obj[i] << endl;
//    }
//}
//
//void printPersonArray(MyArray<Person1>& obj)
//{
//    for (int i = 0; i < obj.getSize(); i++)
//    {
//        obj[i].GetPersonInfo();
//    }
//}

void test5()
{
    /*MyArray<int>array1(10);
    for (int i = 0; i < 10; i++)
    {
        array1.Push_back((i+1)*10);
    }
    printIntArray(array1);

    cout << "----------------" << endl;*/

    /*MyArray<Person1>pArray(2);
    Person1 p1("a", 1);
    Person1 p2("b", 2);
    pArray[0] = p1;
    pArray[1] = p2;*/

    //MyArray<Person1> pArray(2);
    //Person1 p1("孙悟空", 30);
    //Person1 p2("韩信", 20);

    ////插入数据
    //pArray.Push_back(p1);
    //pArray.Push_back(p2);
    cout << "hello world" << endl;
}


template<class NameType, class AgeType>
class Person2
{
private:
    NameType* name;
    AgeType age;
public:
    Person2()
    {
        cout << "Person2无参构造" << endl;
        this->name = NULL;
        this->age = 0;
    }
    Person2(NameType* name, AgeType age)
    {
        this->name = new char[64];
        memset(this->name, 0, 64);
        strcpy_s(this->name, strlen(name) + 1, name);
        this->age = age;
    }
    Person2(const Person2& obj)
    {
        if (this->name != NULL)
        {
            delete[] this->name;
            this->name = NULL;
            this->age = 0;
        }


        this->name = new char[64];
        memset(this->name, 0, 64);
        strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
        this->age = obj.age;
    }
    Person2& operator=(const Person2& obj)
    {
        if (this->name != NULL)
        {
            delete[] this->name;
            this->name = NULL;
            this->age = 0;
        }


        this->name = new char[64];
        memset(this->name, 0, 64);
        strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
        this->age = obj.age;

        return *this;
    }
    Person2(Person2&& obj) // 移动构造
    {
        this->age = obj.age;
        this->name = obj.name;
        obj.name = NULL;
    }
    ~Person2()
    {
        cout << "析构" << endl;

        if (this->name != NULL)
        {
            delete []this->name;
            this->name = NULL;
            this->age = 0;
        }
    }
    void showInfo()
    {
        cout << "姓名: " << this->name << ", 年龄: " << this->age << endl;
    }
};

Person2<char, int> Func()
{
    char name[64] = "abcd";
    Person2<char, int> p4(name, 19);
    return p4;
}

void test6()
{
    char name[64] = "hello";
    Person2<char, int>p1(name, 18);
    Person2<char, int>p2 = p1;
    Person2<char, int>p3;
    p3 = p2;
    p3.showInfo();
    Person2<char, int> p5 = Func();
    cout << "hello world" << endl;
}


int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
	// test02();
    test6();
    return 0;
}