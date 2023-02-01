#pragma once
#include "base.h"

// 在.h中声明, 不要写函数体, 在.cpp实现函数
class Employee : public Base
{
	public:
		Employee(int bid, string bname, int did);
		void showInfo();
		string getDeptName();
};
