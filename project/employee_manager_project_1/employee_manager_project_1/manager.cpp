#include "manager.h"

Manager::Manager(int bid, string name, int did)
{
	this->bId = bid;
	this->bName = name;
	this->dId = did;
}

void Manager::showInfo()
{
	cout << "Ա�����: " << this->bId
		<< ", Ա������: " << this->bName
		<< ", Ա����λ: " << this->getDeptName()
		<< ", ˵��: �������" << endl;
}

string Manager::getDeptName()
{
	return string("����");
}
