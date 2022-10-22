#include <iostream>
using namespace std;


// 定义通讯录内容结构体
struct person
{
    string name;
    int age;
    string phone;
    string address;
};

// 定义通讯录结构体
struct addressBook
{
    person addressList[1000];
    int size;
};

void showMenu();
void addPerson(addressBook *book);
void showPerson(addressBook *book);
int checkPerson(addressBook *book, string name);
void deletePerson(addressBook *book);
void findPerson(addressBook *book);
void modifyPerson(addressBook *book);