#include "manager.h"

// 子类实现
Manager::Manager(int id, string name, int dID)
{
	this->w_ID = id;
	this->w_Name = name;
	this->w_DeptID = dID;
}

void Manager::showInfo()
{
	cout << "员工编号: " << this->w_ID
		<< "\t员工姓名: " << this->w_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t 岗位职责: 完成老板交给的任务, 并下发任务给员工" << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}