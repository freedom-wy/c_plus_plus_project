#pragma once
#include "base.h"

// 员工管理程序
class EmployeeManager
{
public:
	Base** employeeArray;
	int employeeNum;
	
	EmployeeManager();
	~EmployeeManager();

	void addEmployee();
	void showEmployee();
};
