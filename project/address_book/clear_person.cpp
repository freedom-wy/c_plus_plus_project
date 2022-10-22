#include "utils.h"

void clearPerson(addressBook *book)
{
    book->size = 0;
    cout << "请按回车键返回目录" << endl;
    system("read");
    system("clear");
}