#include "boss.h"

Boss::Boss(int bid, string name, int did)
{
	this->bId = bid;
	this->bName = name;
	this->dId = did;
}

void Boss::showInfo()
{
	cout << "Ա�����: " << this->bId
		<< ", Ա������: " << this->bName
		<< ", Ա����λ: " << this->getDeptName()
		<< ", ˵��: ���𿪹�˾" << endl;
}

string Boss::getDeptName()
{
	return string("�ϰ�");
}
