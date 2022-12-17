#include <iostream>
using namespace std;

class Student
{
    // 访问权限, 公共权限, 冒号
    public:
        // 成员属性 成员变量
        string s_name;
        int s_code;

        // 成员方法 成员函数
        void printStudentInfo()
        {
            // 用于判断传入的数据是否为空
            if (this == NULL)
            {
                return;
            }
            cout << "学生姓名为: " << s_name << ", 学号为: " << s_code << endl;
        }

        void setName(string name)
        {
            // 形参名称不能和属性相同
            s_name = name;
        }

        void setCode(int code)
        {
            s_code = code;
        }

        void printInfoDemo()
        {
            cout << "hello world" << endl;
        }
};

class Person
{
    public:
        string p_Name;
    protected:
        string p_Car;
    private:
        int p_Password;
        int p_Age;
    
    public:
        // 类内可以访问成员属性
        void func()
        {
            p_Name = "张三";
            p_Car = "奔驰";
            p_Password = 123456;

            cout << "姓名: " << p_Name << ", 车辆: " << p_Car << ", 密码: " << p_Password << endl;
        }

        // 当成员属性为私有时, 可以通过public方法设置成员属性和访问成员属性
        void setAge(int age)
        {
            if (age >= 100 || age<0)
            {
                cout << "年龄设置错误" << endl;
                p_Age = 0;
                return;
            }
            p_Age = age;
        }

        void getAge()
        {
            cout << "年龄为: " << p_Age << endl;
        }
    protected:
        void func2()
        {
            cout << "hello world" << endl;
        }
};

int main()
{
    // 实例化对象
    // Student s1;
    // s1.s_name = "张三";
    // s1.s_code = 001;
    // s1.setName("张三");
    // s1.setCode(1);
    // s1.printStudentInfo();

    Student * p = NULL;
    // p->printInfoDemo(); // 空指针无实例属性, 因此会报错
    p->printStudentInfo();

    // Person p1;
    // p1.p_Name = "李四";
    // p1.p_Car = "路虎"; // 类外不能访问保护权限
    // p1.p_Password = 111111; // 类外不能访问私有权限
    // p1.func();
    // p1.func2(); // 类外不能访问
    // p1.setAge(100);
    // p1.getAge();
    return 0;
}