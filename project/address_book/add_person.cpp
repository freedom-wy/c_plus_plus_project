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
        cout << "请输入学生姓名: " << name << endl;
        cin >> name;
        book->addressList[book->size].name = name;
        // 信息添加成功后数量加一
        book->size++;
        system("clear");
    }
}