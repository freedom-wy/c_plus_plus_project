#include <iostream>
using namespace std;
#include "utils.h"



// g++ main.cpp a.cpp -o main.out
int main()
{
    int select = 0;
    while (true)
    {
        showMenu();
        cin >> select;
        if (select == 1)
        {
            cout << "添加联系人" << endl;
            struct addressBook book;
            // 初始化通讯录中数据个数
            book.size = 0;
            addPerson(&book);
        }
        else if (select == 2)
        {
            cout << "显示联系人" << endl;
        }
        else if (select == 3)
        {
            cout << "删除联系人" << endl;
        }
        else if (select == 4)
        {
            cout << "查找联系人" << endl;
        }
        else if (select == 5)
        {
            cout << "修改联系人" << endl;
        }
        else if (select == 6)
        {
            cout << "清空联系人" << endl;
        }
        else
        {
            cout << "退出联系人" << endl;
            return 0;
        }
    }

    return 0;
}