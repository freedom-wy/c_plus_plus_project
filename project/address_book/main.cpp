#include <iostream>
using namespace std;
#include "utils.h"


int test1()
{
    int select = 0;
    struct addressBook book;
    book.size = 0; // 初始化通讯录中信息数量
    while (true)
    {
        showMenu();
        cin >> select; // 在c语言中为scanf
        if (select == 1)
        {
            cout << "添加联系人" << endl;
            // 初始化通讯录中数据个数
            addPerson(&book); // 形参修饰实参, 因此传递地址
        }
        else if (select == 2)
        {
            cout << "显示联系人" << endl;
            showPerson(&book);
        }
        else if (select == 3)
        {
            cout << "删除联系人" << endl;
            deletePerson(&book);
        }
        else if (select == 4)
        {
            cout << "查找联系人" << endl;
            findPerson(&book);
        }
        else if (select == 5)
        {
            cout << "修改联系人" << endl;
            modifyPerson(&book);
        }
        else if (select == 6)
        {
            cout << "清空联系人" << endl;
            clearPerson(&book);
        }
        else
        {
            cout << "退出联系人" << endl;
            return 0;
        }
    }
}

void printArray(int* array, int len)
{
    for(int i=0;i<len;i++)
    {
        cout << "数组的元素值为: " << array[i] << endl;
    }
}

void test2()
{
    int dataArray[5] = {1, 2, 3, 4, 5};
    int* p = dataArray;
    printArray(p, 5);
}

// g++ main.cpp a.cpp -o main.out
int main()
{
    test1();
    // test2();
    return 0;
}