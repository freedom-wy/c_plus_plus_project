#include <iostream>
using namespace std;


struct Student
{
    string name;
    int score;
};

struct Teacher
{
    string name;
    // 老师带的学生
    // int a[];
    Student student[5];
};

void appendInfo(Teacher t[], int infoLen)
{
    for (int i=0; i<infoLen; i++)
    {
        string nameString = "abcde";
        t[i].name = "老师_";
        t[i].name += nameString[i];
        for (int j = 0; j < 5; j++)
        {
            t[i].student[j].name = "学生_";
            t[i].student[j].name += nameString[j];
            t[i].student[j].score = 60;
        }
        
    }
}

void printInfo(Teacher t[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师的姓名: " << t[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "学生的姓名: " << t[i].student[j].name << " 学生的成绩: " << t[i].student[j].score << endl;
        }
        
    }
    
}

int main()
{
    // 创建老师结构体变量
    struct Teacher teacher[3];
    // cout << sizeof(teacher) << endl;
    // cout << sizeof(teacher[0]) << endl;
    // 通过函数给老师添加信息
    int len = sizeof(teacher)/sizeof(teacher[0]);
    cout << "长度数据为: " << len << endl;
    appendInfo(teacher, len);
    // 打印数据
    printInfo(teacher, len);
    return 0;
}