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
	// 结构体初始化
	Date birthday1 = { 1, 1, 2019 };
	cout << "生日年份: " << birthday1.year << endl;

	//Date birthday2 = { 1, 2 }; // 如无构造方法则该赋值方法不报错，若有构造方法，则该赋值方法报错
	//cout << "生日月份" << birthday2.month << endl;

	Date* birthday3 = new Date(); // 走无参构造
	birthday3->day = 1;
	birthday3->month = 2;
	birthday3->year = 2013;
	delete birthday3;
}

void test2()
{
	Employee e1("abc",1);
	cout << "姓名: " << e1.name << ", 允许年假为: " << e1.vacationDays << ", 已使用年假为: " << e1.daysUsed << endl;
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
