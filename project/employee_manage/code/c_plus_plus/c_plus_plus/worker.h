#pragma once
#include <iostream>
using namespace std;

class Worker
{
	public:
		// ���麯��, �����಻��ʵ����, ���������д�������еĴ��麯��
		virtual void showInfo() = 0;
		virtual string getDeptName() = 0;

	public:
		int w_ID; // ����
		string w_Name; // ����
		int w_DeptID; // ���ű��
};
