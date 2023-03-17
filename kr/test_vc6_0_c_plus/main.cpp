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


struct tagDateOfBirth //�ṹ��Ƕ��
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