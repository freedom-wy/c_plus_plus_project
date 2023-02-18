#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 进行函数定义等

struct Person
{
	char name[64];
	int age;
	char phone[12];
	char address[1024];
};

struct AddressBook
{
	struct Person* addressBook;
	int size;
};

void AddPerson(struct AddressBook* adb);
void ShowPerson(struct AddressBook* adb);


