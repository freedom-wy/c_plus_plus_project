#include <iostream>
using namespace std;

// 普通函数指针
int CompareString(const string& s1, const string& s2);
typedef int (*funcptr)(const string& s1, const string& s2);

int CompareString(const string& s1, const string& s2)
{
	return s1.compare(s2);
}

void test1()
{
	// 函数指针
	string s1 = "abc";
	string s2 = "abc";
	// 函数指针
	funcptr p1 = CompareString;
	int val1 = p1(s1, s2);
	// 函数指针数组
	funcptr CompareStringArry[2] = { CompareString, CompareString };
	int val2 = CompareStringArry[0](s1, s2);
	cout << val2 << endl;
}

// 类成员指针
class CHero;
class CSodier;
typedef void (CHero::* SkillptrType)(int nIdx); // 类成员指针
typedef int(CSodier::* agePtrType); // 类属性指针

class CHero
{
public:
	CHero()
	{
		cout << "CHero的默认构造方法" << endl;
	}
	virtual void Skill(int nIdx)
	{
		switch (nIdx)
		{
		case 0:
			cout << "平A" << endl;
			break;
		case 1:
			cout << "回血" << endl;
			break;
		default:
			break;
		}
	}
};

class CSodier :public CHero
{
public:
	CSodier(int val)
	{
		this->age = val;
		cout << "CSodier的默认构造方法" << endl;
	}
	// 子类重写父类虚方法
	void Skill(int nIdx)
	{
		switch (nIdx)
		{
		case 0:
			cout << "战士平A" << endl;
			break;
		case 1:
			cout << "战士回血" << endl;
			break;
		default:
			break;
		}
	}
	int age;
};

void test2()
{
	//SkillptrType spt = (SkillptrType)&CSodier::Skill; // 类成员指针赋值
	//CSodier c1(1);
	//(&c1->*spt)(1); // 类成员指针调用
	agePtrType agePtr = &CSodier::age; // 类属性指针赋值
	CSodier c2(1);
	cout << "战士的年龄: " << (&c2->*agePtr) << endl;
}


int main()
{
	//test1();
	test2();
	cout << "hello world" << endl;
	return 0;
}