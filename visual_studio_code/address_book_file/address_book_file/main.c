#define _CRT_SECURE_NO_WARNINGS
#include "address_book.h"


void showMenu()
{
    printf("1、添加联系人\n");
    printf("2、显示联系人\n");
    printf("3、删除联系人\n");
    printf("4、查找联系人\n");
    printf("5、修改联系人\n");
    printf("6、清空联系人\n");
    printf("7、退出程序\n");
}

void addPerson(struct addressBook* adb)
{
    /*
    	char name[64];
	    int age;
	    char phone[11];
	    char address[128];
    */

    // 在c语言中, 通过strcpy给字符串赋值
    char name[64] = { '0' };
    printf("请输入联系人姓名: ");
    scanf("%s", name);
    strcpy(adb->addressList[adb->size].name, name);
    
    int age = 0;
    printf("请输入联系人年龄: ");
    scanf("%d", &age);
    adb->addressList[adb->size].age = age;

    char phone[12] = { '0' };
    printf("请输入联系电话: ");
    scanf("%s", phone);
    strcpy(adb->addressList[adb->size].phone, phone);

    char address[128] = { '0' };
    printf("请输入通信地址: ");
    scanf("%s", address);
    strcpy(adb->addressList[adb->size].address, address);

    // 联系人添加成功后数值加一
    adb->size++;

    system("pause");
    system("cls");

}

void showPerson(struct addressBook* adb)
{
    // 遍历数组
    for (int i = 0; i < adb->size; i++)
    {
        printf("姓名: %s, 年龄: %d, 电话: %s, 地址: %s\n",
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
    printf("欢迎再次使用, 再见!\n");
    system("pause");
    exit(0);
}

int main()
{
    // 通讯录初始化
    struct addressBook book;
    book.size = 0;

    while (1)
    {
        showMenu();
        int select = 0;
        printf("请输入菜单序号: ");
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