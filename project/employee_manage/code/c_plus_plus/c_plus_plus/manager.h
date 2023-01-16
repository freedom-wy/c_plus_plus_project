#pragma once
#include <iostream>
#include "worker.h"
using namespace std;


// æ≠¿Ì
class Manager : public Worker
{
public:
	Manager(int id, string name, int dID);
	void showInfo();
	string getDeptName();
};
