#include "manager.h"

// ����ʵ��
Manager::Manager(int id, string name, int dID)
{
	this->w_ID = id;
	this->w_Name = name;
	this->w_DeptID = dID;
}

void Manager::showInfo()
{
	cout << "Ա�����: " << this->w_ID
		<< "\tԱ������: " << this->w_Name
		<< "\t��λ: " << this->getDeptName()
		<< "\t ��λְ��: ����ϰ彻��������, ���·������Ա��" << endl;
}

string Manager::getDeptName()
{
	return string("����");
}