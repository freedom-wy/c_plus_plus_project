#include "boss.h"

Boss::Boss(int bid, string name, int did)
{
	this->bId = bid;
	this->bName = name;
	this->dId = did;
}

void Boss::showInfo()
{
	cout << "员工编号: " << this->bId
		<< ", 员工姓名: " << this->bName
		<< ", 员工岗位: " << this->getDeptName()
		<< ", 说明: 负责开公司" << endl;
}

string Boss::getDeptName()
{
	return string("老板");
}
