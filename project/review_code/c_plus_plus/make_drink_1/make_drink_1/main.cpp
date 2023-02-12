#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "构造方法" << endl;
	}
	~Base()
	{
		cout << "析构方法" << endl;
	}
	virtual void ShaoShui() = 0;
	virtual void FangYuanLiao() = 0;
	virtual void Wait() = 0;
	virtual void DaoRuBeiZhong() = 0;

	void _do()
	{
		this->ShaoShui();
		this->FangYuanLiao();
		this->Wait();
		this->DaoRuBeiZhong();
	}
};

class Coffee :public Base
{
public:
	Coffee()
	{
		cout << "子类coffee的构造方法" << endl;
	}
	~Coffee()
	{
		cout << "子类coffee的析构方法" << endl;
	}
	void ShaoShui()
	{
		cout << "烧农夫山泉" << endl;
	}
	void FangYuanLiao()
	{
		cout << "放入咖啡" << endl;
	}
	void Wait()
	{
		cout << "搅拌均匀" << endl;
	}
	void DaoRuBeiZhong()
	{
		cout << "倒入马克杯" << endl;
	}
};

void test1()
{
	Coffee c1;
	c1._do();
}



int main()
{
	// 复习多态
	test1();
	return 0;
}