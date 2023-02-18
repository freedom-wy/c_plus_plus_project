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

int addressBookIsEmpty(struct addressBook* adb)
{
    if (adb->size == 0)
    {
        printf("ͨѶ¼��������, ���������!\n");
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
    // �鿴����ǰ�������ж��Ƿ�������
    int return_value = addressBookIsEmpty(adb);
    if (return_value == 0)
    {
        return;
    }
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

int checkPerson(struct addressBook* adb)
{
    // ������ϵ��
    char name[64];
    printf("������Ҫ���ҵ�����: ");
    scanf("%s", name);
    // printf("Ҫ���ҵ�����Ϊ: %s\n", name);
    // ����ͨѶ¼
    for (int i = 0; i < adb->size; i++)
    {
        // printf("%d\n", strcmp(adb->addressList[i].name, name));
        if (strcmp(adb->addressList[i].name, name) == 0)
        {
            // ��������
            return i;
        }
    }
    return -1;
}

void findPerson(struct addressBook* adb)
{
    // ���ж�ͨѶ¼�Ƿ�Ϊ��
    int return_value = addressBookIsEmpty(adb);
    if (return_value == 0)
    {
        return;
    }
    // ������ϵ��
    int return_index = checkPerson(adb);
    if (return_index == -1)
    {
        printf("δ�ҵ���ϵ��, ���������Ƿ�������ȷ\n");
        system("pause");
        system("cls");
        return;
    }
    else 
    {
        // ��������
        printf("����: %s, ����: %d, �绰: %s, ��ַ: %s\n",
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
    // ɾ����ϵ��
    // ���ж�ͨѶ¼�Ƿ�Ϊ��
    int return_value = addressBookIsEmpty(adb);
    if (return_value == 0)
    {
        return;
    }
    // ������ϵ��
    int return_index = checkPerson(adb);
    if (return_index == -1)
    {
        printf("δ�ҵ���ϵ��, ���������Ƿ�������ȷ\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        // ɾ����ϵ��
        for (int i = return_index; i < adb->size; i++)
        {
            adb->addressList[i] = adb->addressList[i + 1];
            adb->size--;
        }
        printf("��ϵ��ɾ���ɹ�\n");
        system("pause");
        system("cls");
    }
}

void modifyPerson(struct addressBook* adb)
{
    // �޸���ϵ��
    // ���ж�ͨѶ¼�Ƿ�Ϊ��
    int return_value = addressBookIsEmpty(adb);
    if (return_value == 0)
    {
        return;
    }
    // ������ϵ��
    int return_index = checkPerson(adb);
    if (return_index == -1)
    {
        printf("δ�ҵ���ϵ��, ���������Ƿ�������ȷ\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        // �޸���ϵ��
        /*char name[64] = { '0' };
        printf("��������ϵ������: ");
        scanf("%s", name);
        strcpy(adb->addressList[adb->size].name, name);*/

        int age = 0;
        printf("��������ϵ������: ");
        scanf("%d", &age);
        adb->addressList[return_index].age = age;

        char phone[12] = { '0' };
        printf("��������ϵ�绰: ");
        scanf("%s", phone);
        strcpy(adb->addressList[return_index].phone, phone);

        char address[128] = { '0' };
        printf("������ͨ�ŵ�ַ: ");
        scanf("%s", address);
        strcpy(adb->addressList[return_index].address, address);
        
        printf("��ϵ���޸ĳɹ�\n");
        system("pause");
        system("cls");
    }
}

void saveBookToFile(struct addressBook* adb)
{
    // ��һ���ļ�
    FILE* f_write = fopen(ADDRESSBOOKFILENAME, "w");
    if (f_write == NULL)
    {
        printf("�ļ���ʧ��\n");
        return;
    }

    // ����ͨѶ¼, ����д������
    for (int i = 0; i < adb->size; i++)
    {
        fprintf(f_write, "����: %s, ����: %d, ��ϵ��ʽ: %s, ��ͥסַ: %s\n",
            adb->addressList[i].name, 
            adb->addressList[i].age, 
            adb->addressList[i].phone, 
            adb->addressList[i].address
        );
    }

    // �ر��ļ�
    fclose(f_write);
}

void loadFileToBook(struct addressBook* adb)
{
    // �����ļ����ڴ�
    // ��һ���ļ�
    FILE* f_read = fopen(ADDRESSBOOKFILENAME, "r");
    if (f_read == NULL)
    {
        // printf("�ļ���ʧ��\n");
        adb->size = 0;
        //memset(adb->addressList, 0, sizeof(adb->addressList));
        return;
    }

    int i = 0;
    while (!feof(f_read))
    {
        // ��������ֹͣ
        fscanf(f_read, "����: %[^,], ����: %d, ��ϵ��ʽ: %[^,], ��ͥסַ: %s\n", 
            adb->addressList[i].name, 
            &adb->addressList[i].age,
            adb->addressList[i].phone,
            adb->addressList[i].address
        );
        i++;
    }
    adb->size = i;

    // �ر��ļ�
    fclose(f_read);
}

void clearPerson(struct addressBook* adb)
{
    memset(adb->addressList, 0, sizeof(adb->addressList));
    adb->size = 0;

    FILE* f_write = fopen(ADDRESSBOOKFILENAME, "w");
    if (f_write == NULL)
    {
        printf("�ļ���ʧ��\n");
        return;
    }
    fclose(f_write);
    
    printf("��ϵ����ճɹ�\n");
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
            printf("��������, ��������\n");
            system("pause");
            system("cls");
            break;
        }
    }
	return 0;
}