#include <iostream>
using namespace std;

class A
{
	// �����СΪ1
};

class B
{
	// ���СΪ4
public:
	int b1 = 1;
	static const int b2 = 2;
};

class C
{
	// ���СΪ8
public:
	int c1 = 4;
	A a;
};

class D
	// 8
{
public:
	string s1 = "abc";
	int d1 = 1;
	virtual void test1()
	{
		cout << "test1" << endl;
	}
	virtual void test2()
	{
		cout << "test2" << endl;
	}
};

class E :public D
{
	// �̳�D�������麯��8
public:
	virtual void test10()
	{
		cout << "test10" << endl;
	}
	virtual void test20()
	{
		cout << "test20" << endl;
	}
};

class F :public D
{
	// �����麯��8
public:
	virtual void test1()
	{
		cout << "F" << endl;
	}
	virtual void test100()
	{
		cout << "test100" << endl;
	}
};

class G :public D, public E, public F
{
	// 24, int+���ָ��
public:
	virtual void test1000()
	{
		cout << "test1000" << endl;
	}
};


int* a = NULL;

void test1()
{
	int* nArray = new int[5];
	// int nArray[5];
	for (int i = 0; i < 5; i++)
	{
		nArray[i] = i;
	}
	a = nArray;
	for (int i = 0; i < 5; i++)
	{
		cout << nArray[i] << endl;
	}
	return;
}




int main()
{
	/*
	A a;
	cout << "A����Ĵ�СΪ: " << sizeof(a) << endl;
	B b;
	cout << "B����Ĵ�СΪ: " << sizeof(b) << endl;
	cout << sizeof(double) << endl;
	C c;
	cout << "C����Ĵ�СΪ: " << sizeof(c) << endl;
	D d;
	cout << "D����Ĵ�СΪ: " << sizeof(d) << endl;
	E e;
	cout << e.s1 << endl;
	cout << "E����Ĵ�СΪ: " << sizeof(e) << endl;
	F f;
	cout << "F����Ĵ�СΪ: " << sizeof(f) << endl;
	G g;
	cout << "G����Ĵ�СΪ: " << sizeof(g) << endl;
	*/

	test1();
	for (size_t i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}