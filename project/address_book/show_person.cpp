#include "utils.h"

void showPerson(addressBook *book)
{
    if (book->size == 0)
    {
        cout << "通讯录无数据" << endl;
        cout << "请按回车键返回目录" << endl;
        system("read");
        system("clear");
        // return;
    }
    else
    {
        for (int i=0; i<book->size; i++)
        {
            cout << "姓名: " << book->addressList[i].name;
            cout << "\t年龄: " << book->addressList[i].age;
            cout << "\t电话: " << book->addressList[i].phone;
            cout << "\t住址: " << book->addressList[i].address;
            cout << endl;
        }
        cout << "请按回车键返回目录" << endl;
        system("read");
        system("clear");
    }
}