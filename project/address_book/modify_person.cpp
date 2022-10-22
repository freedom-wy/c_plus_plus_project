#include "utils.h"

void modifyPerson(addressBook *book)
{
    cout << "输入要修改的联系人姓名: " << endl;
    string name;
    cin >> name;
    int i = checkPerson(book, name);
    // cout << "联系人索引为: " << index << endl;
    if (i != -1)
    {
        // 修改姓名
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        book->addressList[i].name = name;
        // 修改年龄
        int age;
        cout << "请输入年龄: " << endl;
        cin >> age;
        book->addressList[i].age = age;
        // 修改电话
        string phone;
        cout << "请输入电话: " << endl;
        cin >> phone;
        book->addressList[i].phone = phone;
        // 修改住址
        string address;
        cout << "请输入地址: " << endl;
        cin >> address;
        book->addressList[i].address = address;
    }
    else
    {
        // 未找到
        cout << "查无此人" << endl;
    }
    cout << "请按回车键返回目录" << endl;
    system("read");
    system("clear");
}