#pragma once
#include "base.h"

// Ա���������
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
