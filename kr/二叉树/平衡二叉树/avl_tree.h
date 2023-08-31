#pragma once
#include <iostream>
using namespace std;


//https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

class AVLTree
{
private:
	class Node
	{
	public:
		Node* m_pParent;
		Node* m_pLeft;
		Node* m_pRight;
		int m_data;
		int m_height; // 节点高度
	public:
		Node() :m_pParent(NULL), m_pLeft(NULL), m_pRight(NULL), m_data(), m_height(1) {};
		Node(int data):m_pParent(NULL), m_pLeft(NULL), m_pRight(NULL), m_data(data), m_height(1) {};
		Node(const Node& obj)
		{
			*this = obj;
		}

		Node& operator=(const Node& obj)
		{
			this->m_pParent = obj.m_pParent;
			this->m_pLeft = obj.m_pLeft;
			this->m_pRight = obj.m_pRight;
			this->m_data = obj.m_data;
			this->m_height = obj.m_height;
			return *this;
		}
		~Node()
		{
			this->m_pParent = NULL;
			this->m_pLeft = NULL;
			this->m_pRight = NULL;
		}
	};
private:
	Node* m_Proot;
private:
	void Init();
	void AdjustHeight(Node* pNewNode); // 调整高度
	void RightRotate(Node* pF); //右旋
	int CalcHeight(Node* pNode);
	int GetHeight(Node* pNode);
public:
	AVLTree();
public:
	void Insert(int data);
};
