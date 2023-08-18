#include <iostream>
using namespace std;

template<class T>
class Clist
{
public:
	class Node
	{
	public:
		// 节点属性
		T m_data;
		Node* m_pPre;
		Node* m_pNext;
	public:
		Node()
		{
			this->m_data = {}; // 根据类型初始化
			this->m_pPre = NULL;
			this->m_pNext = NULL;
		}
		Node(T val)
		{
			this->m_data = val;
			this->m_pPre = NULL;
			this->m_pNext = NULL;
		}
		/*~Node()
		{
			if(this->m_pPre != NULL || this->m_pNext != NULL)
			{
				delete this->m_pPre;
				delete this->m_pNext;
				this->m_pPre = NULL;
				this->m_pNext = NULL;
			}
			this->m_data = 0;
			
		}*/
	};
private:
	int m_nSize; // 长度
	Node* m_pHead; // 头部
	Node* m_pTail; // 尾部
public:
	void Init()
	{
		// 链表初始化
		this->m_nSize = 0;
		this->m_pHead = new Node(); // 头部哨兵
		this->m_pTail = new Node(); // 尾部哨兵
		this->m_pHead->m_pNext = this->m_pTail;
		this->m_pTail->m_pPre = this->m_pHead;
	}
	Clist()
	{
		cout << "链表无参初始化" << endl;
		this->Init();
	}
	Clist(const Clist& obj)
	{
		//this->Clear(); // 拷贝构造不能使用清空方法,需先构造出链表的两个哨兵节点
		this->Init();
		// 拷贝构造
		//*this=obj; // 直接调用等号运算符重载
		Node* pNode = obj.m_pHead->m_pNext;
		while (pNode != obj.m_pTail)
		{
			this->PushBack(pNode->m_data);
			pNode = pNode->m_pNext;
		}
	}
	Clist& operator=(const Clist& obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		Node* pNode = obj.m_pHead->m_pNext;
		while (pNode != obj.m_pTail)
		{
			this->PushBack(pNode->m_data);
			pNode = pNode->m_pNext;
		}
		this->Clear(); // 清空自己

		return *this;
	}
	/*Clist(const Node& obj)
	{
		cout << "链表有参初始化" << endl;
	}*/
	~Clist()
	{
		this->Clear();
		if (this->m_pHead != NULL)
		{
			delete this->m_pHead;
			this->m_pHead = NULL;
		}
		if(this->m_pTail!=NULL)
		{
			delete this->m_pTail;
			this->m_pTail = NULL;
		}
	}
	void PushHead(const T& val)
	{
		this->Insert(this->m_pHead->m_pNext, val);
	}
	void PushBack(const T& val)
	{
		this->Insert(this->m_pTail, val);
	}
	void Insert(Node* pNode, const T& val)
	{
		// 在指定位置上插入数据, 默认向前插入
		Node* pNewNode = new Node(val);
		// 获取传入节点的前一个节点
		Node* pPreNode = pNode->m_pPre;

		pPreNode->m_pNext = pNewNode;
		pNewNode->m_pPre = pPreNode;
		pNewNode->m_pNext = pNode;
		pNode->m_pPre = pNewNode;

		this->m_nSize++;
	}

	Node* Find(const T& val)
	{
		// 查找
		// 假设要查找的节点为头哨兵节点的下一个节点
		Node* pNode = this->m_pHead->m_pNext;
		while (pNode != this->m_pTail)
		{
			if (pNode->m_data == val)
			{
				return pNode;
			}
			pNode = pNode->m_pNext;
		}
		return NULL;
	}

	void Delete(Node* pNode)
	{
		// 删除
		// 获取当前节点的前置节点和后置节点, 需判断传进来的节点是否为哨兵节点
		if (pNode == NULL || pNode == this->m_pHead || pNode == this->m_pTail)
		{
			return;
		}

		Node* pPreNode = pNode->m_pPre;
		Node* pNextNode = pNode->m_pNext;

		// 将前后两个节点连起来
		pPreNode->m_pNext = pNextNode;
		pNextNode->m_pPre = pPreNode;

		// 删除节点
		delete pNode;
		pNode = NULL;

		this->m_nSize--;
	}

	void PopHead()
	{
		this->Delete(this->m_pHead->m_pNext); // 删除头部哨兵的下一个节点
	}

	void PopBack()
	{
		this->Delete(this->m_pTail->m_pPre);
	}

	void Modify(Node* pNode, const T& val)
	{
		// 修改
		if (pNode == NULL || pNode == this->m_pHead || pNode == this->m_pTail)
		{
			return;
		}
		pNode->m_data = val;
	}

