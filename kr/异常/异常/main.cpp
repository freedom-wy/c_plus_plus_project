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
	Cmyexception(string m_strfilename, string m_strfuncname, string m_strerr, int nlinenum)
	{
		this->m_strfilename = m_strfilename;
		this->m_strfuncname = m_strfuncname;
		this->m_strerr = m_strerr;
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
	CAddOverflowException(string m_strfilename, string m_strfuncname, string m_strerr, int nlinenum)
	{
		Cmyexception myexception(m_strfilename, m_strfuncname, m_strerr, nlinenum);
	}
};

int Add(int n1, int n2)
{
	int nRet = n1 + n2;
	if (n1 > 0 && n2 > 0 && nRet < 0)
	{
		throw CAddOverflowException(__FILE__, __FUNCTION__, "加法溢出", __LINE__);
	}
	return nRet;
}



int main()
{
	try
	{
		Add(0x7fffffff, 2);
	}
	catch (Cmyexception& e)
	{
		e.ErrorProc();
	}
	return 0;
}