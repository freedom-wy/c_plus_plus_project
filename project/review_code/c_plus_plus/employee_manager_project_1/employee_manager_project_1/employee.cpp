#include "employee.h"

Employee::Employee(int bid, string name, int did)
{
	this->bId = bid;
	this->dId = did;
	this->bName = name;
}

void Employee::showInfo()
{
	cout << "Ա�����: " << this->bId 
		<< ", Ա������: " << this->bName 
		<< ", Ա����λ: " << this->getDeptName() 
		<< ", ˵��: ����ɻ�" << endl;
}

string Employee::getDeptName()
{
	return string("��ͨԱ��");
}