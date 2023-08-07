#include <iostream>
using namespace std;

void test1()
{
	// 右值引用
	int a = 1;
	int& b = a; // 左值引用
	//int& c = 1; // 报错，不能对右值进行引用
	int&& c = 1; // 右值引用
	const int& d = 1; // 万能引用
	cout << "a: " << a << ", c: " << c << endl;
	cout << "hello world" << endl;
}

class CA
{
private:
	int* mp;
public:
	CA(int n) :mp(new int(n)) { cout << "CA::CA(int)" << endl; }
	~CA()
	{
		if (mp != NULL)
		{
			delete mp;
		}
		cout << "CA::~CA" << endl;
	}
	CA(const CA& obj)
	{
		cout << "拷贝构造" << endl;
		this->mp = new int(*obj.mp);
	}

	CA(CA&& obj) // 当有移动构造时，不走拷贝构造
	{
		this->mp = obj.mp;
		obj.mp = NULL;
	}
};

CA foo()
{
	 // 创建一个函数
	CA a(1);
	return a; // 如果没有移动构造, 走拷贝构造
}

void test2()
{
	CA b = foo();
	cout << "hello world" << endl;
}


int main()
{
	//test1();
	//test2();
	CA a(12);
	//CA a1 = a;
	CA a1 = (CA&&)a;
	return 0;
}