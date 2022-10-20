#include <iostream>
using namespace std;
#include <string>

struct Student
{
    string name;
    int age;
};

struct Teacher
{
    int id;
    string name;
    struct Student s1; // 结构体嵌套
};

// 通过函数访问结构体数据
// 值传递
void printStudent1(Student s);
// 地址传递, 通过地址传递形参可以影响实参
void printStudent2(Student *p);
// 通过const来修饰指针形参
void printStudent3(const Student *p);

void printStudent1(Student s)
{
    s.age = 100;
    cout << "子函数学生姓名: " << s.name << " 学生年龄: " << s.age << endl;
}

void printStudent2(Student *p)
{
    p->age = 200;
    cout << "子函数学生姓名: " << p->name << " 学生年龄: " << p->age << endl;
}

// 通过const来限定数据
void printStudent3(const Student *p)
{
    // p->age = 200; // 不允许修改
    cout << "子函数学生姓名: " << p->name << " 学生年龄: " << p->age << endl;
}

void printStudent4(Student s[])
{
    for (int i = 0; i < 2; i++)
    {
        // cout << "学生姓名: " << s[i].name << " 学生年龄: " << s[i].age << endl;
        s[i].age = 100;
    }
    
}

int main()
{
    struct Student s1 = {"张三", 18};
    // 结构体指针
    struct Student *p = &s1;

    // 结构体嵌套
    struct Teacher t1;
    t1.id = 1000;
    t1.name = "李老师";
    t1.s1.name = "李四";
    t1.s1.age = 19;
    cout << "老师姓名: " << t1.name << " 老师辅导的学生姓名: " << t1.s1.name << endl;

    // 通过函数访问结构体信息
    printStudent1(s1);
    // printStudent2(&s1);
    printStudent3(&s1);

    // 通过箭头来访问结构体指针数据
    cout << "姓名: " << p->name << " 年龄: " << p->age << endl;
    // 值传递在函数中的弊端为, 当结构体中数据很多会造成大量的数据拷贝
    // 地址传递在函数中的优势为, 虽然结构体中数据很多, 但是传递的参数为指针, 仅传递一个指针的字节大小

    // 定义结构体数组, 将结构体数组传入函数, 并修改数据
    Student s2[] = {{"赵六", 18}, {"陈七", 19}};
    printStudent4(s2);
    for (int i = 0; i < 2; i++)
    {
        cout << "学生姓名: " << s2[i].name << " 学生年龄: " << s2[i].age << endl;
    }
    
    return 0;
}