#include <iostream>
using namespace std;

template<class T>
class Clist
{
public:
	class Node
	{
	public:
		// 节点属性
		T m_data;
		Node* m_pPre;
		Node* m_pNext;
	public:
		Node()
		{
			this->m_data = {}; // 根据类型初始化
			this->m_pPre = NULL;
			this->m_pNext = NULL;
		}
		Node(T val)
		{
			this->m_data = val;
			this->m_pPre = NULL;
			this->m_pNext = NULL;
		}
	};
private:
	int m_nSize; // 长度
	Node* m_pHead; // 头部
	Node* m_pTail; // 尾部
public:
	void Init()
	{
		// 链表初始化
		this->m_nSize = 0;
		this->m_pHead = new Node(); // 头部哨兵
		this->m_pTail = new Node(); // 尾部哨兵
		this->m_pHead->m_pNext = this->m_pTail;
		this->m_pTail->m_pPre = this->m_pHead;
	}
	Clist()
	{
		cout << "链表无参初始化" << endl;
		this->Init();
	}
	/*Clist(const Node& obj)
	{
		cout << "链表有参初始化" << endl;
	}*/
	void PushHead(const T& val)
	{
		this->Insert(this->m_pHead->m_pNext, val);
	}
	void PushBack(const T& val)
	{
		this->Insert(this->m_pTail, val);
	}
	void Insert(Node* pNode, const T& val)
	{
		// 在指定位置上插入数据, 默认向前插入
		Node* pNewNode = new Node(val);
		// 获取传入节点的前一个节点
		Node* pPreNode = pNode->m_pPre;

		pPreNode->m_pNext = pNewNode;
		pNewNode->m_pPre = pPreNode;
		pNewNode->m_pNext = pNode;
		pNode->m_pPre = pNewNode;

		this->m_nSize++;
	}
};


void test1()
{
	Clist<int>c1;
	c1.PushBack(1);
	c1.PushBack(2);
	c1.PushHead(3);
	c1.PushHead(4);
	cout << "hello world" << endl;
}

int main()
{
	test1();
	return 0;
}