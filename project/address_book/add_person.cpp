#include "utils.h"

// 添加学生
void addPerson(addressBook *book)
{
    // 首先判断通讯录是否有空间
    if (book->size >= 1000)
    {
        cout << "通讯录已满, 无法添加!" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入学生姓名: " << endl;
        cin >> name;
        book->addressList[book->size].name = name;

        int age;
        cout << "请输入学生年龄: " << endl;
        cin >> age;
        book->addressList[book->size].age = age;

        string phone;
        cout << "请输入学生电话号码: " << endl;
        cin >> phone;
        book->addressList[book->size].phone = phone;

        string address;
        cout << "请输入学生家庭住址: " << endl;
        cin >> address;
        book->addressList[book->size].address = address;

        // 信息添加成功后数量加一
        book->size++;
        cout << "请按回车键返回目录" << endl;
        system("read");
        system("clear");
    }
}