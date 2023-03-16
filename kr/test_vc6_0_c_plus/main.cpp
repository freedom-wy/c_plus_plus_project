#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
设编译器对齐方式为Zp，默认为8
设成员变量到结构体之间的地址差为member offset
member必须满足	member offset % min(Zp,sizeof(member type)) == 0;

设结构体自身对齐为StructAlign
stryctAlign必须满足
StructAlign = max(sizeof(member1 type),sizeof(member2 type)···,sizeof(membern type));
StructAlign = min(Zp,StructAlign);
sizeof(结构体变量)必须满足
sizeof(结构体变量)%structAlign == 0;


结构体寻址公式：结构体首地址+成员偏移量
structObj.member or pstructObj->member
*(member type*)((int)(&structObj)+ member offset)
和offsetof关键字展开后的结果相同。
*/



// 定义结构体
struct tagStuInfo = {
    char szName[5]; // +0 // 8 % min(8,sizeof(char)) == 0;
    float fHeight; // +8
    short int wScore; // +12
    int nAge; // +16
    char cGender; // +20
    double dblWeight; // +24
}; // 32

int main()
{
    return 0;
}
