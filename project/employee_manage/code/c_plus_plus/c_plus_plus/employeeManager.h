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
		int e_EmpNum; // 记录员工数
		Worker** e_EmpArry;
	// 职工管理
	public:
		employeeManager();
		~employeeManager();

		// 成员方法
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