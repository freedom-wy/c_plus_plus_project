#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return 0;
}
