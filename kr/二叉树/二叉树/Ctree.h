#pragma once
#include <iostream>
using namespace std;

// https://www.cs.usfca.edu/~galles/visualization/BST.html

class Ctree
{
private:
	class Node
	{
	public:
		Node* m_pParent; // ���ڵ�
		Node* m_pLeft; // ��ڵ�
		Node* m_pRight; // �ҽڵ�
		int m_data;
		Node() :m_pParent(NULL), m_pLeft(NULL), m_pRight(NULL), m_data() {};
		Node(int data) :m_data(data), m_pParent(NULL), m_pLeft(NULL), m_pRight(NULL) {};
		Node(const Node& obj)
		{
			m_data = obj.m_data;
			m_pParent = obj.m_pParent;
			m_pLeft = obj.m_pLeft;
			m_pRight = obj.m_pRight;
		}
		Node& operator=(const Node& obj)
		{
			m_data = obj.m_data;
			m_pParent = obj.m_pParent;
			m_pLeft = obj.m_pLeft;
			m_pRight = obj.m_pRight;
			return *this;
		}
		~Node()
		{
			m_pParent = NULL;
			m_pLeft = NULL;
			m_pRight = NULL;
		}
	};
private:
	Node* m_Proot; // ���ڵ�
	int m_Size;
private:
	void Init();
public:
	Ctree();
	Ctree(const Ctree& obj);
	Ctree& operator=(const Ctree& obj);
	virtual ~Ctree(); // ����

	void Insert(int data); // ����Ҷ�ӽڵ�
	Node* Find(int data);
	void Delete(int data); // ɾ��
private:
	void DelLeaf(Node* pNode); // ɾ��Ҷ�ӽڵ�
	void DelSingleLeaf(Node* pNode); // ɾ������֧
	void DelDoubleLeaf(Node* pNode); // ɾ��˫��֧
};
