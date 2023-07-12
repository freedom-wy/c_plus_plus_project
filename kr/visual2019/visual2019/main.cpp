#include <iostream>
using namespace std;


int* func1()
{
	int a = 10;
	return &a;
}

int* func2()
{
	int* b = new int(10);
	return b;
}

void test1()
{
	int* arr = new int[10]; // �ڶ�����������
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	// ɾ����������
	delete[] arr;

	/*for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}*/ // ɾ�����������޷�����
}

// ֵ����
void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ��ַ����
void mySwap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ���ô���
void mySwap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

class Person {
public:
	// �����������д����ֵҲ��дvoid, ����������������ͬ
	Person(string name, int age) 
	{
		cout << "���췽��" << endl;
		this->name = name;
		this->age = new int(age);
	}
	Person(const Person& p)
	{
		cout << "�������캯��" << endl;
		this->name = p.name;
		this->age = new int(*(p.age));
	}
	~Person()
	{
		if (this->age != nullptr)
		{
			cout << "����" << endl;
			delete this->age;
		}
	}

	string getName()
	{
		return this->name;
	}

	int getAge()
	{
		return *(this->age);
	}
public:
	static int m_A; //��̬��Ա���������������������ʼ��
private:
	string name;
	int* age;
};

int Person::m_A = 10;

void test2()
{
	Person p1 = Person("����", 18);
	p1.m_A = 100;
	cout << "����: " << p1.getName() << ", ����: " << p1.getAge() << ", m_A��ֵΪ: " << p1.m_A << endl;
	Person p2 = Person(p1); // ���ÿ������췽��
	p2.m_A = 200;
	cout << "����: " << p2.getName() << ", ����: " << p2.getAge() << ", m_A��ֵΪ: " << p2.m_A << endl;
	cout << "ͨ����������m_A��ֵ: " << Person::m_A << endl;
}

class CBuff
{
private:
	void init()
	{
		this->m_pBuff = nullptr;
		this->m_nSize = 0;
		this->m_pnRefCount = nullptr;
	}
	void uninit()
	{
		if (this->m_pnRefCount != nullptr)
		{
			--(*this->m_pnRefCount);
		}
		if (this->m_pnRefCount == nullptr)
		{
			delete[] this->m_pBuff;
			delete this->m_pnRefCount;
			this->m_pBuff = nullptr;
			this->m_pnRefCount = nullptr;
			this->m_nSize = 0;
		}
	}
public:
	CBuff()
	{
		cout << "Ĭ�Ϲ��췽��" << endl;
		init();
	}
	CBuff(const CBuff& obj)
	{
		cout << "��������-ǳ����" << endl;
		if (obj.m_pnRefCount != nullptr)
		{
			this->m_pBuff = obj.m_pBuff;
			this->m_nSize = obj.m_nSize;
			this->m_pnRefCount = obj.m_pnRefCount;
		}

		++(*this->m_pnRefCount);
		/*this->m_pBuff = new char[obj.m_nSize];
		memset(this->m_pBuff, 0, obj.m_nSize);
		memcpy(this->m_pBuff, obj.m_pBuff, obj.m_nSize);
		this->m_nSize = obj.m_nSize;*/
	}
	~CBuff()
	{
		cout << "��������" << endl;
		uninit();
	}
	void Set(const char* pBuff, int nSize)
	{
		uninit();
		this->m_pBuff = new char[nSize];
		this->m_pnRefCount = new int(1);
		memset(this->m_pBuff, 0, nSize);
		memcpy(this->m_pBuff, pBuff, nSize);
		this->m_nSize = nSize;
	}

	char* Get()
	{
		return this->m_pBuff;
	}

public:
	static int value; // ��̬��������

private:
	char* m_pBuff;
	int m_nSize;
	int* m_pnRefCount; //������
};

int CBuff::value = 1;

void test3()
{
	CBuff *buf = new CBuff();
	buf->Set("\x55\x55\x55\x55", 4);

	CBuff* buf1 = new CBuff();
	buf1->Set("\x44\x44\x44\x44\x44\x44\x44\x44\x44\x44\x44\x44", 100);

	CBuff *buf3 = buf1;
	delete buf;
	delete buf1;
	delete buf3;

}


int main() {
	//int* p1 = func1();
	//cout << "��Ҫ���ؾֲ������ĵ�ַ" << *p1 << endl; // 10
	//cout << "��Ҫ���ؾֲ������ĵ�ַ" << *p1 << endl; // 2065865096
	//int* p2 = func2();
	//cout << "���ض�������" << *p2 << endl;
	//delete p2;
	// cout << "���ض�������" << *p2 << endl; // ɾ��������޷��鿴�ڴ�ָ������
	// test1();
	/*int a = 10;
	int b = 20;
	mySwap01(a, b);
	cout << "�������a: " << a << ", �������b: " << b << endl;*/
	//test2();
	test3();
	cout << "hello world" << endl;
	return 0;
}