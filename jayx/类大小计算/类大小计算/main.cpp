#include <iostream>
using namespace std;

class A
{
	// 空类大小为1
};

class B
{
	// 类大小为4
public:
	int b1 = 1;
	static const int b2 = 2;
};

class C
{
	// 类大小为8
public:
	int c1 = 4;
	A a;
};

class D
	// 8
{
public:
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
	// 继承D不覆盖虚函数8
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
	// 覆盖虚函数8
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
	// 24, int+虚表指针
public:
	virtual void test1000()
	{
		cout << "test1000" << endl;
	}
};


int main()
{
	/*A a;
	cout << "A对象的大小为: " << sizeof(a) << endl;
	B b;
	cout << "B对象的大小为: " << sizeof(b) << endl;
	cout << sizeof(double) << endl;
	C c;
	cout << "C对象的大小为: " << sizeof(c) << endl;
	D d;
	cout << "D对象的大小为: " << sizeof(d) << endl;
	E e;
	cout << "E对象的大小为: " << sizeof(e) << endl;
	F f;
	cout << "F对象的大小为: " << sizeof(f) << endl;*/
	G g;
	cout << "G对象的大小为: " << sizeof(g) << endl;
	return 0;
}