#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
void MySwap(int* p1, int* p2)
{
    // �޷�����
    /*int* pTmp = p1;
    p1 = p2;
    p2 = pTmp;*/
    // ����Ҫ�м�ӷ��ʲŻ��н���
    int tmp = 0;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


int main()
{
    // ��ַ���ݴ��
    int a = 1;
    int b = 2;
    MySwap(&a, &b);
    printf("������a=%d, b=%d\n", a, b);
=======
/*
����������뷽ʽΪZp��Ĭ��Ϊ8
���Ա�������ṹ��֮��ĵ�ַ��Ϊmember offset
member��������	member offset % min(Zp,sizeof(member type)) == 0;

��ṹ���������ΪStructAlign
stryctAlign��������
StructAlign = max(sizeof(member1 type),sizeof(member2 type)������,sizeof(membern type));
StructAlign = min(Zp,StructAlign);
sizeof(�ṹ�����)��������
sizeof(�ṹ�����)%structAlign == 0;


�ṹ��Ѱַ��ʽ���ṹ���׵�ַ+��Աƫ����
structObj.member or pstructObj->member
*(member type*)((int)(&structObj)+ member offset)
��offsetof�ؼ���չ����Ľ����ͬ��
*/



// ����ṹ��
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
