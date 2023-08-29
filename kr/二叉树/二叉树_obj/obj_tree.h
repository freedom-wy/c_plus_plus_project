#pragma once
#include <iostream>
using namespace std;


class Person
{
private:
	void Init()
	{
		this->age = 0;
		this->name = NULL;
		this->index = 0;
	}
public:
	int age;
	char* name;
	int index; // 编号
public:
	Person()
	{
		this->Init();
	}
	Person(int a, char* n, int i)
	{
		this->Init();
		this->age = a;
		this->name = new char[strlen(n) + 1];
		memset(this->name, 0, strlen(n) + 1);
		strcpy_s(this->name, strlen(n) + 1, n);
		this->index = i;
	}
	Person(const Person& obj)
	{
		this->Init();
		*this = obj;
	}
	Person& operator=(const Person& obj)
	{
		if (this->name != NULL)
		{
			delete[]this->name;
		}

		this->age = obj.age;
		this->name = new char[strlen(obj.name) + 1];
		memset(this->name, 0, strlen(obj.name) + 1);
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
		this->index = obj.index;
		return *this;
	}
	~Person()
	{
		if (this->name != NULL)
		{
			delete[]this->name;
		}
		this->age = 0;
		this->index = 0;
	}
};


// 创建一个对象二叉树
class Objtree
{
private:
	// 二叉树的节点
	class Node
	{
	public:
		Node* m_pParent;
		Node* m_pLeft;
		Node* m_pRight;
		Person* p;
	public:
		Node() :m_pParent(NULL), m_pLeft(NULL), m_pRight(NULL), p(NULL) {};
		Node(Person* temp):m_pParent(NULL), m_pLeft(NULL), m_pRight(NULL), p(temp) {};
		Node(const Node* obj)
		{
			this->m_pParent = NULL;
			this->m_pLeft = NULL;
			this->m_pRight = NULL;
			this->p = NULL;

			this->m_pParent = obj->m_pParent;
			this->m_pLeft = obj->m_pLeft;
			this->m_pRight = obj->m_pRight;
			this->p = obj->p;
		}

		Node& operator=(const Node* obj)
		{
			this->m_pParent = obj->m_pParent;
			this->m_pLeft = obj->m_pLeft;
			this->m_pRight = obj->m_pRight;
			this->p = obj->p;
			return *this;
		}
		~Node()
		{
			this->m_pParent = NULL;
			this->m_pLeft = NULL;
			this->m_pRight = NULL;
			this->p = NULL;
		}
	};
private:
	// 二叉树的根节点
	Node* m_Proot;
private:
	// 初始化二叉树
	void Init();
public:
	Objtree();
	Objtree(const Objtree& obj);
	Objtree& operator=(const Objtree& obj);
	~Objtree();

	void Insert(Person* obj);
};