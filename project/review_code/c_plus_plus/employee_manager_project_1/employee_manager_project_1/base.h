#pragma once
#include <iostream>
using namespace std;

class Base
{
	public:
		int bId;
		string bName;
		int dId;
	public:
		virtual void showInfo() = 0;
		virtual string getDeptName() = 0;
};
