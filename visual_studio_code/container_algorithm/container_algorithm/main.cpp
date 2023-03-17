#include <vector>
#include <deque>
#include <list>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

void PrintVectorFunction(int val)
{
	// 普通函数
	cout << val << endl;
}

class PrintVectorClass {
	// 函数对象
public:
	// 重写小括号
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test1()
{
	// 遍历vector容器
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
	// 重载==，让find底层代码可以对比Person自定义数据类型
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
	// 查找deque容器中的元素
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	
	deque<int>::iterator it1 = (find(d1.begin(), d1.end(), 5));
	if (it1 == d1.end())
	{
		cout << "未找到元素" << endl;
	}
	else
	{
		cout << "找到元素5" << endl;
	}

	Person p1("张三", 1);
	Person p2("李四", 2);
	Person p3("王五", 3);

	deque<Person> d2;
	d2.push_front(p1);
	d2.push_front(p2);
	d2.push_front(p3);

	deque<Person>::iterator it2 = find(d2.begin(), d2.end(), p2);
	if (it2 == d2.end())
	{
		cout << "未找到元素" << endl;
	}
	else
	{
		cout << "找到元素, " << "姓名: " << it2->name << endl;
	}
}

class FindFive
	// 返回bool类型的仿函数
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
		cout << "未找到元素5" << endl;
	}
	else {
		cout << "找到元素5" << endl;
	}

	list<Person>l2;
	Person p1("张三", 30);
	Person p2("李四", 10);
	Person p3("王五", 20);
	l2.push_front(p1);
	l2.push_front(p2);
	l2.push_front(p3);

	list<Person>::iterator it2 = find_if(l2.begin(), l2.end(), FindAge20());
	if (it2 == l2.end())
	{
		cout << "未找到年龄为20岁的人" << endl;
	}
	else {
		cout << "姓名为: " << it2->name << ", 年龄为: " << it2->age << endl;
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
//		cout << "名称: " << it->name << ", 颜色: " << it->color << ", 身高: " << it->height << endl;
//	}
//}

void test4()
{
	// set中添加自定义数据类型时, 需要指定排序规则
	// 统计
	vector<Animal> v1;

	Animal a1("长颈鹿", "白色", 50);
	Animal a2("大象", "灰色", 40);
	Animal a3("野猪", "黑色", 10);
	Animal a4("野猪", "黑色", 10);

	v1.push_back(a1);
	v1.push_back(a2);
	v1.push_back(a3);
	v1.push_back(a4);

	Animal a("野猪", "黑色", 10);

	int num = count(v1.begin(), v1.end(), a);
	cout << "统计: " << num << endl;

}

void test5()
{
	// 排序
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