﻿#include <iostream>
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
		/*~Node()
		{
			if(this->m_pPre != NULL || this->m_pNext != NULL)
			{
				delete this->m_pPre;
				delete this->m_pNext;
				this->m_pPre = NULL;
				this->m_pNext = NULL;
			}
			this->m_data = 0;
			
		}*/
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
	~Clist()
	{
		delete this->m_pHead;
		delete this->m_pTail;
		this->m_nSize = 0;
		this->m_pHead = NULL;
		this->m_pTail = NULL;
	}
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

	Node* Find(const T& val)
	{
		// 查找
		// 假设要查找的节点为头哨兵节点的下一个节点
		Node* pNode = this->m_pHead->m_pNext;
		while (pNode != this->m_pTail)
		{
			if (pNode->m_data == val)
			{
				return pNode;
			}
			pNode = pNode->m_pNext;
		}
		return NULL;
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

	void PopHead()
	{
		this->Delete(this->m_pHead->m_pNext); // 删除头部哨兵的下一个节点
	}

	void PopBack()
	{
		this->Delete(this->m_pTail->m_pPre);
	}
};


void test1()
{
	Clist<int>c1;
	c1.PushBack(1);
	c1.PushBack(2);
	c1.PushHead(3);
	c1.PushHead(4);
	Clist<int>::Node* n1 = c1.Find(3);
	c1.Insert(n1, 5); // 4 5 3 1 2
	Clist<int>::Node* n2 = c1.Find(6);
	
	c1.PopHead();
	c1.Delete(n1);
	c1.Delete(n2);
	c1.PopBack();
	c1.PopHead();
	c1.PopBack();

	c1.PopBack();
	cout << "hello world" << endl;
}

int main()
{
	test1();
	return 0;
}