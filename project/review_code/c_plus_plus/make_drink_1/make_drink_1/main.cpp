#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "���췽��" << endl;
	}
	//virtual ~Base()
	//{
	//	// ��Ҫ����������, ����ֻ�ܵ���base������, ���ܵ������������
	//	cout << "��������" << endl;
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
	cout << "��������" << endl;
}

class Coffee :public Base
{
public:
	Coffee()
	{
		cout << "����coffee�Ĺ��췽��" << endl;
	}
	~Coffee()
	{
		cout << "����coffee����������" << endl;
	}
	void ShaoShui()
	{
		cout << "��ũ��ɽȪ" << endl;
	}
	void FangYuanLiao()
	{
		cout << "���뿧��" << endl;
	}
	void Wait()
	{
		cout << "�������" << endl;
	}
	void DaoRuBeiZhong()
	{
		cout << "������˱�" << endl;
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
	// ��ϰ��̬
	test1();
	return 0;
}