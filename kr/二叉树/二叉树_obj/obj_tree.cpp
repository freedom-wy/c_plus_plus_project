#include "obj_tree.h"

void Objtree::Init()
{
	this->m_Proot = NULL;
}

Objtree::Objtree()
{
	this->Init();
}

Objtree::Objtree(const Objtree& obj)
{
	this->Init();
}

Objtree& Objtree::operator=(const Objtree& obj)
{
	return *this;
}

Objtree::~Objtree()
{
}

// 向二叉树插入节点
void Objtree::Insert(Person* obj)
{
	Node* pNewNode = new Node(obj);
	if (this->m_Proot == NULL)
	{
		this->m_Proot = pNewNode;
		return;
	}

	Node* pNode = this->m_Proot;
	while (true)
	{
		if (obj->index < pNode->p->index)
		{
			if (pNode->m_pLeft == NULL)
			{
				pNode->m_pLeft = pNewNode;
				pNewNode->m_pParent = pNode;
				return;
			}
			pNode = pNode->m_pLeft;
		}
		else if (obj->index > pNode->p->index)
		{
			if (pNode->m_pRight == NULL)
			{
				pNode->m_pRight = pNewNode;
				pNewNode->m_pParent = pNode;
				return;
			}
			pNode = pNode->m_pRight;
		}
		else
		{
			delete pNewNode;
			pNewNode = NULL;
			return;
		}
	}

}
