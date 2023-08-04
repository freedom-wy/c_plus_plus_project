#include <iostream>
#include <sstream>
using namespace std;

class Cmyexception
{
	// 异常类
private:
	string m_strfilename;
	string m_strfuncname;
	string m_strerr;
	int nlinenum;
public:
	Cmyexception() {};
	Cmyexception(string strfilename, string strfuncname, string strerr, int nlinenum)
	{
		this->m_strfilename = strfilename;
		this->m_strfuncname = strfuncname;
		this->m_strerr = strerr;
		this->nlinenum = nlinenum;
	}

	void ErrorProc()
	{
		cout << this->m_strfilename << endl;
		cout << this->m_strfuncname << endl;
		cout << this->m_strerr << endl;
		cout << this->nlinenum << endl;
	}
};

class CAddOverflowException :public Cmyexception
{
public:
	CAddOverflowException(string strfilename, string strfuncname, string strerr, int nlinenum):
		Cmyexception(strfilename, strfuncname, strerr, nlinenum)
	{}
};

//class CAddOverflowException : public Cmyexception
//{
//public:
//	CAddOverflowException(string strfilename, string strfuncname, string strerr, size_t nlinenum) :
//		Cmyexception(strfilename, strfuncname, strerr, nlinenum)
//	{ }
//};

int Add(int n1, int n2)
{
	int nRet = n1 + n2;
	if (n1 > 0 && n2 > 0 && nRet < 0)
	{
		throw CAddOverflowException(__FILE__, __FUNCTION__, "加法溢出", __LINE__);
	}
	return nRet;
}

class Student
{
private:
	string name;
public:
	Student(string name)
	{
		this->name = name;
	}
	~Student() {};

	virtual void getInfo()=0;
	const string getName()
	{
		return this->name;
	}
};

class Student1 :public Student
{
private:
	int age;
public:
	Student1(string name, int age) :Student(name) // 子类中调用父类构造方法
	{
		this->age = age;
	}
	~Student1() {};

	void getInfo()
	{
		cout << "姓名: " << this->getName() << ", 年龄: " << this->age << endl;
	}
};

void test1()
{
	Student* s1 = new Student1("hello", 11);
	s1->getInfo();
	delete s1;
}


int main()
{
	//try
	//{
	//	Add(0x7fffffff, 2);
	//}
	//catch (Cmyexception& e)
	//{
	//	e.ErrorProc();
	//}
	////cout << __FILE__ << endl;
	test1();
	return 0;
}