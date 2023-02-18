#define _CRT_SECURE_NO_WARNINGS
#include "address_book.h"

void AddPerson(struct AddressBook* adb)
{
	char name[64] = { '0' };
	printf("����������: ");
	scanf("%s", name);
	strcpy(adb->addressBook[adb->size].name, name);
	
	//getchar();

	int age = 0;
	printf("����������: ");
	scanf("%d", &age);
	adb->addressBook[adb->size].age = age;
	
	//getchar();

	char phone[20] = { '0' };
	printf("������绰����: ");
	scanf("%s", phone);
	strncpy(adb->addressBook[adb->size].phone, phone, 11);
	adb->addressBook[adb->size].phone[11] = '\0';
	
	//getchar();

	char address[1024] = { '0' };
	printf("�������ַ: ");
	scanf("%s", address);
	strcpy(adb->addressBook[adb->size].address, address);

	adb->size++;
}

void ShowPerson(struct AddressBook* adb)
{
	for (int i = 0; i < adb->size; i++)
	{
		printf(
			"����: %s, ����: %d, �绰: %s, ��ַ: %s\n",
			adb->addressBook[i].name,
			adb->addressBook[i].age,
			adb->addressBook[i].phone,
			adb->addressBook[i].address
		);
	}
}

int main()
{
#if 1
	// ͨѶ¼��ʼ��
	struct AddressBook book;
	book.addressBook = NULL;
	book.addressBook = (struct Person*)malloc(1000 * sizeof(Person*));
	memset(book.addressBook, 0, sizeof(book.addressBook));
	book.size = 0;

	while (1)
	{
		int select = 0;
		printf("�����빦�ܱ��: ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			// ����û�
			AddPerson(&book);
			break;
		case 2:
			ShowPerson(&book);
			break;
		case 3:
			break;
		default:
			break;
		}
	}

	free(book.addressBook);
	book.addressBook = NULL;
#else
	/*char phone1[12] = {'0'};
	char phone2[20] = { '0' };
	printf("������绰��: ");
	scanf("%s", phone2);
	strncpy(phone1, phone2, 11);
	printf("�绰��Ϊ: %s\n", phone1);*/
	char phone1[12];
	char phone2[12] = { '0' };
	fgets(phone2, sizeof(phone2), stdin);
	strncpy(phone1, phone2, 11);
	phone1[11] = '\0';
	printf("�绰��: %s\n", phone1);
#endif
	return 0;
}