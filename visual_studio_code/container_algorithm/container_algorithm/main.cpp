#include <vector>
#include <deque>
#include <list>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

void PrintVectorFunction(int val)
{
	// ��ͨ����
	cout << val << endl;
}

class PrintVectorClass {
	// ��������
public:
	// ��дС����
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test1()
{
	// ����vector����
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), PrintVectorFunction);
	cout << "==========" << endl;
	for_each(v1.begin(), v1.end(), PrintVectorClass());
	
}

class Person
{
public:
	string name;
	int age;
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	// ����==����find�ײ������ԶԱ�Person�Զ�����������
	bool operator==(const Person& p)
	{
		if (this->name == p.name && this->age == p.age)
		{
			return true;
		}
		else {
			return false;
		}
	}
};

void test2()
{
	// ����deque�����е�Ԫ��
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	
	deque<int>::iterator it1 = (find(d1.begin(), d1.end(), 5));
	if (it1 == d1.end())
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}
	else
	{
		cout << "�ҵ�Ԫ��5" << endl;
	}

	Person p1("����", 1);
	Person p2("����", 2);
	Person p3("����", 3);

	deque<Person> d2;
	d2.push_front(p1);
	d2.push_front(p2);
	d2.push_front(p3);

	deque<Person>::iterator it2 = find(d2.begin(), d2.end(), p2);
	if (it2 == d2.end())
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}
	else
	{
		cout << "�ҵ�Ԫ��, " << "����: " << it2->name << endl;
	}
}

class FindFive
	// ����bool���͵ķº���
{
public:
	bool operator()(int val)
	{
		return val == 5;
	}
};

class FindAge20
{
public:
	bool operator()(Person& p)
	{
		return p.age == 20;
	}
};

void test3()
{
	list<int> l1;
	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i);
	}

	list<int>::iterator it1 = find_if(l1.begin(), l1.end(), FindFive());
	if (it1 == l1.end())
	{
		cout << "δ�ҵ�Ԫ��5" << endl;
	}
	else {
		cout << "�ҵ�Ԫ��5" << endl;
	}

	list<Person>l2;
	Person p1("����", 30);
	Person p2("����", 10);
	Person p3("����", 20);
	l2.push_front(p1);
	l2.push_front(p2);
	l2.push_front(p3);

	list<Person>::iterator it2 = find_if(l2.begin(), l2.end(), FindAge20());
	if (it2 == l2.end())
	{
		cout << "δ�ҵ�����Ϊ20�����" << endl;
	}
	else {
		cout << "����Ϊ: " << it2->name << ", ����Ϊ: " << it2->age << endl;
	}

}

class Animal
{
public:
	string name;
	string color;
	int height;
	Animal(string name, string color, int height)
	{
		this->name = name;
		this->color = color;
		this->height = height;
	}

	bool operator==(const Animal& a)
	{
		if (this->name == a.name && this->color == a.color && this->height == a.height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//class CompareAnimal
//{
//public:
//	bool operator()(const Animal& a1, const Animal& a2)const
//	{
//		return a1.height < a2.height;
//	}
//};

//void PrintSet(set<Animal, CompareAnimal>& s)
//{
//	for (set<Animal, CompareAnimal>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << "����: " << it->name << ", ��ɫ: " << it->color << ", ���: " << it->height << endl;
//	}
//}

void test4()
{
	// set������Զ�����������ʱ, ��Ҫָ���������
	// ͳ��
	vector<Animal> v1;

	Animal a1("����¹", "��ɫ", 50);
	Animal a2("����", "��ɫ", 40);
	Animal a3("Ұ��", "��ɫ", 10);
	Animal a4("Ұ��", "��ɫ", 10);

	v1.push_back(a1);
	v1.push_back(a2);
	v1.push_back(a3);
	v1.push_back(a4);

	Animal a("Ұ��", "��ɫ", 10);

	int num = count(v1.begin(), v1.end(), a);
	cout << "ͳ��: " << num << endl;

}

void test5()
{
	// ����
	vector<int> v;
	v.push_back(10);
	v.push_back(120);
	v.push_back(5);
	v.push_back(1);

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), PrintVectorClass());

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), PrintVectorClass());
}

void test6()
{
	/*set<int> s1;*/
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(6);
	s1.insert(2);
	s1.insert(1);
	s1.insert(1);
	s1.insert(6);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	/*for (multiset<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;*/
}

class PrintList
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test7()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i * 10);
	}

	list<int> lTarget;
	lTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), lTarget.begin());
	for_each(lTarget.begin(), lTarget.end(), PrintVectorClass());

	/*random_shuffle(lTarget.begin(), lTarget.end());
	for_each(lTarget.begin(), lTarget.end(), PrintVectorClass());*/
}



int main()
{
	test7();
	return 0;
}