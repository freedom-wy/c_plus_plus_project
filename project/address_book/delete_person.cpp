#include "utils.h"

void deletePerson(addressBook *book)
{
    cout << "输入要删除联系人姓名: " << endl;
    string name;
    cin >> name;
    int index = checkPerson(book, name);
    // cout << "联系人索引为: " << index << endl;
    if (index != -1)
    {
        // 找到人了
        for (int i = index; i < book->size; i++)
        {
            // 后面的数据向前移动, 覆盖索引位置
            book->addressList[i] = book->addressList[i+1];
        }
        // 整个数组长度整体减一
        book->size--;
        cout << "联系人已删除" << endl;
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