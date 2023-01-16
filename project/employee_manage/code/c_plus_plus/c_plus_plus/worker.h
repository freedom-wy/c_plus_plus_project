#pragma once
#include <iostream>
using namespace std;

class Worker
{
	public:
		// 纯虚函数, 抽象类不能实例化, 子类必须重写抽象类中的纯虚函数
		virtual void showInfo() = 0;
		virtual string getDeptName() = 0;

	public:
		int w_ID; // 工号
		string w_Name; // 姓名
		int w_DeptID; // 部门编号
};
