#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	int b_id;
	string name;
	int d_id;
public:
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;
};
