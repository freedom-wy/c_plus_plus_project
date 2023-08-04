#include <iostream>
using namespace std;


class Person
{
public:
	static char name[64]; // 静态成员
	int age;
public:
	Person()
	{
		cout << "Person无参构造" << endl;
	}
	Person(char* name, int age)
	{
		memset(this->name, 0, sizeof(this->name));
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}

	static void showInfo()
	{
		// 静态方法中只能使用静态变量
		cout << name << endl;
	}
};

char Person::name[64] = "abcd"; // 静态成员初始化

void test1()
{
	cout << Person::name << endl; // abcd 使用静态成员可以通过类名或对象
	char name[64] = "hello";
	Person p1(name, 18);
	cout << p1.name << endl; // 对象可以使用静态成员
	cout << Person::name << endl;
	p1.showInfo();
}


int main()
{
	test1();
	return 0;
}