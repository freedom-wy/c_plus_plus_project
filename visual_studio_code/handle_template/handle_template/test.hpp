#pragma once
#include <iostream>
using namespace std;

// 分文件编写
template<class T1, class T2>
class Base
{
	// 基类
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


// 类外实现
template<class T1, class T2>
Person1<T1, T2>::Person1(T1 name, T2 age)
{
	this->b_name = name;
	this->b_age = age;
}

template<class T1, class T2>
void Person1<T1, T2>::showInfo()
{
	cout << "名字为: " << this->b_name << ", 年龄为: " << this->b_age << endl;
}