	void Clear()
	{
		while (this->GetSize() != 0)
		{
			this->PopBack();
		}
	}

	int GetSize()
	{
		return this->m_nSize;
	}
};

void test1()
{
	Clist<int>c1;
	c1.PushBack(1);
	c1.PushBack(2);
	c1.PushHead(3);
	c1.PushHead(4);
	Clist<int>::Node* n1 = c1.Find(3);
	c1.Insert(n1, 5); // 4 5 3 1 2
	Clist<int>::Node* n2 = c1.Find(6);

	/*Clist<int>c2 = c1;
	Clist<int>c3;
	c3 = c1;*/
	
	/*c1.PopHead();
	c1.Delete(n1);
	c1.Delete(n2);
	c1.PopBack();
	c1.PopHead();
	c1.PopBack();

	c1.PopBack();*/
	cout << "hello world" << endl;
}

class Person
{
private:
	int* age;
	char* name;
public:
	Person() 
	{ 
		this->age = new int(0); 
		this->name = new char[64];
	};
	Person(int age, char* name)
	{
		if (this->age != NULL)
		{
			delete this->age;
			this->age = NULL;
		}
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
		this->age = new int(age);
		this->name = new char[64];
		memset(this->name, 0, 64);
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	Person(const Person& obj)
	{
		if (this->age != NULL)
		{
			delete this->age;
			this->age = NULL;
		}
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
		this->age = new int(*(obj.age));
		this->name = new char[64];
		memset(this->name, 0, 64);
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	}
	Person& operator=(const Person& obj)
	{
		if (this->age != NULL)
		{
			delete this->age;
			this->age = NULL;
		}
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
		this->age = new int(*(obj.age));
		this->name = new char[64];
		memset(this->name, 0, 64);
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);

		return *this;
	}
	~Person()
	{
		if (this->age != NULL)
		{
			delete this->age;
			this->age = NULL;
		}
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
	}
};

class Person2
{
private:
	int* age;
public:
	Person2()
	{
		this->age = new int(0);
	}
	Person2(int val)
	{
		this->age = new int(val);
	}
	Person2(const Person2& obj)
	{
		if (this->age != NULL)
		{
			delete this->age;
		}
		this->age = new int(*(obj.age));
	}
	Person2& operator=(const Person2& obj)
	{
		if (this->age != NULL)
		{
			delete this->age;
		}
		this->age = new int(*(obj.age));
		return *this;
	}
	~Person2()
	{
		delete this->age;
	}
};

void test2()
{
	/*char name[64] = "hello";
	Person p1(1, name);
	Person p2(2, name);
	Person p3(3, name);*/
	/*Person p2 = p1;
	Person p3;
	p3 = p2;*/
	Person2 p1(1);
	/*Person2 p2(2);
	Person2 p3(3);*/
	Clist<Person2>c1;
	c1.PushBack(p1);
	/*c1.PushBack(p2);
	c1.PushBack(p3);*/
	cout << "hello world" << endl;
}

void test3()
{
	int arr1[2]; //可以指定数组大小，后续再进行赋值
	for (int i = 0; i < 2; i++)
	{
		arr1[i] = i;
	}

	for (int i = 0; i < 2; i++)
	{
		cout << arr1[i] << endl;
	}
	int arr2[] = { 1, 2,3 }; // 也可以不指定大小，直接初始化赋值

	// 在堆上也是一样
	int* p1 = new int[] {1, 2}; //在堆上初始化1和2
	int* p2 = new int[2];
	for (int i = 0; i < 2; i++)
	{
		p2[i] = i; // 在堆上初始化0和1
	}
	delete[]p1;
	delete[]p2;

	Person2 arr3[] = { 1, 2 }; // 走两次有参构造
	Person2 arr4[2]; //走两次默认构造，通过索引更新后删除了原默认构造数据，放入新的数据
	Person2 test1(1);
	Person2 test2(2);
	arr4[0] = test1; //等号运算符重载
	arr4[1] = test2; //等号运算符重载

	Person2* arr5 = new Person2[2];
	Person2* arr6 = new Person2[]{5, 6};
	arr5[0] = test1;
	arr5[1] = test2;
	delete[]arr5;
	delete[]arr6;


	/*Person2 p1(1);
	Person2 p2(2);
	Person2 p3[2] = {3, 4};*/
	/*int* p = new int[2]{1, 2};
	Person2* p2 = new Person2[2]{ 3, 4 };
	delete[]p2;*/
	cout << "hello world" << endl;
}



int main()
{
	// test1();
	// test3();
	return 0;
}