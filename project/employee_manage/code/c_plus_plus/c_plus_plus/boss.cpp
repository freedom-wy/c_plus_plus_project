#include "boss.h"

// ����ʵ��
Boss::Boss(int id, string name, int dID)
{
	this->w_ID = id;
	this->w_Name = name;
	this->w_DeptID = dID;
}

void Boss::showInfo()
{
	cout << "Ա�����: " << this->w_ID
		<< "\tԱ������: " << this->w_Name
		<< "\t��λ: " << this->getDeptName()
		<< "\t ��λְ��: ����˾��������" << endl;
}

string Boss::getDeptName()
{
	return string("�ϰ�");
}