#include <iostream>
using namespace std;

class CInteger
{
private:
	int m_n;
public:
	CInteger()
	{
		cout << "Ĭ���޲ι��췽��" << endl;
	}
	CInteger(int val)
	{
		cout << "�вι��췽��" << endl;
		this->m_n = val;
	}
	CInteger(CInteger& obj)
	{
		cout << "��������" << endl;
		this->m_n = obj.m_n;
	}
	void SetVal(int n)
	{
		this->m_n = n;
	}
	int GetVal()
	{
		return this->m_n;
	}
	CInteger& operator=(int n)
	{
		this->m_n = n;
		return *this;
	}
	CInteger& operator=(CInteger& obj)
	{
		this->m_n = obj.m_n;
		return *this;
	}
	CInteger operator+(int n)
	{
		CInteger temp(this->m_n + n);
		return temp;
	}
	CInteger operator+(CInteger& obj)
	{
		CInteger temp(this->m_n + obj.m_n);
		return temp;
	}
	int operator+=(int n)
	{
		this->m_n += n;
		return this->m_n;
	}
	friend CInteger operator+(int n, CInteger& obj);
};

CInteger operator+(int n, CInteger& obj)
{
	CInteger temp(n + obj.m_n);
	return temp;
}



int main()
{
	//CInteger n;
	///*n.SetVal(10);
	//n = 89;
	//n + 10;
	//n += 3;*/
	//CInteger n1;
	//n1.SetVal(10);
	//// CInteger n2;
	//// n = n1 = n2 = 100;
	//(n = 1) = 2;
	//n = n1; // �Ⱥ����������
	//CInteger n4 = n; // ��������
	//// �������ڴ�Ŀ���ȡ��ַ�Ľ�����ֵ
	/*CInteger n1(10);
	CInteger n2(20);
	n1 + 2 + n2 + 1;
	1 + n1;*/

	int n = 1;
	cout << ++n << endl; // ����������
	cout << n << endl;
	int n1 = 1;
	cout << n1++ << endl; // �����������
	cout << n1 << endl;
	cout << "hello world" << endl;
	return 0;
}