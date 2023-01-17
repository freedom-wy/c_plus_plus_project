#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
using namespace std;

#define FILENAME "employee.txt"

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
		void delEmployee();
		int employeeIsExist(int id);
		void modifyEmployee();
		void findEmployee();
		void saveData();
		void loadData();
};