#include <iostream>
using namespace std;

// ��ͨ����ָ��
int CompareString(const string& s1, const string& s2);
typedef int (*funcptr)(const string& s1, const string& s2);

int CompareString(const string& s1, const string& s2)
{
	return s1.compare(s2);
}

void test1()
{
	// ����ָ��
	string s1 = "abc";
	string s2 = "abc";
	// ����ָ��
	funcptr p1 = CompareString;
	int val1 = p1(s1, s2);
	// ����ָ������
	funcptr CompareStringArry[2] = { CompareString, CompareString };
	int val2 = CompareStringArry[0](s1, s2);
	cout << val2 << endl;
}

// ���Աָ��
class CHero;
class CSodier;
typedef void (CHero::* SkillptrType)(int nIdx); // ���Աָ��
typedef int(CSodier::* agePtrType); // ������ָ��

class CHero
{
public:
	CHero()
	{
		cout << "CHero��Ĭ�Ϲ��췽��" << endl;
	}
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
};

class CSodier :public CHero
{
public:
	CSodier(int val)
	{
		this->age = val;
		cout << "CSodier��Ĭ�Ϲ��췽��" << endl;
	}
	// ������д�����鷽��
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
		default:
			break;
		}
	}
	int age;
};

void test2()
{
	//SkillptrType spt = (SkillptrType)&CSodier::Skill; // ���Աָ�븳ֵ
	//CSodier c1(1);
	//(&c1->*spt)(1); // ���Աָ�����
	agePtrType agePtr = &CSodier::age; // ������ָ�븳ֵ
	CSodier c2(1);
	cout << "սʿ������: " << (&c2->*agePtr) << endl;
}


int main()
{
	//test1();
	test2();
	cout << "hello world" << endl;
	return 0;
}