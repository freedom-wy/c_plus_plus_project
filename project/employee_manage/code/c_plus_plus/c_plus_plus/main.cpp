#include <iostream>
using namespace std;
#include "employeeManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main()
{
#if 0
	/*Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;*/
	/*int array[2] = { 1, 2 };
	for (int i = 0; i < 2; i++)
	{
		cout << "Ԫ�ص�ֵΪ: " << array[i] << endl;
	}*/

	/*int a = 1;
	int b = 2;
	int* array[2] = { &a, &b };
	for (int i = 0; i < 2; i++)
	{
		cout << "Ԫ��ֵΪ: " << *array[i] << endl;
	}*/

	int* array[5];
	for (int i = 0; i < 5; i++)
	{
		array[i] = new int(i);
	}
	delete array[0];
	for (int i = 0; i < sizeof(array) / sizeof(int*); i++)
	{
		cout << "Ԫ�ص�ֵΪ: " << *array[i] << endl;
	}


#else
	employeeManager em;
	int choice = 0;
	while (1)
	{
		em.showMenu();
		cout << "������˵����: " << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				// �����ϵ��
				em.addEmployee();
				break;
			case 2:
				em.showEmployee();
				break;
			case 3:
				em.delEmployee();
				break;
			case 4:
				em.findEmployee();
				break;
			case 5:
				em.modifyEmployee();
				break;
			case 6:
				break;
			case 7:
				em.exitProgram();
				break;
			default:
				cout << "��������, ��������" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
#endif
	return 0;
}