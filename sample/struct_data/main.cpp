#include <iostream>
using namespace std;
#include <string>

// 自定义的数据类型叫做结构体
struct Student
{
    string name;
    int age;
    int score;

} s3; // s3为定义结构体时创建的变量

int main()
{
    // 结构体变量, struct关键字可以省略
    struct Student s1;
    // 给结构体变量赋值
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;

    cout << "学生的名字: " << s1.name << " 学生的年龄: " << s1.age << " 学生的分数: " << s1.score << endl;

    Student s2 = {"李四", 19, 90};
    cout << "学生的名字: " << s2.name << " 学生的年龄: " << s2.age << " 学生的分数: " << s2.score << endl;

    s3.name = "王五";
    s3.age = 20;
    s3.score = 80;
    cout << "学生的名字: " << s3.name << " 学生的年龄: " << s3.age << " 学生的分数: " << s3.score << endl;

    // 结构体数组
    struct Student stuArray[3] = 
    {
        {"张三", 18, 100},
        {"李四", 19, 90},
        {"王五", 20, 80}
    };

    // 修改数组中数据
    stuArray[2].name = "赵六";
    // 遍历结构体数组数据
    for (int i=0; i<3; i++)
    {
        cout << "学生姓名: " << stuArray[i].name << endl;
    }
    return 0;
}