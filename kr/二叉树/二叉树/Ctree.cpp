#include "Ctree.h"
void Ctree::Init()
{
	this->m_Proot = NULL;
	this->m_Size = 0;
}

Ctree::Ctree()
{
	this->Init();
}

Ctree::Ctree(const Ctree& obj)
{
	this->Init();
}

Ctree& Ctree::operator=(const Ctree& obj)
{
	return *this;
}

Ctree::~Ctree()
{
}

void Ctree::Insert(int data)
{
	Node* pNewNode = new Node(data);
	if (this->m_Proot == NULL)
	{
		// 无节点
		this->m_Proot = pNewNode;
		this->m_Size++;
		return;
	}

	Node* pNode = this->m_Proot; // 将根节点先赋值给临时节点
	while (true)
	{
		// 判断值大小
		if (data < pNode->m_data)
		{
			// 左侧
			if (pNode->m_pLeft == NULL)
			{
				pNode->m_pLeft = pNewNode;
				pNewNode->m_pParent = pNode;
				this->m_Size++;
				return;
			}
			pNode = pNode->m_pLeft; // 接着向叶子寻找
		}
		else if (data > pNode->m_data)
		{
			// 右侧
			if (pNode->m_pRight == NULL)
			{
				pNode->m_pRight = pNewNode;
				pNewNode->m_pParent = pNode;
				this->m_Size++;
				return;
			}
			pNode = pNode->m_pRight; // 接着向叶子寻找
		}
		else
		{
			delete pNewNode;
			pNewNode = NULL;
			return;
		}
		
	}
}

Ctree::Node* Ctree::Find(int data)
{
	Node* pNode = this->m_Proot; // 将根节点先赋值给临时节点
	while (true)
	{
		// 判断值大小
		if (data < pNode->m_data)
		{
			// 左侧
			if (pNode->m_pLeft == NULL)
			{
				break;
			}
			pNode = pNode->m_pLeft; // 接着向叶子寻找
		}
		else if (data > pNode->m_data)
		{
			// 右侧
			if (pNode->m_pRight == NULL)
			{
				break;
			}
			pNode = pNode->m_pRight; // 接着向叶子寻找
		}
		else
		{
			return pNode;
		}

	}
	return NULL;
}
