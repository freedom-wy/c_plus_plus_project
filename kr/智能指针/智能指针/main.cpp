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
	//int* m_pnRefCount;
public:
	ManagerPtr(T* ptr)
	{
		if (ptr == NULL)
		{
			return;
		}
		this->ptr = ptr;
		//this->m_pnRefCount = new int(1);
	}
	ManagerPtr(const ManagerPtr& obj)
	{
		cout << "拷贝构造" << endl;
		this->ptr = new T(obj.ptr->GetVal());
		//this->ptr = obj.ptr;
		/*this->m_pnRefCount = obj.m_pnRefCount;
		++(*this->m_pnRefCount);*/
	}
	~ManagerPtr()
	{
		/*--(*this->m_pnRefCount);
		if (*this->m_pnRefCount == 0)
			if (ptr != NULL)
			{
				delete this->ptr;
				this->ptr = NULL;
			}*/
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

void Print(ManagerPtr<CFoo>& p) // 如果不写&则需要走拷贝构造
{
	cout << p->GetVal() << endl;
}

int main()
{
	CFoo* cf1 = new CFoo(1);
	ManagerPtr<CFoo> m1(cf1);
	cout << m1->GetVal() << endl;
	Print(m1);

	////ManagerPtr<void>m2(NULL);

	//int n [2] = { 1, 2 };
	//CFoo cf1[2] = { 1, 2 }; // 类数组构造

	cout << "hello world" << endl;
	return 0;
}