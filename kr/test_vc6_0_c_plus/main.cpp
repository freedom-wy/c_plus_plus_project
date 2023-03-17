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


struct tagDateOfBirth //结构体嵌套
{
    short int wDay; // 0
    int nYear; // 4
    char cMonth; // 8
}; // 12


struct tagPerson
{
    char szName[5]; // 0
    float fHeight; // 8
    double dblWeight; // 16
    char cGender; // 24
    struct tagDateOfBirth DOB; // 28
    __int64 i64; // 40
    char c; // 48
    int nID; // 52
    unsigned short int wAge; // 56
}; // 64


int main()
{
    int a = 100;
    printf("sizeof __int64=%d\n", sizeof(__int64));
    struct tagPerson p1= {
        "abc",
        185.0f,
        75.0,
        'U',
        {
            17,
            2023,
            3
        },
        100,
        'A',
        1234,
        17
    };

    printf("sizeof tagPerson p1 = %d\n", sizeof(p1)); // 40
    return 0;
}