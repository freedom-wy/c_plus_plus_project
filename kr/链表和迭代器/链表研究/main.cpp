#include <iostream>
#include <list>
using namespace std;


class Person
{
public:
	int age;
	char* name;
public:
	Person()
	{
		this->age = 0;
		this->name = NULL;
	}
	Person(int val, char* name)
	{
		this->age = val;
		int size = strlen(name) + 1;
		this->name = new char[size];
		memset(this->name, 0, size);
		strcpy_s(this->name, size, name);
	}
	Person(const Person & obj)
	{
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
		this->age = obj.age;
		int size = strlen(obj.name) + 1;
		this->name = new char[size];
		memset(this->name, 0, size);
		strcpy_s(this->name, size, obj.name);
	}
	Person& operator=(const Person & obj)
	{
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
		this->age = obj.age;
		int size = strlen(obj.name) + 1;
		this->name = new char[size];
		memset(this->name, 0, size);
		strcpy_s(this->name, size, obj.name);
		return *this;
	}
	~Person()
	{
		this->age = 0;
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
	}
};


int main()
{
	char name[] = "hello";
	Person p1(1, name);
	Person p2(2, name);
	list<Person>l1;
	l1.push_back(p1);
	l1.push_back(p2);
	cout << "hello world" << endl;
	return 0;
}