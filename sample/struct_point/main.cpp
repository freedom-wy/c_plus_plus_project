#include <iostream>
using namespace std;
#include <string>


struct Student
{
    string name;
    int age;
};

int main()
{
    struct Student s1 = {"张三", 18};
    // 结构体指针
    struct Student *p = &s1;
    // 通过箭头来访问结构体指针数据
    cout << "姓名: " << p->name << " 年龄: " << p->age << endl;
    return 0;
}