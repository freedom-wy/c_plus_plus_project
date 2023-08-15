#include <iostream>
using namespace std;

struct NODE;
typedef NODE* PNODE;

template<class T>
class Clist
{
public:
	// 定义节点
	struct NODE
	{
		T m_val; // 数据
		PNODE m_pPre; // 前驱结点指针
		PNODE m_pNext; // 后继节点指针
	};
public:
	Clist();
	Clist(const Clist& obj);
	Clist& operator=(const Clist& obj);
	~Clist();

	// 成员方法
	void PushBack(const T& val);
	void PushHead(const T& val);
	void Insert(PNODE pNode, const T& val);
	void PopHead();
	void PopBack();
	void Delete(PNODE pNode); // 删除指定位置的元素
	void Modify(PNODE pNode, const T& obj); //修改
	PNODE Find(const T& obj); // 查找
	void Clear();
	int GetSize();
	bool IsEmpty();

private:
	void Reset();

private:
	PNODE m_pHead; // 头结点指针
	PNODE m_pTail; // 尾节点指针
	int m_nSize; // 节点个数
};

template<class T>
Clist<T>::Clist()
{
	cout << "默认构造" << endl;
}

template<class T>
Clist<T>::Clist(const Clist& obj)
{
	cout << "拷贝构造" << endl;
}

template<class T>
Clist<T>& Clist<T>::operator=(const Clist& obj)
{
	cout << "重载等号运算符" << endl;
	return *this;
}

template<class T>
Clist<T>::~Clist()
{
	this->Reset();
	cout << "析构" << endl;
}

template<class T>
void Clist<T>::PushBack(const T& val)
{
}

template<class T>
void Clist<T>::PushHead(const T& val)
{
}

template<class T>
void Clist<T>::Insert(PNODE pNode, const T& val)
{
	if (pNode == NULL)
	{
		return;
	}
}

template<class T>
void Clist<T>::PopHead()
{
}

template<class T>
void Clist<T>::PopBack()
{
}

template<class T>
void Clist<T>::Delete(PNODE pNode)
{
}

template<class T>
void Clist<T>::Modify(PNODE pNode, const T& obj)
{
}

template<class T>
PNODE Clist<T>::Find(const T& obj)
{
	return nullptr;
}

template<class T>
void Clist<T>::Clear()
{
}

template<class T>
int Clist<T>::GetSize()
{
	return 0;
}

template<class T>
bool Clist<T>::IsEmpty()
{
	return false;
}

template<class T>
void Clist<T>::Reset()
{
	this->m_pHead = NULL;
	this->m_pTail = NULL;
	this->m_nSize = 0;
}


int main()
{
	return 0;
}
