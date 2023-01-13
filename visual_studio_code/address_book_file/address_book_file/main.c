#define _CRT_SECURE_NO_WARNINGS
#include "address_book.h"


void showMenu()
{
    printf("1�������ϵ��\n");
    printf("2����ʾ��ϵ��\n");
    printf("3��ɾ����ϵ��\n");
    printf("4��������ϵ��\n");
    printf("5���޸���ϵ��\n");
    printf("6�������ϵ��\n");
    printf("7���˳�����\n");
}

void addPerson(struct addressBook* adb)
{
    /*
    	char name[64];
	    int age;
	    char phone[11];
	    char address[128];
    */

    // ��c������, ͨ��strcpy���ַ�����ֵ
    char name[64] = { '0' };
    printf("��������ϵ������: ");
    scanf("%s", name);
    strcpy(adb->addressList[adb->size].name, name);
    
    int age = 0;
    printf("��������ϵ������: ");
    scanf("%d", &age);
    adb->addressList[adb->size].age = age;

    char phone[12] = { '0' };
    printf("��������ϵ�绰: ");
    scanf("%s", phone);
    strcpy(adb->addressList[adb->size].phone, phone);

    char address[128] = { '0' };
    printf("������ͨ�ŵ�ַ: ");
    scanf("%s", address);
    strcpy(adb->addressList[adb->size].address, address);

    // ��ϵ����ӳɹ�����ֵ��һ
    adb->size++;

    system("pause");
    system("cls");

}

void showPerson(struct addressBook* adb)
{
    // ��������
    for (int i = 0; i < adb->size; i++)
    {
        printf("����: %s, ����: %d, �绰: %s, ��ַ: %s\n",
            adb->addressList[i].name,
            adb->addressList[i].age,
            adb->addressList[i].phone,
            adb->addressList[i].address
        );
    }

    system("pause");
    system("cls");
}

void exitProgram()
{
    printf("��ӭ�ٴ�ʹ��, �ټ�!\n");
    system("pause");
    exit(0);
}

int main()
{
    // ͨѶ¼��ʼ��
    struct addressBook book;
    book.size = 0;

    while (1)
    {
        showMenu();
        int select = 0;
        printf("������˵����: ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            addPerson(&book);
            break;
        case 2:
            showPerson(&book);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            exitProgram();
            break;
        default:
            break;
        }
    }
	return 0;
}