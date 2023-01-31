#pragma once
#include <iostream>
using namespace std;

// ���ļ���д
template<class T1, class T2>
class Base
{
	// ����
	public:
		T1 b_name;
		T2 b_age;
	public:
		virtual void showInfo() = 0;
};

template<class T1, class T2>
class Person1 :public Base<T1, T2>
{
public:
	Person1(T1 name, T2 age);
	void showInfo();
};


// ����ʵ��
template<class T1, class T2>
Person1<T1, T2>::Person1(T1 name, T2 age)
{
	this->b_name = name;
	this->b_age = age;
}

template<class T1, class T2>
void Person1<T1, T2>::showInfo()
{
	cout << "����Ϊ: " << this->b_name << ", ����Ϊ: " << this->b_age << endl;
}
