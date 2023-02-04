#include <iostream>
#include <vector>
using namespace std;

void test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);

	/*vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	while (pBegin != pEnd)
	{
		cout << "数据为: " << *pBegin << endl;
		pBegin++;
	}*/

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "数据为: " << *it << endl;
	}
}

void test2()
{
	// 自定义数据类型
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
	};

	//vector<Person> v;
	//// 创建自定义对象
	//Person p1("张三", 1);
	//Person p2("李四", 2);

	//// 放入容器
	//v.push_back(p1);
	//v.push_back(p2);

	//// 遍历
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名为: " << (*it).name << ", 年龄为: " << (*it).age << endl;
	//}
	
	// 放入指针
	vector<Person*> v;
	Person p1("王五", 3);
	Person p2("赵六", 4);
	v.push_back(&p1);
	v.push_back(&p2); 

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名为: " << (*it)->name << ", 年龄为: " << (*it)->age << endl;
	}



}

void test3()
{
	// 拷贝构造
	class Person
	{
	private:
		string name;
		int* age;
	public:
		Person(string name, int age)
		{
			cout << "构造方法" << endl;
			this->name = name;
			this->age = new int(age);
		}
		Person(const Person& p)
		{
			cout << "拷贝构造" << endl;
			//this->age = p.age;
			this->age = new int(*(p.age)); // 深拷贝
			this->name = p.name;
		}
		~Person()
		{
			cout << "析构函数" << endl;
			delete this->age;
			this->age = NULL;
		}

		void showInfo()
		{
			cout << "姓名为: " << this->name << ", 年龄为: " << *(this->age) << endl;
		}
	};

	Person p1("张三", 1);
	Person p2(p1);
	p2.showInfo();
}

void test4()
{
	string s1;
	cout << "s1的值为: " << s1 << endl;
}

int main()
{
	test4();
	return 0;
}