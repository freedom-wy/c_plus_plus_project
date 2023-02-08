#include "employeeManager.h"
#include "employee.h"

EmployeeManager::EmployeeManager()
{
	cout << "EmployeeManager构造方法" << endl;
}

EmployeeManager::~EmployeeManager()
{
	if (this->employeeArray != NULL || this->employeeNum > 0)
	{
		for (int i = 0; i < this->employeeNum; i++)
		{
			delete this->employeeArray[i];
		}
		delete[] this->employeeArray;
		this->employeeArray = NULL;
		this->employeeNum = 0;
	}
	cout << "EmployeeManager析构方法" << endl;
}

void EmployeeManager::addEmployee()
{
	// 添加员工
	// 添加员工前需判断原数组中是否有数据, 如有数需取出
	cout << "请输入要添加的员工数: ";
	int input;
	cin >> input;
	int new_size = input + this->employeeNum;
	Base** new_space = new Base* [new_size];
	if (this->employeeNum > 0)
	{
		for (int i = 0; i < this->employeeNum; i++)
		{
			new_space[i] = this->employeeArray[i];
		}
	}

	for (int i = 0; i < input; i++)
	{
		int b_id;
		string name;
		int d_id;
		cout << "请输入员工编号: " << endl;
		cin >> b_id;
		cout << "请输入员工姓名: " << endl;
		cin >> name;
		cout << "请输入员工岗位: " << endl;
		cin >> d_id;
		Base* worker = NULL;
		switch (d_id)
		{
		case 1:
			worker = new Employee(b_id, name, d_id);
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << "输入有误, 请重新输入" << endl;
			break;
		}

		new_space[this->employeeNum] = worker;
		this->employeeNum++;
	}

	delete[] this->employeeArray;
	this->employeeArray = new_space;
}

void EmployeeManager::showEmployee()
{
	for (int i = 0; i < this->employeeNum; i++)
	{
		this->employeeArray[i]->showInfo();
	}
}
