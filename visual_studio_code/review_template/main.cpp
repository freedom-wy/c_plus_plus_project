#include <iostream>
using namespace std;


template<class T>
class MyArray
{
private:
	T* pAddress;
	int mCapacity;
	int mSize;
public:
	// ���췽��
	MyArray(int capacity)
	{
		cout << "array���췽��" << endl;
		this->mCapacity = capacity;
		this->mSize = 0;
		this->pAddress = new T[this->mCapacity]; // new int[10]
	}
	// ��������
	~MyArray()
	{
		cout << "array��������" << endl;
		delete[] this->pAddress;
		this->pAddress = NULL;
		this->mCapacity = 0;
		this->mSize = 0;
	}
	// ��Ա����
	void PushBack(const T& val)
	{
		if (this->mCapacity == this->mSize)
		{
			return;
		}
		this->pAddress[this->mSize] = val;
		this->mSize++;
	}

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	void PrintArray()
	{
		for (int i = 0; i < this->mSize; i++)
		{
			cout << "Ԫ������Ϊ: " << this->pAddress[i] << endl;
		}
	}
};

void test1()
{
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.PushBack(i);
	}
	arr1.PrintArray();
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
			cout << "Person���췽��" << endl;
		}
		~Person()
		{
			cout << "Person��������" << endl;
		}
};

void printPersonArray(MyArray<Person>& personarr)
{
	for (int i = 0; i < 2; i++)
	{
		cout << "����Ϊ: " << personarr[i].name << ", ����Ϊ: " << personarr[i].age << endl;
	}
}

void test2()
{
	MyArray<Person>arr2(2);
	Person p1("����", 1);
	Person p2("����", 2);
	arr2.PushBack(p1);
	arr2.PushBack(p2);
	printPersonArray(arr2);
}



int main()
{
	test2();
	return 0;
}