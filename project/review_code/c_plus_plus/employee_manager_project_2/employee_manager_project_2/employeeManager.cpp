#include "employeeManager.h"
#include "employee.h"
#include <fstream>

EmployeeManager::EmployeeManager()
{
	cout << "EmployeeManager���췽��" << endl;
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

	// �ļ�������
	if (!ifs.is_open())
	{
		this->employeeNum = 0;
		this->employeeArray = NULL;
		ifs.close();
		return -1;
	}

	// �ļ���������
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
	// д��һ���ַ��������¶�λ��ͷ��

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
