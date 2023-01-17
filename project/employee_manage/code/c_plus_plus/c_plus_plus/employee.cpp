#include "employee.h"

// 子类实现
Employee::Employee(int id, string name, int dID)
{
	this->w_ID = id;
	this->w_Name = name;
	this->w_DeptID = dID;
}

void Employee::showInfo()
{
	cout << "员工编号: " << this->w_ID
		<< "\t员工姓名: " << this->w_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t 岗位职责: 完成经理交给的任务" << endl;
}

string Employee::getDeptName()
{
	return string("员工");
}