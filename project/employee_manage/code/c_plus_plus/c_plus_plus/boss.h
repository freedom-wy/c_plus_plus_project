#pragma once
#include <iostream>
#include "worker.h"
using namespace std;


// ����
class Boss : public Worker
{
public:
	Boss(int id, string name, int dID);
	void showInfo();
	string getDeptName();
};
