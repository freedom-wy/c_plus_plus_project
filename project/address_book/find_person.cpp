#include "utils.h"

void findPerson(addressBook *book)
{
    cout << "输入要查找联系人姓名: " << endl;
    string name;
    cin >> name;
    int i = checkPerson(book, name);
    // cout << "联系人索引为: " << index << endl;
    if (i != -1)
    {
        // 找到人了
        cout << "姓名: " << book->addressList[i].name;
        cout << "\t年龄: " << book->addressList[i].age;
        cout << "\t电话: " << book->addressList[i].phone;
        cout << "\t住址: " << book->addressList[i].address;
        cout << endl;
        cout << "请按回车键返回目录" << endl;
        system("read");
        system("clear");
    }
    else
    {
        // 未找到
        cout << "查无此人" << endl;
        cout << "请按回车键返回目录" << endl;
        system("read");
        system("clear");
    }
}