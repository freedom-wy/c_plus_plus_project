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

// 智能指针
template <class T>
class ManagerPtr
{
private:
	T* ptr;
	int* m_pnRefCount;
public:
	ManagerPtr(T* ptr)
	{
		this->ptr = ptr;
		this->m_pnRefCount = new int(1);
	}
	ManagerPtr(const ManagerPtr& obj)
	{
		cout << "拷贝构造" << endl;
		this->ptr = obj.ptr;
		this->m_pnRefCount = obj.m_pnRefCount;
		++(*this->m_pnRefCount);
	}
	~ManagerPtr()
	{
		--(*this->m_pnRefCount);
		if (*this->m_pnRefCount == 0)
			if (ptr != NULL)
			{
				delete this->ptr;
				this->ptr = NULL;
			}
	}

	T* operator->()
	{
		return this->ptr;
	}
};

void Print(ManagerPtr<CFoo> p)
{
	cout << p->GetVal() << endl;
}

int main()
{
	// CFoo* cf1 = new CFoo(1);
	ManagerPtr<CFoo> m1(new CFoo(1));
	cout << m1->GetVal() << endl;
	Print(m1);
	
	/*CFoo* cf2 = new CFoo(2);
	ManagerPtr m2(cf2);*/

	cout << "hello world" << endl;
	return 0;
}