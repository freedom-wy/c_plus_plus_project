#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
1��ͨѶ¼�˵�
2�������Ա
3����ʾ��Ա
4��ɾ����Ա
5��������Ա
6�������Ա
7���˳�����
*/

#define ADDRESSBOOKFILENAME "person.txt"

struct Person
{
	char name[64];
	int age;
	char phone[12]; // ע���ֻ����볤������
	char address[128];
};

struct addressBook
{
	struct Person addressList[1000];
	int size;
};

void showMenu();
void addPerson(struct addressBook* adb);
void showPerson(struct addressBook* adb);
int checkPerson(struct addressBook* adb);
void deletePerson(struct addressBook* adb);
void findPerson(struct addressBook* adb);
void modifyPerson(struct addressBook* adb);
void clearPerson(struct addressBook* adb);
void exitProgram();

void saveBookToFile(struct addressBook* adb);
void loadFileToBook(struct addressBook* adb);

int addressBookIsEmpty(struct addressBook* adb);
