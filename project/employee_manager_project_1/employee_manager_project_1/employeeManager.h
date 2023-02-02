#pragma once
#include "base.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "employee.txt"

class employeeManager
{
	// Ա��������, ��ά��һ������
	public:
		int eEmpNum; //ά��Ա������
		Base** eEmpArry;
	public:
		// ���췽��
		employeeManager();
		~employeeManager();
		// ��Ա����
		void showMenu();
		void exitProgram();
		void addEmployee();
		void showEmployee();
		void saveData();
		void loadData();
		int getEmployeeNum();
};