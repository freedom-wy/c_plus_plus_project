#include <iostream>
using namespace std;


class CFoo
{
private:
	int m_n;
public:
	CFoo(int val)
	{
		cout << "CFoo有参构造" << endl;
		this->m_n = val;
	}
	~CFoo()
	{
		cout << "CFoo析构" << endl;
	}
	void SetVal(int val)
	{
		this->m_n = val;
	}

	int GetVal()
	{
		return this->m_n;
	}
};

class ManagerPtr
{
private:
	CFoo* ptr;
public:
	ManagerPtr(CFoo* ptr)
	{
		this->ptr = ptr;
	}
	~ManagerPtr()
	{
		if (ptr != NULL)
		{
			delete this->ptr;
			this->ptr = NULL;
		}
	}

	CFoo* operator->()
	{
		return this->ptr;
	}
};

int main()
{
	// CFoo* cf1 = new CFoo(1);
	ManagerPtr m1(new CFoo(1));
	cout << m1->GetVal() << endl;
	
	/*CFoo* cf2 = new CFoo(2);
	ManagerPtr m2(cf2);*/

	cout << "hello world" << endl;
	return 0;
}