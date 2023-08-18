#include <iostream>
using namespace std;


class Person
{
public:
	int age;
public:
	Person()
	{
		this->age = 0;
	}
	Person(int val)
	{
		this->age = val;
	}
	Person(const Person & obj)
	{
		this->age = obj.age;
	}
	Person& operator=(const Person & obj)
	{
		this->age = obj.age;
		return *this;
	}
	~Person()
	{
		this->age = 0;
	}
};

class Node
{
public:
	Person m_data;
	Node* m_pPre;
	Node* m_pNext;
public:
	Node()
	{
		cout << "Node无参构造" << endl;
		this->m_data = Person(); // 850 6d4
		this->m_pPre = NULL;
		this->m_pNext = NULL;
	}

	Node(const Person& obj)
	{
		cout << "Node有参构造" << endl;
		this->m_data = obj;
		this->m_pPre = NULL;
		this->m_pNext = NULL;
	}

	Node(const Node& obj)
	{
		this->m_data = obj.m_data;
		this->m_pPre = obj.m_pPre;
		this->m_pNext = obj.m_pNext;
	}

	Node& operator=(const Node& obj)
	{
		this->m_data = obj.m_data;
		this->m_pPre = obj.m_pPre;
		this->m_pNext = obj.m_pNext;
		return *this;
	}

	~Node()
	{
		cout << "Node析构" << endl;
		this->m_data = NULL;
		this->m_pPre = NULL;
		this->m_pNext = NULL;
	}
};

//class Clist
//{
//private:
//	int m_nSize;
//	Node* m_pHead;
//	Node* m_pTail;
//public:
//	Clist()
//	{
//		cout << "链表无参初始化" << endl;
//		this->m_nSize = 0;
//		this->m_pHead = new Node(); // 头部哨兵
//		this->m_pTail = new Node(); // 尾部哨兵
//		this->m_pHead->m_pNext = this->m_pTail;
//		this->m_pTail->m_pPre = this->m_pHead;
//	}
//	//Clist(const Clist& obj)
//	//{
//	//	cout << "链表拷贝构造" << endl;
//	//	this->m_nSize = 0;
//	//	delete this->m_pHead;
//	//	this->m_pHead = NULL;
//	//	delete this->m_pTail;
//	//	this->m_pTail = NULL;
//
//	//	this->m_pHead = new Node(); // 头部哨兵
//	//	this->m_pTail = new Node(); // 尾部哨兵
//	//	this->m_pHead->m_pNext = this->m_pTail;
//	//	this->m_pTail->m_pPre = this->m_pHead;
//	//}
//
//	void PushBack(int val)
//	{
//		this->Insert(this->m_pTail, val);
//	}
//
//	void Insert(Node* pNode, int val)
//	{
//		// 向指定节点前面插入数据
//		Node* pNewNode = new Node(val);
//		// 获取指定节点的前一个节点
//		Node* pPreNode = pNode->m_pPre;
//
//		pPreNode->m_pNext = pNewNode;
//		pNewNode->m_pPre = pPreNode;
//		pNewNode->m_pNext = pNode;
//		pNode->m_pPre = pNewNode;
//
//		this->m_nSize++;
//	}
//
//	void Delete(Node* pNode)
//	{
//		// 删除
//		// 获取当前节点的前置节点和后置节点, 需判断传进来的节点是否为哨兵节点
//		if (pNode == NULL || pNode == this->m_pHead || pNode == this->m_pTail)
//		{
//			return;
//		}
//
//		Node* pPreNode = pNode->m_pPre;
//		Node* pNextNode = pNode->m_pNext;
//
//		// 将前后两个节点连起来
//		pPreNode->m_pNext = pNextNode;
//		pNextNode->m_pPre = pPreNode;
//
//		// 删除节点
//		delete pNode;
//		pNode = NULL;
//
//		this->m_nSize--;
//	}
//
//	void PopBack()
//	{
//		this->Delete(this->m_pTail->m_pPre);
//	}
//
//	~Clist()
//	{
//		cout << "链表的析构" << endl;
//		while (this->m_nSize != 0)
//		{
//			this->PopBack();
//		}
//		if (this->m_pHead != NULL)
//		{
//			delete this->m_pHead;
//			this->m_pHead = NULL;
//		}
//		if (this->m_pTail != NULL)
//		{
//			delete this->m_pTail;
//			this->m_pTail = NULL;
//		}
//	}
//};



class ClistPerson
{
private:
	int m_nSize;
	Node* m_pHead;
	Node* m_pTail;
public:
	ClistPerson()
	{
		cout << "链表无参初始化" << endl;
		this->m_nSize = 0;
		this->m_pHead = new Node(); // 头部哨兵
		this->m_pTail = new Node(); // 尾部哨兵
		this->m_pHead->m_pNext = this->m_pTail;
		this->m_pTail->m_pPre = this->m_pHead;
	}
	//Clist(const Clist& obj)
	//{
	//	cout << "链表拷贝构造" << endl;
	//	this->m_nSize = 0;
	//	delete this->m_pHead;
	//	this->m_pHead = NULL;
	//	delete this->m_pTail;
	//	this->m_pTail = NULL;

	//	this->m_pHead = new Node(); // 头部哨兵
	//	this->m_pTail = new Node(); // 尾部哨兵
	//	this->m_pHead->m_pNext = this->m_pTail;
	//	this->m_pTail->m_pPre = this->m_pHead;
	//}

	void PushBack(const Person& obj)
	{
		this->Insert(this->m_pTail, obj);
	}

	void Insert(Node* pNode, const Person& obj)
	{
		// 向指定节点前面插入数据
		Node* pNewNode = new Node(obj);
		// 获取指定节点的前一个节点
		Node* pPreNode = pNode->m_pPre;

		pPreNode->m_pNext = pNewNode;
		pNewNode->m_pPre = pPreNode;
		pNewNode->m_pNext = pNode;
		pNode->m_pPre = pNewNode;

		this->m_nSize++;
	}

	void Delete(Node* pNode)
	{
		// 删除
		// 获取当前节点的前置节点和后置节点, 需判断传进来的节点是否为哨兵节点
		if (pNode == NULL || pNode == this->m_pHead || pNode == this->m_pTail)
		{
			return;
		}

		Node* pPreNode = pNode->m_pPre;
		Node* pNextNode = pNode->m_pNext;

		// 将前后两个节点连起来
		pPreNode->m_pNext = pNextNode;
		pNextNode->m_pPre = pPreNode;

		// 删除节点
		delete pNode;
		pNode = NULL;

		this->m_nSize--;
	}

	void PopBack()
	{
		this->Delete(this->m_pTail->m_pPre);
	}

	~ClistPerson()
	{
		cout << "链表的析构" << endl;
		while (this->m_nSize != 0)
		{
			this->PopBack();
		}
		if (this->m_pHead != NULL)
		{
			delete this->m_pHead;
			this->m_pHead = NULL;
		}
		if (this->m_pTail != NULL)
		{
			delete this->m_pTail;
			this->m_pTail = NULL;
		}
	}
};


int main()
{
	Person p1;
	ClistPerson c1;
	c1.PushBack(p1);
	cout << "hello world" << endl;
	return 0;
}