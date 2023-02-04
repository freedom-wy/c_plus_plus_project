#include "manager.h"

Manager::Manager(int bid, string name, int did)
{
	this->bId = bid;
	this->bName = name;
	this->dId = did;
}

void Manager::showInfo()
{
	cout << "员工编号: " << this->bId
		<< ", 员工姓名: " << this->bName
		<< ", 员工岗位: " << this->getDeptName()
		<< ", 说明: 负责管理" << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}
