#include "employeeManager.h"
#include "employee.h"
#include <fstream>

EmployeeManager::EmployeeManager()
{
	cout << "EmployeeManager构造方法" << endl;
	this->loadData();
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
	//this->employeeNum = new_size;
}

void EmployeeManager::showEmployee()
{
	for (int i = 0; i < this->employeeNum; i++)
	{
		this->employeeArray[i]->showInfo();
	}
}

void EmployeeManager::saveData()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->employeeNum; i++)
	{
		ofs << this->employeeArray[i]->b_id << " "
			<< this->employeeArray[i]->name << " "
			<< this->employeeArray[i]->d_id << endl;
	}

	ofs.close();
}

int EmployeeManager::getEmployeeNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 文件不存在
	if (!ifs.is_open())
	{
		this->employeeNum = 0;
		this->employeeArray = NULL;
		ifs.close();
		return -1;
	}

	// 文件中无数据
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->employeeNum = 0;
		this->employeeArray = NULL;
		ifs.close();
		return -1;
	}
	ifs.close();
	// 写入一个字符后需重新定位到头部

	ifstream ifs_data;
	ifs_data.open(FILENAME, ios::in);
	int b_id;
	string name;
	int d_id;

	int num = 0;
	while (ifs_data >> b_id && ifs_data >> name && ifs_data >> d_id)
	{
		num++;
	}

	ifs_data.close();
	return num;
}

void EmployeeManager::loadData()
{
	int num = this->getEmployeeNum();
	if (num > 0)
	{
		this->employeeArray = new Base * [num];
		
		int b_id;
		string name;
		int d_id;
		
		ifstream ifs;
		ifs.open(FILENAME, ios::in);

		int index = 0;
		while (ifs >> b_id && ifs >> name && ifs >> d_id)
		{
			Base* worker = NULL;
			switch (d_id)
			{
			case 1:
				worker = new Employee(b_id, name, d_id);
				break;
			default:
				break;
			}

			this->employeeArray[index] = worker;
			index++;
		}
		/*while (ifs >> b_id && ifs >> name && ifs >> d_id)
		{
			Base* worker = NULL;
			switch (d_id)
			{
			case 1:
				worker = new Employee(b_id, name, d_id);
				break;
			default:
				break;
			}

			this->employeeArray[index] = worker;
			index++;
		}*/

		ifs.close();
		this->employeeNum = num;
	}
	else
	{
		this->employeeArray = NULL;
		this->employeeNum = 0;
	}
}
