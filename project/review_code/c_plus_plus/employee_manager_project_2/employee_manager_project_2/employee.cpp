#include "employee.h"

Employee::Employee(int b_id, string name, int d_id)
{
	cout << "Employee���췽��" << endl;
	this->b_id = b_id;
	this->name = name;
	this->d_id = d_id;
}

Employee::~Employee()
{
	cout << "Employee��������" << endl;
}

void Employee::showInfo()
{
	cout << "���: " << this->b_id <<
		", ����: " << this->name <<
		", ��������: ����Ա��, ����ɻ�" << endl;
}

string Employee::getDeptName()
{
	return string("����Ա��");
}
