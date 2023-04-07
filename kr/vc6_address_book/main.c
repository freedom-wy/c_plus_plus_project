#include "address_book.h"


void showMenu()
{
    printf("1 ���\n");
    printf("2 ��ʾ\n");
    printf("3 ɾ��\n");
    printf("4 ����\n");
    printf("5 �޸�\n");
    printf("6 ���\n");
    printf("7 �˳�\n");
}

void exitProgram()
{
    printf("��ӭ�ٴ�ʹ��, �ټ�\n");
    getchar();
    exit(0);
}

void addPerson(struct addressBook* adb)
{
    //  char name[64];
    // 	int age;
    // 	char phone[12];
    // 	char address[128];
    // ������Ϣ
    char name[64] = {'0'};
    int age = 0;
    char phone[12] = {'0'};
    char address[128] = {'0'};

    printf("����������: ");
    scanf("%s", name);
    strcpy(adb->addressList[adb->size].name, name);

    printf("����������: ");
    scanf("%d", &age);
    adb->addressList[adb->size].age = age;

    printf("������绰: ");
    scanf("%s", phone);
    if(strlen(phone) != 11)
    {
        printf("�绰�������\n");
        return;
    }
    else
    {
        strcpy(adb->addressList[adb->size].phone, phone);
    }

    printf("�������ַ�� ");
    scanf("%s", address);
    strcpy(adb->addressList[adb->size].address, address);

    adb->size++;

    getchar();
}

void showInfo(struct addressBook* adb)
{
    int i = 0;
    for(; i<adb->size;i++)
        {
            printf(
                "����: %s, ����: %d, �绰: %s, ��ַ: %s\n", 
                adb->addressList[i].name,
                adb->addressList[i].age,
                adb->addressList[i].phone,
                adb->addressList[i].address
                );
        }

    getchar();

}

int checkPerson(struct addressBook* adb)
{
    char name[64];
    int i=0;
    printf("������Ҫ���ҵ�����: ");
    scanf("%s", name);

    for (;i<adb->size;i++)
    {
        if(strcmp(adb->addressList[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

void deletePerson(struct addressBook* adb)
{
    int return_value, i;
    return_value = checkPerson(adb);
    if (return_value == -1)
    {
        printf("δ�ҵ���ϵ��, ���������Ƿ�������ȷ\n");
        getchar();
        return;
    }
    else
    {
        for(i=return_value;i<adb->size;i++)
        {
            adb->addressList[i] = adb->addressList[i+1];
        }
        adb->size--;
    }
    
}

void findPerson(struct addressBook* adb)
{
    int return_value, i;
    return_value = checkPerson(adb);
    if (return_value == -1)
    {
        printf("δ�ҵ���ϵ��, ���������Ƿ�������ȷ\n");
        getchar();
        return;
    }
    else
    {
        for(i=return_value;i<return_value+1;i++)
        {
            printf(
                "����: %s, ����: %d, �绰: %s, ��ַ: %s\n", 
                adb->addressList[i].name,
                adb->addressList[i].age,
                adb->addressList[i].phone,
                adb->addressList[i].address
                );
            break;
        }
    }
    
}

void modifyPerson(struct addressBook* adb)
{
    int return_value;
    return_value = checkPerson(adb);
    if (return_value == -1)
    {
        printf("δ�ҵ���ϵ��, ���������Ƿ�������ȷ\n");
        getchar();
        return;
    }
    else
    {
        // �޸���Ϣ
        char name[64] = {'0'};
        int age = 0;
        char phone[12] = {'0'};
        char address[128] = {'0'};

        printf("����������: ");
        scanf("%s", name);
        strcpy(adb->addressList[return_value].name, name);

        printf("����������: ");
        scanf("%d", &age);
        adb->addressList[return_value].age = age;

        printf("������绰: ");
        scanf("%s", phone);
        if(strlen(phone) != 11)
        {
            printf("�绰�������\n");
            return;
        }
        else
        {
            strcpy(adb->addressList[return_value].phone, phone);
        }

        printf("�������ַ�� ");
        scanf("%s", address);
        strcpy(adb->addressList[return_value].address, address);
    }
}

void program()
{
    int select;
	struct addressBook book;
    memset(book.addressList, 0, sizeof(book));
    book.size = 0;
    
    while (1)
    {
        showMenu();
        select = 0;
        printf("�����빦�����: ");
        scanf("%d", &select);
        switch(select)
        {
            case 1:
                // ���
                addPerson(&book);
                break;
            case 2:
                showInfo(&book);
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
            case 7:
                exitProgram();
                break;
            default:
                printf("��������, ����������\n");
                getchar();
                break;
        }
    }
}

int main()
{
    program();
	return 0;
}