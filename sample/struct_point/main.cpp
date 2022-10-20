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

int main()
{
    struct Student s1 = {"张三", 18};
    // 结构体指针
    struct Student *p = &s1;
    // 通过箭头来访问结构体指针数据
    cout << "姓名: " << p->name << " 年龄: " << p->age << endl;
    
    // 结构体嵌套
    struct Teacher t1;
    t1.id = 1000;
    t1.name = "李老师";
    t1.s1.name = "李四";
    t1.s1.age = 19;
    cout << "老师姓名: " << t1.name << " 老师辅导的学生姓名: " << t1.s1.name << endl;
    return 0;
}