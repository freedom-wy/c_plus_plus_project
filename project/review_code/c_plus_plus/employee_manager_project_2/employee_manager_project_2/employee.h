#pragma once
#include "base.h"

// 继承基类 声明方法
class Employee :public Base
{
public:
	// 构造方法
	Employee(int b_id, string name, int d_id);
	~Employee();
	void showInfo();
	string getDeptName();
};
