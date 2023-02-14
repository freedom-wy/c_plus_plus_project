#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "构造方法" << endl;
	}
	//virtual ~Base()
	//{
	//	// 需要设置需析构, 否则只能调用base的析构, 不能调用子类的析构
	//	cout << "析构方法" << endl;
	//}
	virtual ~Base() = 0;
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

Base::~Base()
{
	cout << "纯虚析构" << endl;
}

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
	/*Coffee c1;
	c1._do();*/
	Base* c1 = new Coffee;
	c1->_do();
	delete c1;
}



int main()
{
	// 复习多态
	test1();
	return 0;
}