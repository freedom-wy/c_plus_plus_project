#include <iostream>
#include "employeeManager.h"
#include <fstream>
using namespace std;

/*
1����������, ������Ա����(id, name, ����id), ��ʾԱ����Ϣ��Ա����������������
2������Ա���༯�ɻ���, Ա�����вι��췽��, ��������, ʵ�ֳ������ķ���
3������Ա��������, ��Ա���������ڶ���������, Ա������, ���췽���ж�Ա����Ϣ���г�ʼ��, ����������ɾ����������
4��Ա�������� ��Ա���� ���Ա�� չʾԱ����Ϣ, ����Ա����Ϣ���ļ�, ���ļ��м���Ա����Ϣ
*/

int main()
{
	EmployeeManager* em = new EmployeeManager();
	while (true)
	{
		int select = 0;
		cout << "�����빦�ܱ��: " << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "���Ա��" << endl;
			em->addEmployee();
			break;
		case 2:
			cout << "չʾԱ����Ϣ" << endl;
			em->showEmployee();
			break;
		case 3:
			cout << "�˳�����" << endl;
			//em->saveData();
			delete em;
			exit(0);
		default:
			break;
		}
	}

	//ifstream ifs;
	//ifs.open(FILENAME, ios::in);
	//int b_id;
	//string name;
	//int d_id;

	//while (ifs >> b_id && ifs >> name && ifs >> d_id)
	//{
	//	cout << "���: " << b_id <<
	//		", ����: " << name <<
	//		", ����id" << d_id << endl;
	//}

	//ifs.close();

}