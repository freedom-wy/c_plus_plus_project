#include <iostream>
#include <Windows.h>
using namespace std;

// ��ͨ����ָ��
//int CompareString(const string& s1, const string& s2);
//typedef int (*funcptr)(const string& s1, const string& s2);
//
//int CompareString(const string& s1, const string& s2)
//{
//	return s1.compare(s2);
//}

//void test1()
//{
//	// ����ָ��
//	string s1 = "abc";
//	string s2 = "abc";
//	// ����ָ��
//	funcptr p1 = CompareString;
//	int val1 = p1(s1, s2);
//	// ����ָ������
//	funcptr CompareStringArry[2] = { CompareString, CompareString };
//	int val2 = CompareStringArry[0](s1, s2);
//	cout << val2 << endl;
//}

// ���Աָ��
//class CHero;
//class CSodier;
//typedef void (CHero::* SkillptrType)(int nIdx); // ���Աָ��
//typedef int(CSodier::* agePtrType); // ������ָ��

//class CHero
//{
//public:
//	CHero()
//	{
//		cout << "CHero��Ĭ�Ϲ��췽��" << endl;
//	}
//	virtual void Skill(int nIdx)
//	{
//		switch (nIdx)
//		{
//		case 0:
//			cout << "ƽA" << endl;
//			break;
//		case 1:
//			cout << "��Ѫ" << endl;
//			break;
//		default:
//			break;
//		}
//	}
//};

//class CSodier :public CHero
//{
//public:
//	CSodier(int val)
//	{
//		this->age = val;
//		cout << "CSodier��Ĭ�Ϲ��췽��" << endl;
//	}
//	// ������д�����鷽��
//	void Skill(int nIdx)
//	{
//		switch (nIdx)
//		{
//		case 0:
//			cout << "սʿƽA" << endl;
//			break;
//		case 1:
//			cout << "սʿ��Ѫ" << endl;
//			break;
//		default:
//			break;
//		}
//	}
//	int age;
//};

//void test2()
//{
//	//SkillptrType spt = (SkillptrType)&CSodier::Skill; // ���Աָ�븳ֵ
//	//CSodier c1(1);
//	//(&c1->*spt)(1); // ���Աָ�����
//	//agePtrType agePtr = &CSodier::age; // ������ָ�븳ֵ
//	//CSodier c2(1);
//	//cout << "սʿ������: " << (&c2->*agePtr) << endl;
//	/*CSodier c3(0x11111111);
//	CHero& c4 = c3;
//	c4.Skill(1);*/
//	CHero* c2 = new CSodier(0x11111111);
//	c2->Skill(1);
//	cout << "hello world" << endl;
//}


/* �麯�����������ǣ�ԭ��
�������ĸ��ֽڵĵ�ַ�����ָ��
�麯����ַ�����飺���

�ڴ�ṹ��
CB b;
|------------|        ���(vftable)
|__vfptr     | -----> |----------|
|m_nA        |        |&CB:Foo   |
|m_nB        |        |&CB::Foo1 |
|------------|        |----------|

�����ڣ�
   CB b;
   1��������������{&CA:Foo, &CA::Foo1}
   2����������д�˸�����麯����ַ�滻����еĶ�Ӧ�ĵ�ַ{&CB:Foo, &CB::Foo1}

�����ڣ�
   1.������� new CB
	 ���Լ������ĵ�ַ�����������ָ�루__vfptr��λ�ڶ������ĸ��ֽڣ�
   2.�����麯��
	 �ȴӶ������ĸ��ֽڻ�ȡ���ָ�룬Ȼ��ͨ�����ָ���ȡ���Ȼ��ͨ������ȡ�麯���ĵ�ַ������
*/

//class CA
//{
//public:
//	CA()
//	{
//		cout << "CA::CA" << endl;
//	}
//	virtual void Foo1() { cout << "CA::Foo1" << endl; }
//	virtual void Foo() { cout << "CA::Foo" << endl; }
//	int m_nA = 0xAAAAAAAA;
//};
//
//class CB :public CA
//{
//public:
//	CB()
//	{
//		cout << "CB::CB" << endl;
//	}
//	void Foo() { cout << "CB::Foo" << endl; }
//	void Foo1() { cout << "CB::Foo1" << endl; }
//	int m_nB = 0xBBBBBBBB;
//};
//
//class CD :public CA
//{
//public:
//	CD()
//	{
//		cout << "CD::CD" << endl;
//	}
//	virtual void Foo() { cout << "CD::Foo" << endl; }
//	virtual void Foo1() { cout << "CD::Foo1" << endl; }
//	void Test()
//	{
//		CA::Foo();
//	}
//	int m_nB = 0xDDDDDDDD;
//};
//
//void printFoo(CA& c)
//{
//	c.Foo();
//	cout << "hello world" << endl;
//}
//
//int test3()
//{
//	CB c1;
//	printFoo(c1);
//	CA* c2 = new CB();
//	c2->Foo();
//	return 0;
//}


class Animal
{
public:
	virtual void outPrint1()
	{
		cout << "Animal1" << endl;
	}
	virtual void outPrint2()
	{
		cout << "Animal2" << endl;
	}
	virtual void outPrint3()
	{
		cout << "Animal3" << endl;
	}
};


class Cat : public Animal
{
public:
	virtual void outPrint2()
	{
		cout << "CAT2" << endl;
	}

	virtual void outPrint4()
	{
		cout << "CAT4" << endl;
	}
};

void test()
{
	cout << "TEST" << endl;
}


int main()
{
	//Animal a1;  // ���ָ��0x0041AB34--outPrint������ַ0x00411532
	//Cat c1;  //���ָ��0x0041AB44--outPrint������ַ0x00411532
	// Animal* a2 = new Animal();  // ���ָ��0x00810E10---outPrint������ַ0x0041ab34
	//Cat* c2 = new Cat();  // ���ָ��0x00810E40---outPrint������ַ0x0041ab44


	Animal* a2 = new Animal();  // ���ָ��0x00810E10---outPrint������ַ0x0041ab34
	// ��ȡ���ָ��
	int vfptrAddress = *(int*)a2;
	DWORD dwOld = 0;
	VirtualProtect((void*)vfptrAddress, 0x1000, PAGE_EXECUTE_READWRITE, &dwOld);
	// ͨ�������ı�Ҫ�޸ĵķ���
	*((int*)vfptrAddress+1) = (int)test;
	a2->outPrint1();
	a2->outPrint2();
	
	return 0;
}