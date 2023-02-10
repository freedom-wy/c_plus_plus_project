#include <iostream>
#include "template_array.hpp"
using namespace std;

void PrintIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.PushBack(i);
	}
	PrintIntArray(array1);

	MyArray<int> array2(array1);
	PrintIntArray(array2);

	MyArray<int> array3 = array2;
	PrintIntArray(array3);
}

class Person
{
public:
	string name;
	int age;
public:
	Person() {};
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	void showInfo()
	{
		cout << "员工姓名: " << this->name << ", 年龄: " << this->age << endl;
	}
};

void PrintPersonArray(MyArray<Person>& arr)
{
	// 打印对象数据
	for (int i = 0; i < 5; i++)
	{
		arr[i].showInfo();
	}
}


void test2()
{

	MyArray<Person> arr(5);
	string sub_name = "ABCDEF";
	for (int i = 0; i < sub_name.size(); i++)
	{
		string name = "名称: ";
		name += sub_name[i];
		Person p(name, i);
		arr.PushBack(p);
	}
	PrintPersonArray(arr);
}

int main()
{
	test2();
	return 0;
}