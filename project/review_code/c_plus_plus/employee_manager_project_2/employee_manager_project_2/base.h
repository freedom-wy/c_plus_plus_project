#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	int b_id;
	string name;
	int d_id;
public:
	virtual ~Base() // 如不设置需析构, 则仅进行base析构, 设置后会执行子类的析构
	{
		cout << "base虚析构方法" << endl;
	}
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;
};
