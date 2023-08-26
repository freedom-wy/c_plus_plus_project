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
		// �޽ڵ�
		this->m_Proot = pNewNode;
		this->m_Size++;
		return;
	}

	Node* pNode = this->m_Proot; // �����ڵ��ȸ�ֵ����ʱ�ڵ�
	while (true)
	{
		// �ж�ֵ��С
		if (data < pNode->m_data)
		{
			// ���
			if (pNode->m_pLeft == NULL)
			{
				pNode->m_pLeft = pNewNode;
				pNewNode->m_pParent = pNode;
				this->m_Size++;
				return;
			}
			pNode = pNode->m_pLeft; // ������Ҷ��Ѱ��
		}
		else if (data > pNode->m_data)
		{
			// �Ҳ�
			if (pNode->m_pRight == NULL)
			{
				pNode->m_pRight = pNewNode;
				pNewNode->m_pParent = pNode;
				this->m_Size++;
				return;
			}
			pNode = pNode->m_pRight; // ������Ҷ��Ѱ��
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
	Node* pNode = this->m_Proot; // �����ڵ��ȸ�ֵ����ʱ�ڵ�
	while (true)
	{
		// �ж�ֵ��С
		if (data < pNode->m_data)
		{
			// ���
			if (pNode->m_pLeft == NULL)
			{
				break;
			}
			pNode = pNode->m_pLeft; // ������Ҷ��Ѱ��
		}
		else if (data > pNode->m_data)
		{
			// �Ҳ�
			if (pNode->m_pRight == NULL)
			{
				break;
			}
			pNode = pNode->m_pRight; // ������Ҷ��Ѱ��
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

	// ɾ������Ҷ�ӽڵ�
	if (pNodeToDel->m_pLeft == NULL && pNodeToDel->m_pRight == NULL)
	{
		return this->DelLeaf(pNodeToDel);
	}
	// ɾ������֧�ڵ㣬�ڵ����Ƽ���
	if (pNodeToDel->m_pLeft == NULL || pNodeToDel->m_pRight == NULL)
	{
		return this->DelSingleLeaf(pNodeToDel);
	}
	// ɾ��˫��֧�ڵ㣬��������������Ҷ�����ֵ
	return this->DelDoubleLeaf(pNodeToDel);
}

void Ctree::Modiry(int oldVal, int newVal)
{
	// �޸ģ�ɾ����ֵ��������ֵ
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

	// ������
	this->MidNode(pNode->m_pLeft);
	cout << pNode->m_data << " " << endl;
	this->MidNode(pNode->m_pRight);
}

void Ctree::DelLeaf(Node* pNode)
{
	this->m_Size--;
	// �ж������ӻ����Һ���
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
