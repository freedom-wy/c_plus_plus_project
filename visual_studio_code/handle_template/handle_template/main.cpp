#include "test.hpp"
//#include <iostream>
//using namespace std;
//
//
//// ��ģ��
//template<class T1, class T2>
//class Person
//{
//	public:
//		T1 p_name;
//		T2 p_age;
//	public:
//		Person(T1 name, T2 age)
//		{
//			this->p_name = name;
//			this->p_age = age;
//		}
//		void showPerson()
//		{
//			cout << "����Ϊ: " << this->p_name << ", ����Ϊ: " << this->p_age << endl;
//		}
//};
//
//void test1()
//{
//	Person<string, int>p1("����", 20);
//	p1.showPerson();
//}
//
//void printPerson1(Person<string, int>& p)
//{
//	p.showPerson();
//}
//
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p)
//{
//	p.showPerson();
//	cout << "T1����Ϊ: " << typeid(T1).name() << endl;
//	cout << "T2����Ϊ: " << typeid(T2).name() << endl;
//}
//
//template<class T>
//void printPerson3(T& p)
//{
//	p.showPerson();
//	cout << "T������Ϊ: " << typeid(T).name() << endl;
//}
//
//void test2()
//{
//	Person<string, int>p("�����", 999);
//	printPerson3(p);
//}
//
//template<class T1, class T2>
//class Base
//{
//public:
//	T1 b_name;
//	T2 b_age;
//};
//
//class Son1 :public Base<string, int> // �̳�ʱ����ָ��ģ������
//{
//	public:
//		Son1()
//		{
//			// ���캯��
//			this->b_name = "����";
//			this->b_age = 20;
//		}
//		void showInfo()
//		{
//			cout << "����Ϊ: " << this->b_name << ", ����Ϊ: " << this->b_age << endl;
//		}
//};
//
//template<class T1, class T2>
//class Son2 :public Base<T1, T2>
//{
//	public:
//		Son2()
//		{
//			this->b_name = "����";
//			this->b_age = 18;
//		}
//		void showInfo()
//		{
//			cout << "T1����Ϊ: " << typeid(T1).name() << endl;
//			cout << "T2����Ϊ: " << typeid(T2).name() << endl;
//			cout << "����Ϊ: " << this->b_name << ", ����Ϊ: " << this->b_age << endl;
//		}
//};
//
//void test3()
//{
//	/*Son1 s1;
//	s1.showInfo();*/
//	Son2<string, int> s2;
//	s2.showInfo();
//}

void test4()
{
	Person1<string, int>p1("����", 18);
	p1.showInfo();
}

int main()
{
	test4();
	return 0;
}