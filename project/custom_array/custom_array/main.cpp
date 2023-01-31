#include "myArray.hpp"

void printArray(myArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//void test1()
//{
//	myArray<int>array1(10);
//	for (int i = 0; i < array1.getCapacity(); i++)
//	{
//		array1.pushBack(i);
//	}
//	printArray(array1);
//}

class Person
{
	public:
		string p_name;
		int p_age;
	public:
		Person() {};
		Person(string name, int age)
		{
			this->p_name = name;
			this->p_age = age;
		}
};

void printPersonArray(myArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名为: " << arr[i].p_name << ", 年龄为: " << arr[i].p_age << endl;
	}
}

void test2()
{
	// 创建数组
	myArray<Person>pArray(10);

	Person p1("孙悟空", 21);
	Person p2("猪八戒", 22);
	Person p3("沙僧", 23);

	pArray.pushBack(p1);
	pArray.pushBack(p2);
	pArray.pushBack(p3);

	printPersonArray(pArray);

	pArray.popBack();
	printPersonArray(pArray);
}

void printTestArray(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "数组数据为: " << arr[i] << endl;
	}
}

void printTestPersonArray(Person arr[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名: " << arr[i].p_name << ", 年龄: " << arr[i].p_age << endl;
	}
}

void test4()
{
	Person arr[10];
	Person p1("孙悟空", 1);
	Person p2("猪八戒", 2);
	Person p3("沙僧", 3);
	arr[0] = p1;
	arr[1] = p2;
	arr[2] = p3;

	printTestPersonArray(arr);
}

void test3()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	printTestArray(arr);
}

void test5()
{
	// 测试拷贝构造
	/*myArray<int>arr1(10);
	for (int i = 0; i < 10; i++)
	{
		arr1.pushBack(i);
	}

	printArray(arr1);
	myArray<int>arr2(arr1);
	printArray(arr2);*/

	Person p1("孙悟空", 1);
	Person p2(p1);
	cout << "姓名: " << p2.p_name << ", 年龄: " << p2.p_age << endl;
}

int main()
{
	//test2();
	test5();
	return 0;
}