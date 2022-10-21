#include <iostream>
using namespace std;

struct Person
{
    string name;
};

struct addressBook
{
    Person addressList[1000];
    int size;
};

int showPerson(addressBook *book, string name)
{
    // 通过姓名查找通讯录中信息, 如果查找到返回索引, 如果查找不到返回-1
    for (int i = 0; i < book->size; i++)
    {
        if (book->addressList[i].name == name)
        {
            cout << "找到了" << endl;
            return i;
        }
    }
    cout << "查无此人" << endl;
    return -1;
}

int main()
{
    struct addressBook book;
    book.size=0;
    showPerson(&book, "张三");
}