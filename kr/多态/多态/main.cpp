#include <iostream>
#include <Windows.h>
using namespace std;

// 普通函数指针
//int CompareString(const string& s1, const string& s2);
//typedef int (*funcptr)(const string& s1, const string& s2);
//
//int CompareString(const string& s1, const string& s2)
//{
//	return s1.compare(s2);
//}

//void test1()
//{
//	// 函数指针
//	string s1 = "abc";
//	string s2 = "abc";
//	// 函数指针
//	funcptr p1 = CompareString;
//	int val1 = p1(s1, s2);
//	// 函数指针数组
//	funcptr CompareStringArry[2] = { CompareString, CompareString };
//	int val2 = CompareStringArry[0](s1, s2);
//	cout << val2 << endl;
//}

// 类成员指针
//class CHero;
//class CSodier;
//typedef void (CHero::* SkillptrType)(int nIdx); // 类成员指针
//typedef int(CSodier::* agePtrType); // 类属性指针

//class CHero
//{
//public:
//	CHero()
//	{
//		cout << "CHero的默认构造方法" << endl;
//	}
//	virtual void Skill(int nIdx)
//	{
//		switch (nIdx)
//		{
//		case 0:
//			cout << "平A" << endl;
//			break;
//		case 1:
//			cout << "回血" << endl;
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
//		cout << "CSodier的默认构造方法" << endl;
//	}
//	// 子类重写父类虚方法
//	void Skill(int nIdx)
//	{
//		switch (nIdx)
//		{
//		case 0:
//			cout << "战士平A" << endl;
//			break;
//		case 1:
//			cout << "战士回血" << endl;
//			break;
//		default:
//			break;
//		}
//	}
//	int age;
//};

//void test2()
//{
//	//SkillptrType spt = (SkillptrType)&CSodier::Skill; // 类成员指针赋值
//	//CSodier c1(1);
//	//(&c1->*spt)(1); // 类成员指针调用
//	//agePtrType agePtr = &CSodier::age; // 类属性指针赋值
//	//CSodier c2(1);
//	//cout << "战士的年龄: " << (&c2->*agePtr) << endl;
//	/*CSodier c3(0x11111111);
//	CHero& c4 = c3;
//	c4.Skill(1);*/
//	CHero* c2 = new CSodier(0x11111111);
//	c2->Skill(1);
//	cout << "hello world" << endl;
//}


/* 虚函数（函数覆盖）原理
对象首四个字节的地址：虚表指针
虚函数地址的数组：虚表

内存结构：
CB b;
|------------|        虚表(vftable)
|__vfptr     | -----> |----------|
|m_nA        |        |&CB:Foo   |
|m_nB        |        |&CB::Foo1 |
|------------|        |----------|

编译期：
   CB b;
   1）拷贝父类的虚表{&CA:Foo, &CA::Foo1}
   2）将子类重写了父类的虚函数地址替换虚表中的对应的地址{&CB:Foo, &CB::Foo1}

运行期：
   1.构造对象 new CB
	 将自己的虚表的地址填入对象的虚表指针（__vfptr，位于对象首四个字节）
   2.调用虚函数
	 先从对象首四个字节获取虚表指针，然后通过虚表指针获取虚表，然后通过虚表获取虚函数的地址，调用
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
	//Animal a1;  // 虚表指针0x0041AB34--outPrint方法地址0x00411532
	//Cat c1;  //虚表指针0x0041AB44--outPrint方法地址0x00411532
	// Animal* a2 = new Animal();  // 虚表指针0x00810E10---outPrint方法地址0x0041ab34
	//Cat* c2 = new Cat();  // 虚表指针0x00810E40---outPrint方法地址0x0041ab44


	Animal* a2 = new Animal();  // 虚表指针0x00810E10---outPrint方法地址0x0041ab34
	// 获取虚表指针
	int vfptrAddress = *(int*)a2;
	DWORD dwOld = 0;
	VirtualProtect((void*)vfptrAddress, 0x1000, PAGE_EXECUTE_READWRITE, &dwOld);
	// 通过索引改变要修改的方法
	*((int*)vfptrAddress+1) = (int)test;
	a2->outPrint1();
	a2->outPrint2();
	
	return 0;
}