#include "avl_tree.h"


void AVLTree::Init()
{
	this->m_Proot = NULL;
}

void AVLTree::AdjustHeight(Node* pNewNode)
{
	Node* pFather = pNewNode->m_pParent;
	Node* pChild = pNewNode;

	while (pFather != NULL)
	{
		if (pFather->m_height == pChild->m_height)
		{
			pFather->m_height++;
		}
		pChild = pFather;
		pFather = pFather->m_pParent;
	}
}

// Ä¬ÈÏ¹¹Ôì
AVLTree::AVLTree()
{
	this->Init();
}

void AVLTree::Insert(int data)
{
	Node* pNewNode = new Node(data);
	if (this->m_Proot == NULL)
	{
		this->m_Proot = pNewNode;
		return;
	}
	Node* pNode = this->m_Proot;
	while (true)
	{
		if (data < pNode->m_data)
		{
			if (pNode->m_pLeft == NULL)
			{
				pNode->m_pLeft = pNewNode;
				pNewNode->m_pParent = pNode;
				AdjustHeight(pNewNode);
				return;
			}
			pNode = pNode->m_pLeft;
		}
		else if (data > pNode->m_data)
		{
			if (pNode->m_pRight == NULL)
			{
				pNode->m_pRight = pNewNode;
				pNewNode->m_pParent = pNode;
				AdjustHeight(pNewNode);
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
