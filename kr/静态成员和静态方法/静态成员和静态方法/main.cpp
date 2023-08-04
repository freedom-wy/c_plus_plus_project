#include <iostream>
using namespace std;


class Person
{
public:
	static char name[64]; // ��̬��Ա
	int age;
public:
	Person()
	{
		cout << "Person�޲ι���" << endl;
	}
	Person(char* name, int age)
	{
		memset(this->name, 0, sizeof(this->name));
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}

	static void showInfo()
	{
		// ��̬������ֻ��ʹ�þ�̬����
		cout << name << endl;
	}
};

char Person::name[64] = "abcd"; // ��̬��Ա��ʼ��

void test1()
{
	cout << Person::name << endl; // abcd ʹ�þ�̬��Ա����ͨ�����������
	char name[64] = "hello";
	Person p1(name, 18);
	cout << p1.name << endl; // �������ʹ�þ�̬��Ա
	cout << Person::name << endl;
	p1.showInfo();
}


int main()
{
	test1();
	return 0;
}