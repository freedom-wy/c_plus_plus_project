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


int main()
{
	/*A a;
	cout << "A����Ĵ�СΪ: " << sizeof(a) << endl;
	B b;
	cout << "B����Ĵ�СΪ: " << sizeof(b) << endl;
	cout << sizeof(double) << endl;
	C c;
	cout << "C����Ĵ�СΪ: " << sizeof(c) << endl;
	D d;
	cout << "D����Ĵ�СΪ: " << sizeof(d) << endl;
	E e;
	cout << "E����Ĵ�СΪ: " << sizeof(e) << endl;
	F f;
	cout << "F����Ĵ�СΪ: " << sizeof(f) << endl;*/
	G g;
	cout << "G����Ĵ�СΪ: " << sizeof(g) << endl;
	return 0;
}