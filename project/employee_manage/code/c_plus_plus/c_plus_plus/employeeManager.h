#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

class employeeManager
{
	public:
		int e_EmpNum; // ��¼Ա����
		Worker** e_EmpArry;
	// ְ������
	public:
		employeeManager();
		~employeeManager();

		// ��Ա����
		void showMenu();
		void exitProgram();
		void addEmployee();
		void showEmployee();
};