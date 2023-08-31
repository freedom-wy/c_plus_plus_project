#include "avl_tree.h"


void AVLTree::Init()
{
	this->m_Proot = NULL;
}

// 调整高度 
void AVLTree::AdjustHeight(Node* pNewNode)
{
	Node* pFather = pNewNode->m_pParent; // 8
	Node* pChild = pNewNode; // 7

	while (pFather != NULL)
	{
		if (GetHeight(pFather) == GetHeight(pChild)) // 1
		{
			pFather->m_height++; // 8->2
			if (pFather == this->m_Proot)
			{
				break;
			}
			pChild = pFather; // 8
			pFather = pFather->m_pParent; // 9
			// 右旋
			if (GetHeight(pFather->m_pLeft) - GetHeight(pFather->m_pRight) > 1) // 2-0
			{
				this->RightRotate(pFather); // 9
			}
			else if (GetHeight(pFather->m_pRight) - GetHeight(pFather->m_pLeft) > 1) // 左旋
			{

			}
		}
		else
		{
			break;
		}
	}
}

// 右旋
void AVLTree::RightRotate(Node* pF)
{
	Node* pFF = pF->m_pParent; // NULL
	Node* pL = pF->m_pLeft; // 8
	Node* pC2 = pL->m_pRight; // NULL

	// 旋转
	pL->m_pParent = pFF;
	pL->m_pRight = pF; // 7-8-9

	if (pFF != NULL)
	{
		if (pFF->m_pLeft == pF)
		{
			pFF->m_pLeft = pL;
		}
		else if (pFF->m_pRight == pF)
		{
			pFF->m_pRight = pL;
		}
	}
	else
	{
		this->m_Proot = pL;
	}
	
	if (pC2 != NULL)
	{
		pC2->m_pParent = pF;
	}
	
	pF->m_pLeft = pC2;
	pF->m_pParent = pL;

	// 调整高度
	pF->m_height = this->CalcHeight(pF);
	pL->m_height = this->CalcHeight(pL);

}

int AVLTree::CalcHeight(Node* pNode)
{
	if (pNode->m_pLeft == NULL && pNode->m_pRight == NULL)
	{
		return 1;
	}
	if (GetHeight(pNode->m_pLeft) > GetHeight(pNode->m_pRight))
	{
		return pNode->m_pLeft->m_height + 1;
	}
	else
	{
		return pNode->m_pRight->m_height + 1;
	}

	return 0;
}

int AVLTree::GetHeight(Node* pNode)
{
	if (pNode == NULL)
	{
		return 0;
	}
	else
	{
		return pNode->m_height;
	}
	
}

// 默认构造
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
