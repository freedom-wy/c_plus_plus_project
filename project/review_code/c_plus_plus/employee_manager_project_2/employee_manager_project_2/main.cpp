#include <iostream>
#include "employeeManager.h"
using namespace std;

/*
1�������鴴���ڶ���
2���������̬
*/

int main()
{
	EmployeeManager* em = new EmployeeManager();
	em->addEmployee();
	em->showEmployee();
	delete em;
}