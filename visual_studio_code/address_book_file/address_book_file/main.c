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

int addressBookIsEmpty(struct addressBook* adb)
{
    if (adb->size == 0)
    {
        printf("通讯录中无数据, 请添加数据!\n");
        system("pause");
        system("cls");
        return 0;
    }
    else
    {
        return adb->size;
    }
}

void addPerson(struct addressBook* adb)
{
    /*
    	char name[64];
	    int age;
	    char phone[12];
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
    // 查看数据前可以先判定是否有数据
    int return_value = addressBookIsEmpty(adb);
    if (return_value == 0)
    {
        return;
    }
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

int checkPerson(struct addressBook* adb)
{
    // 查找联系人
    char name[64];
    printf("请输入要查找的姓名: ");
    scanf("%s", name);
    // printf("要查找的姓名为: %s\n", name);
    // 遍历通讯录
    for (int i = 0; i < adb->size; i++)
    {
        // printf("%d\n", strcmp(adb->addressList[i].name, name));
        if (strcmp(adb->addressList[i].name, name) == 0)
        {
            // 返回索引
            return i;
        }
    }
    return -1;
}

void findPerson(struct addressBook* adb)
{
    // 先判定通讯录是否为空
    int return_value = addressBookIsEmpty(adb);
    if (return_value == 0)
    {
        return;
    }
    // 查找联系人
    int return_index = checkPerson(adb);
    if (return_index == -1)
    {
        printf("未找到联系人, 请检查姓名是否输入正确\n");
        system("pause");
        system("cls");
        return;
    }
    else 
    {
        // 遍历数组
        printf("姓名: %s, 年龄: %d, 电话: %s, 地址: %s\n",
            adb->addressList[return_index].name,
            adb->addressList[return_index].age,
            adb->addressList[return_index].phone,
            adb->addressList[return_index].address
        );
        system("pause");
        system("cls");
    }
}

void deletePerson(struct addressBook* adb)
{
    // 删除联系人
    // 先判定通讯录是否为空
    int return_value = addressBookIsEmpty(adb);
    if (return_value == 0)
    {
        return;
    }
    // 查找联系人
    int return_index = checkPerson(adb);
    if (return_index == -1)
    {
        printf("未找到联系人, 请检查姓名是否输入正确\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        // 删除联系人
        for (int i = return_index; i < adb->size; i++)
        {
            adb->addressList[i] = adb->addressList[i + 1];
            adb->size--;
        }
        printf("联系人删除成功\n");
        system("pause");
        system("cls");
    }
}

void modifyPerson(struct addressBook* adb)
{
    // 修改联系人
    // 先判定通讯录是否为空
    int return_value = addressBookIsEmpty(adb);
    if (return_value == 0)
    {
        return;
    }
    // 查找联系人
    int return_index = checkPerson(adb);
    if (return_index == -1)
    {
        printf("未找到联系人, 请检查姓名是否输入正确\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        // 修改联系人
        /*char name[64] = { '0' };
        printf("请输入联系人姓名: ");
        scanf("%s", name);
        strcpy(adb->addressList[adb->size].name, name);*/

        int age = 0;
        printf("请输入联系人年龄: ");
        scanf("%d", &age);
        adb->addressList[return_index].age = age;

        char phone[12] = { '0' };
        printf("请输入联系电话: ");
        scanf("%s", phone);
        strcpy(adb->addressList[return_index].phone, phone);

        char address[128] = { '0' };
        printf("请输入通信地址: ");
        scanf("%s", address);
        strcpy(adb->addressList[return_index].address, address);
        
        printf("联系人修改成功\n");
        system("pause");
        system("cls");
    }
}

void saveBookToFile(struct addressBook* adb)
{
    // 打开一个文件
    FILE* f_write = fopen(ADDRESSBOOKFILENAME, "w");
    if (f_write == NULL)
    {
        printf("文件打开失败\n");
        return;
    }

    // 遍历通讯录, 按行写入数据
    for (int i = 0; i < adb->size; i++)
    {
        fprintf(f_write, "姓名: %s, 年龄: %d, 联系方式: %s, 家庭住址: %s\n",
            adb->addressList[i].name, 
            adb->addressList[i].age, 
            adb->addressList[i].phone, 
            adb->addressList[i].address
        );
    }

    // 关闭文件
    fclose(f_write);
}

void loadFileToBook(struct addressBook* adb)
{
    // 加在文件到内存
    // 打开一个文件
    FILE* f_read = fopen(ADDRESSBOOKFILENAME, "r");
    if (f_read == NULL)
    {
        // printf("文件打开失败\n");
        adb->size = 0;
        //memset(adb->addressList, 0, sizeof(adb->addressList));
        return;
    }

    int i = 0;
    while (!feof(f_read))
    {
        // 遇到逗号停止
        fscanf(f_read, "姓名: %[^,], 年龄: %d, 联系方式: %[^,], 家庭住址: %s\n", 
            adb->addressList[i].name, 
            &adb->addressList[i].age,
            adb->addressList[i].phone,
            adb->addressList[i].address
        );
        i++;
    }
    adb->size = i;

    // 关闭文件
    fclose(f_read);
}

void clearPerson(struct addressBook* adb)
{
    memset(adb->addressList, 0, sizeof(adb->addressList));
    adb->size = 0;

    FILE* f_write = fopen(ADDRESSBOOKFILENAME, "w");
    if (f_write == NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    fclose(f_write);
    
    printf("联系人清空成功\n");
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
    memset(book.addressList, 0, sizeof(book.addressList));
    book.size = 0;
    //loadFileToBook(&book);
    /*for (int i = 0; i < book.size; i++)
    {
        printf("%s, %d, %s, %s\n",
            book.addressList[i].name,
            book.addressList[i].age,
            book.addressList[i].phone,
            book.addressList[i].address
        );
    }*/
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
            deletePerson(&book);
            break;
        case 4:
            findPerson(&book);
            break;
        case 5:
            modifyPerson(&book);
            break;
        case 6:
            clearPerson(&book);
            break;
        case 7:
            saveBookToFile(&book);
            exitProgram();
            break;
        default:
            printf("输入有误, 重新输入\n");
            system("pause");
            system("cls");
            break;
        }
    }
	return 0;
}