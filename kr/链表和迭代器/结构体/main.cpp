#include <iostream>
#include <list>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
	Date()
	{
		day = 1;
		month = 2;
		year = 2013;
	}
	Date(int a, int b, int c)
	{
		day = a;
		month = b;
		year = c;
	}
};

struct Employee
{
	string name;
	int vacationDays;
	int daysUsed;
	Employee(string n = "", int d = 0)
	{
		name = n;
		vacationDays = 10;
		daysUsed = d;
	}
};

class Test
{
public:
	int age;
	string name;
public:
	Test()
	{
		this->age = 0;
		this->name = "";
	}
	Test(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	~Test()
	{
		this->age = 0;
		this->name = "";
	}
};

void test1()
{
	// �ṹ���ʼ��
	Date birthday1 = { 1, 1, 2019 };
	cout << "�������: " << birthday1.year << endl;

	//Date birthday2 = { 1, 2 }; // ���޹��췽����ø�ֵ�������������й��췽������ø�ֵ��������
	//cout << "�����·�" << birthday2.month << endl;

	Date* birthday3 = new Date(); // ���޲ι���
	birthday3->day = 1;
	birthday3->month = 2;
	birthday3->year = 2013;
	delete birthday3;
}

void test2()
{
	Employee e1("abc",1);
	cout << "����: " << e1.name << ", �������Ϊ: " << e1.vacationDays << ", ��ʹ�����Ϊ: " << e1.daysUsed << endl;
}

void test3()
{
	Test* t1 = new Test;
	Test* t2 = new Test();
}


int main()
{
	test1();
	//test2();
	//test3();
	return 0;
}
