#pragma once
#include "base.h"

// ��.h������, ��Ҫд������, ��.cppʵ�ֺ���
class Employee : public Base
{
	public:
		Employee(int bid, string bname, int did);
		void showInfo();
		string getDeptName();
};
