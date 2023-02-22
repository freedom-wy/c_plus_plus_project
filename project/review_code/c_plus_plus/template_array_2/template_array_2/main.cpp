#include <iostream>
using namespace std;


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
};

template<class T>
class MyIntArray
{
	friend void PrintPersonArray(MyIntArray<Person>& a);
private:
	T* arr;
	int capacity;
	int size;
public:
	MyIntArray(int capacity)
	{
		if (capacity > 0)
		{
			this->size = 0;
			this->capacity = capacity;
			this->arr = new T[this->capacity];
		}
	}
	MyIntArray(const MyIntArray& a)
	{
		this->capacity = a.capacity;
		this->size = a.size;
		this->arr = new T[this->capacity];
		for (int i = 0; i < this->GetSize(); i++)
		{
			this->arr[i] = a.arr[i];
		}
	}
	~MyIntArray()
	{
		if (this->arr != NULL)
		{
			cout << "����" << endl;
			delete[] this->arr;
			this->arr = NULL;
		}
	}
public:
	int GetSize()
	{
		return this->size;
	}
	int GetCpacity()
	{
		return this->capacity;
	}

	void Push_back(T& v)
	{
		this->arr[this->GetSize()] = v;
		this->size++;
	}

	/*void PrintMyIntArray()
	{
		for (int i = 0; i < this->GetSize(); i++)
		{
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}*/
};

void PrintPersonArray(MyIntArray<Person>& a)
{
	for (int i = 0; i < a.GetSize(); i++)
	{
		cout << "����: " << a.arr[i].name << ", ����: " << a.arr[i].age << endl;
	}
}

int main()
{
	/*MyIntArray<int> arr1(10);
	for (int i = 0; i < 10; i++)
	{
		arr1.Push_back(i);
	}*/

	/*cout << "��������Ϊ: " << arr1.GetCpacity() << endl;
	cout << "�����СΪ: " << arr1.GetSize() << endl;

	arr1.PrintMyIntArray();*/

	/*MyIntArray<int> arr2(arr1);
	cout << "��������Ϊ: " << arr2.GetCpacity() << endl;
	cout << "�����СΪ: " << arr2.GetSize() << endl;

	arr2.PrintMyIntArray();*/


	/*int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	if (arr != NULL)
	{
		cout << "ɾ��������" << endl;
		delete[] arr;
	}*/

	MyIntArray<Person> m1(2);
	Person p1("����", 1);
	Person p2("����", 2);
	m1.Push_back(p1);
	m1.Push_back(p2);
	//m1.PrintMyIntArray();
	PrintPersonArray(m1);
}

