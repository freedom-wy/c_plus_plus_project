#pragma once
#include "base.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "employee.txt"

class employeeManager
{
	// 员工管理类, 需维护一个数组
	public:
		int eEmpNum; //维护员工数量
		Base** eEmpArry;
	public:
		// 构造方法
		employeeManager();
		~employeeManager();
		// 成员方法
		void showMenu();
		void exitProgram();
		void addEmployee();
		void showEmployee();
		void saveData();
		void loadData();
		int getEmployeeNum();
};