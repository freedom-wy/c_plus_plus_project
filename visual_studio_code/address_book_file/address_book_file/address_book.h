#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
1、通讯录菜单
2、添加人员
3、显示人员
4、删除人员
5、查找人员
6、清空人员
7、退出程序
*/

#define ADDRESSBOOKFILENAME "person.txt"

struct Person
{
	char name[64];
	int age;
	char phone[12]; // 注意手机号码长度问题
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
