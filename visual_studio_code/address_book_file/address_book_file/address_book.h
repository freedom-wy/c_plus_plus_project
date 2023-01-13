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

struct Person
{
	char name[64];
	int age;
	char phone[11];
	char address[128];
};

struct addressBook
{
	struct Person addressList[1000];
	int size;
};

void menu();
void addPerson(struct addressBook* adb);
void showPerson(struct addressBook* adb);
int checkPerson(struct addressBook* adb);
void deletePerson(struct addressBook* adb);
void findPerson(struct addressBook* adb);
void modifyPerson(struct addressBook* adb);
void clearPerson(struct addressBook* adb);
void exitProgram();
