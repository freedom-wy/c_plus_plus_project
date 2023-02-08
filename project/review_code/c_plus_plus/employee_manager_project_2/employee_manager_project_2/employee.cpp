#include "employee.h"

Employee::Employee(int b_id, string name, int d_id)
{
	cout << "Employee构造方法" << endl;
	this->b_id = b_id;
	this->name = name;
	this->d_id = d_id;
}

Employee::~Employee()
{
	cout << "Employee析构方法" << endl;
}

void Employee::showInfo()
{
	cout << "编号: " << this->b_id <<
		", 姓名: " << this->name <<
		", 工作内容: 基础员工, 负责干活" << endl;
}

string Employee::getDeptName()
{
	return string("基础员工");
}
