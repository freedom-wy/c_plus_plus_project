#include <iostream>
#include <vector>
using namespace std;

// vector理解为数组，迭代器理解为指针

class Person
{
public:
	char* name;
	int age;
public:
	Person()
	{
		cout << "无参构造" << endl;
		this->name = NULL;
		this->age = 0;
	}
	Person(char* name, int age)
	{
		this->name = new char[64];
		memset(this->name, 0, 64);
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}
	Person(const Person& obj)
	{
		*this = obj;
	}

	Person& operator=(const Person& obj)
	{
		//if (this->name != NULL)
		//{
		//	//cout << typeid(*this).name() << endl;
		//	delete[] this->name;
		//	this->name = NULL;
		//}

		this->name = new char[64];
		memset(this->name, 0, 64);
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
		this->age = obj.age;
		return *this;
	}
	~Person()
	{
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
	}

};

void test1()
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}
	char name[64] = "hello";
	Person p1(name, 18);
	Person p2(name, 19);
	Person p3(name, 20);
	Person p4(name, 21);
	vector<Person>v2;
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);

	for (vector<Person>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << "姓名" << (*it).name << ", 年龄" << (*it).age << endl;
	}
	cout << "hello world" << endl;
}



int main()
{
	test1();
	return 0;
}