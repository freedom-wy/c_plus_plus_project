#include "employee.h"

// ����ʵ��
Employee::Employee(int id, string name, int dID)
{
	this->w_ID = id;
	this->w_Name = name;
	this->w_DeptID = dID;
}

void Employee::showInfo()
{
	cout << "Ա�����: " << this->w_ID
		<< "\tԱ������: " << this->w_Name
		<< "\t��λ: " << this->getDeptName()
		<< "\t ��λְ��: ��ɾ�����������" << endl;
}

string Employee::getDeptName()
{
	return string("Ա��");
}