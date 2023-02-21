#include <iostream>
#include <list>
#include <set>
using namespace std;

class Person
{
public:
	string name;
	int age;
	int height;
public:
	Person(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}
};

bool ComparePerson(Person& p1, Person& p2)
{
	if (p1.age == p2.age)
	{
		return p1.height > p2.height; // 降序
	}
	else
	{
		return p1.age < p2.age; // 升序
	}
}

void test1()
{
	list<Person> L;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	/*for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名: " << it->name 
			<< ", 年龄: " << it->age 
			<< ", 身高: " << it->height << endl;
	}*/

	L.sort(ComparePerson);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名: " << it->name
			<< ", 年龄: " << it->age
			<< ", 身高: " << it->height << endl;
	}
}

void test2()
{
	pair<string, int> p1(string("tom"), 20);
	pair<string, int> p2 = make_pair("jerry", 10);

	cout << "P1的姓名为: " << p1.first << ", 年龄为: " << p1.second << endl;
	cout << "p2的姓名为: " << p2.first << ", 年龄为: " << p2.second << endl;
}

void test3()
{
	class MyCompare
	{
	public:
		bool operator()(int v1, int v2)const
		{
			return v1 > v2;
		}
	};
	// set默认排序规则为从小到大
	set<int, MyCompare>s1;
	s1.insert(20);
	s1.insert(10);
	s1.insert(30);
	s1.insert(50);
	s1.insert(40);

	for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main()
{
	test3();
	return 0;
}