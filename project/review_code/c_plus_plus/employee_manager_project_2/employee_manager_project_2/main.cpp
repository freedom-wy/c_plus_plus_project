#include <iostream>
#include "employeeManager.h"
using namespace std;

/*
1、将数组创建在堆区
2、利用类多态
*/

int main()
{
	EmployeeManager* em = new EmployeeManager();
	em->addEmployee();
	em->showEmployee();
	delete em;
}