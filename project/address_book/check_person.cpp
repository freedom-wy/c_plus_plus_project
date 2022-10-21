#include "utils.h"

int checkPerson(addressBook *book, string name)
{
    // 通过姓名查找通讯录中信息, 如果查找到返回索引, 如果查找不到返回-1
    for(int i=0; i<book->size; i++)
    {
        if (book->addressList[i].name == name)
        {
            return i;
        }
    }
    return -1;
}