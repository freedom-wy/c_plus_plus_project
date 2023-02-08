#include "employeeManager.h"
#include "employee.h"

EmployeeManager::EmployeeManager()
{
	cout << "EmployeeManager���췽��" << endl;
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
	cout << "EmployeeManager��������" << endl;
}

void EmployeeManager::addEmployee()
{
	// ���Ա��
	// ���Ա��ǰ���ж�ԭ�������Ƿ�������, ��������ȡ��
	cout << "������Ҫ��ӵ�Ա����: ";
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
		cout << "������Ա�����: " << endl;
		cin >> b_id;
		cout << "������Ա������: " << endl;
		cin >> name;
		cout << "������Ա����λ: " << endl;
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
			cout << "��������, ����������" << endl;
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
