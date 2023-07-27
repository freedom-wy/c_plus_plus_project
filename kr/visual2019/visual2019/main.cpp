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

class CA
{
public:
	void TestA()
	{
		cout << "CA::TestA()" << endl;
	}
	void TestA(const char*)
	{
		cout << "CA::Test(const char*)" << endl;
	}
protected:
	int m_n = 0xAAAAAAAA;
};

class CB :public CA
{
public:
	void TestA()
	{
		cout << "CB����Test()" << endl;
		m_n = 0xDDDDDDDD;//���ȵ����Լ��ġ�
		CA::m_n = 0xEEEEEEEE; //��ʾ�ĵ��ø���ġ�
	}
private:
	int m_n = 0xBBBBBBBB;
};

class Animal
{
public:
	Animal()
	{
		this->speak();
	}
	/*virtual ~Animal()
	{
		cout << "Animal������" << endl;
	}*/
	virtual ~Animal() = 0;
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
	virtual void run()
	{
		cout << "��������" << endl;
	}
};

Animal::~Animal()
{
	cout << "Animal��������" << endl;
}

class Cat :public Animal
{
public:
	Cat()
	{
		this->speak();
	}
	~Cat()
	{
		cout << "Cat��������" << endl;
	}
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
	virtual void run()
	{
		cout << "��������" << endl;
	}
};

//class Dog :public Animal
//{
//public:
//	Dog()
//	{
//		this->c = 3;
//	}
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//private:
//	int c;
//};

//void DoSpeak(Animal& animal)
//{
//	animal.speak();
//}
int test4()
{
	/*Cat cat;
	DoSpeak(cat);*/
	/*Animal* cat = new Cat();
	cat->speak();
	delete cat;*/
	Animal* a = new Cat();
	a->speak();
	delete a;
	return 0;
}

class CHero
{
public:
	//CHero(int nType)
	//{
	//	this->m_nType = nType;
	//}

	virtual void Skill(int nIdx)
	{
		switch (nIdx)
		{
		case 0:
			cout << "ƽA" << endl;
			break;
		case 1:
			cout << "��Ѫ" << endl;
			break;
		default:
			break;
		}
	}

//private:
//	int m_nType;
};

class CSodier :public CHero
{
public:
	void Skill(int nIdx)
	{
		switch (nIdx)
		{
		case 0:
			cout << "սʿƽA" << endl;
			break;
		case 1:
			cout << "սʿ��Ѫ" << endl;
			break;
		case 2:
			cout << "С��ɵ�" << endl;
			break;
		case 3:
			cout << "��ɰ��" << endl;
			break;
		case 4:
			cout << "������, ������" << endl;
			break;
		default:
			break;
		}
	}
};

class CWizard :public CHero
{
public:
	void Skill(int nIdx)
	{
		switch (nIdx)
		{
		case 0:
			cout << "��ʦƽA" << endl;
			break;
		case 1:
			cout << "��ʦ��Ѫ" << endl;
			break;
		case 2:
			cout << "������" << endl;
			break;
		case 3:
			cout << "����ʮ����" << endl;
			break;
		case 4:
			cout << "��������, ���޷���" << endl;
			break;
		default:
			break;
		}
	}
};

int test5()
{
	CHero* aryHeros[6]; //���ָ��
	for (int i = 0; i < 6; i++)
	{
		CHero* c = NULL;
		if (i % 2 == 0)
		{
			c = new CSodier();
		}
		else
		{
			c = new CWizard();
		}
		aryHeros[i] = c;
	}

	for (int i = 0; i < 6; i++)
	{
		aryHeros[i]->Skill(i);
	}

	delete[] aryHeros;

	return 0;
}

void test7()
{
	// �Ƚ��е�����������, ���ȵ����������
	int a = 0;
	cout << ++a << endl; // 1
	cout << a << endl; // 1
	// �Ƚ������㼴����������
	int b = 0;
	cout << b++ << endl; // 0
	cout << b << endl; // 1
}

class CMystring
{
private:
	char m_szBuf[256];
public:
	CMystring(const char* sz)
	{
		memcpy(this->m_szBuf, sz, strlen(sz) + 1);
	}
};