#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
void MySwap(int* p1, int* p2)
{
    // 无法交换
    /*int* pTmp = p1;
    p1 = p2;
    p2 = pTmp;*/
    // 必须要有间接访问才会有交换
    int tmp = 0;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


int main()
{
    // 地址传递大坑
    int a = 1;
    int b = 2;
    MySwap(&a, &b);
    printf("交换后a=%d, b=%d\n", a, b);
=======
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
>>>>>>> 6fa4a1a360c63343d4ed4a307ca55ea4fca8950e
    return 0;
}
