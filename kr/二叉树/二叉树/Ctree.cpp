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
