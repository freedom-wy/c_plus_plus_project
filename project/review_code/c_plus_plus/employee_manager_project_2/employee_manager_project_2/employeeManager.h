#pragma once
#include "base.h"
#define FILENAME "employee.txt"

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
	void saveData();
	int getEmployeeNum();
	void loadData();
};
