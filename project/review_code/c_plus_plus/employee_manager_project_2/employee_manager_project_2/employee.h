#pragma once
#include "base.h"

// �̳л��� ��������
class Employee :public Base
{
public:
	// ���췽��
	Employee(int b_id, string name, int d_id);
	~Employee();
	void showInfo();
	string getDeptName();
};
