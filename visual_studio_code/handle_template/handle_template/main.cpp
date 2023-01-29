#include <iostream>
using namespace std;


// 类模板
template<class T1, class T2>
class Person
{
	public:
		T1 p_name;
		T2 p_age;
	public:
		Person(T1 name, T2 age)
		{
			this->p_name = name;
			this->p_age = age;
		}
		void showPerson()
		{
			cout << "姓名为: " << this->p_name << ", 年龄为: " << this->p_age << endl;
		}
};

void test1()
{
	Person<string, int>p1("张三", 20);
	p1.showPerson();
}

void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}

template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1类型为: " << typeid(T1).name() << endl;
	cout << "T2类型为: " << typeid(T2).name() << endl;
}

template<class T>
void printPerson3(T& p)
{
	p.showPerson();
	cout << "T的类型为: " << typeid(T).name() << endl;
}

void test2()
{
	Person<string, int>p("孙悟空", 999);
	printPerson3(p);
}

int main()
{
	test2();
	return 0;
}