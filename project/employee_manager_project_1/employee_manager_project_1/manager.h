#pragma once
#include "base.h"

class Manager :public Base
{
	public:
		Manager(int bid, string name, int did);
		void showInfo();
		string getDeptName();
};
