#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ADDRESSBOOKFILENAME "person.txt"

struct Person
{
	char name[64];  //+0
	int age; // +64
	char phone[12]; // +68
	char address[128]; // 80
}; // 208

struct addressBook
{
	struct Person addressList[10]; // 0
	int size; // 2080 % 4
}; // 2084 

void program();
void showMenu();
void addPerson(struct addressBook* adb); // addressList point
void exitProgram();
void showInfo(struct addressBook* adb);
void deletePerson(struct addressBook* adb);
int checkPerson(struct addressBook* adb);
void findPerson(struct addressBook* adb);
void modifyPerson(struct addressBook* adb);