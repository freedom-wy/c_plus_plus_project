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
		Node* m_pParent; // 父节点
		Node* m_pLeft; // 左节点
		Node* m_pRight; // 右节点
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
	Node* m_Proot; // 根节点
	int m_Size;
private:
	void Init();
public:
	Ctree();
	Ctree(const Ctree& obj);
	Ctree& operator=(const Ctree& obj);
	virtual ~Ctree(); // 析构

	void Insert(int data); // 插入叶子节点
	Node* Find(int data);
	void Delete(int data); // 删除
private:
	void DelLeaf(Node* pNode); // 删除叶子节点
	void DelSingleLeaf(Node* pNode); // 删除单分支
	void DelDoubleLeaf(Node* pNode); // 删除双分支
};
