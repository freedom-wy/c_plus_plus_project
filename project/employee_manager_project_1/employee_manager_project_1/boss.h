#pragma once
#include "base.h"

class Boss :public Base
{
public:
	Boss(int bid, string name, int did);
	void showInfo();
	string getDeptName();
};
