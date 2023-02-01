#include "employee.h"

Employee::Employee(int bid, string name, int did)
{
	this->bId = bid;
	this->dId = did;
	this->bName = name;
}

void Employee::showInfo()
{
	cout << "员工编号: " << this->bId 
		<< ", 员工姓名: " << this->bName 
		<< ", 员工岗位: " << this->getDeptName() 
		<< ", 说明: 负责干活" << endl;
}

string Employee::getDeptName()
{
	return string("普通员工");
}