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

void Ctree::Delete(int data)
{
	Node* pNodeToDel = this->Find(data);
	if (pNodeToDel == NULL)
	{
		return;
	}

	// 删除单独叶子节点
	if (pNodeToDel->m_pLeft == NULL && pNodeToDel->m_pRight == NULL)
	{
		return this->DelLeaf(pNodeToDel);
	}
	// 删除单分支节点，节点上移即可
	if (pNodeToDel->m_pLeft == NULL || pNodeToDel->m_pRight == NULL)
	{
		return this->DelSingleLeaf(pNodeToDel);
	}
	// 删除双分支节点，在左子树中找右叶子最大值
	return this->DelDoubleLeaf(pNodeToDel);
}

void Ctree::Modiry(int oldVal, int newVal)
{
	// 修改，删除旧值，插入新值
	Node* pFindNode = this->Find(oldVal);
	if (pFindNode != NULL)
	{
		this->Delete(oldVal);
		this->Insert(newVal);
	}
}

void Ctree::Mid()
{
	this->MidNode(this->m_Proot);
}

void Ctree::MidNode(Node* pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	// 先左孩子
	this->MidNode(pNode->m_pLeft);
	cout << pNode->m_data << " " << endl;
	this->MidNode(pNode->m_pRight);
}

void Ctree::DelLeaf(Node* pNode)
{
	this->m_Size--;
	// 判断是左孩子还是右孩子
	Node* pFatherNode = pNode->m_pParent;
	if (pFatherNode->m_pLeft == pNode)
	{
		pFatherNode->m_pLeft = NULL;
	}
	else if (pFatherNode->m_pRight == pNode)
	{
		pFatherNode->m_pRight = NULL;
	}

	delete pNode;
	pNode = NULL;
	return;
}

void Ctree::DelSingleLeaf(Node* pNode)
{
	this->m_Size--;
	
	Node* pChildNode = pNode->m_pLeft;
	if (pChildNode != NULL)
	{
		pNode->m_pLeft = NULL;
	}
	else
	{
		pChildNode = pNode->m_pRight;
		pNode->m_pRight = NULL;
	}

	if (pNode == this->m_Proot)
	{
		pChildNode->m_pParent = NULL;
		this->m_Proot = pChildNode;
		return;
	}

	pNode->m_data = pChildNode->m_data;
	pChildNode->m_pParent = NULL;
	delete pChildNode;
	return;
}

void Ctree::DelDoubleLeaf(Node* pNode)
{
	Node* pMaxNode = pNode->m_pLeft;
	while (pMaxNode->m_pRight != NULL)
	{
		pMaxNode = pMaxNode->m_pRight;
	}

	pNode->m_data = pMaxNode->m_data;

	if (pMaxNode->m_pLeft != NULL)
	{
		this->DelSingleLeaf(pMaxNode);
	}
	else
	{
		this->DelLeaf(pMaxNode);
	}
	
}
