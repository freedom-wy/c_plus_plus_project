#pragma once
#include "base.h"
#define FILENAME "employee.txt"

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
	void saveData();
	int getEmployeeNum();
	void loadData();
};
