#include "employeeManager.h"
/*
����:
1��չʾ�˵�
2�������ϵ��
3��չʾ��ϵ��
4��ɾ����ϵ��
5��������ϵ��
6���޸���ϵ��
7�������ϵ��
8��������ϵ�˺ͼ�����ϵ��
9���˳�����
*/

/*
����:
����һ�����࣬��Ա���� ���š����������ű�ţ���Ա���� չʾԱ����Ϣ��չʾԱ��title
1��Ա����
2���������
3���ϰ���
4��Ա��������
5�����ļ�
*/

int main()
{
	employeeManager em;
	int choice = 0;
	while (1)
	{
		em.showMenu();
		cout << "������˵���: " << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				// ���Ա����Ϣ
				cout << "���Ա����Ϣ" << endl;
				em.addEmployee();
				break;
			case 2:
				cout << "��ʾԱ����Ϣ" << endl;
				em.showEmployee();
				break;
			case 3:
				cout << "ɾ��Ա��" << endl;
				break;
			case 4:
				cout << "����Ա��" << endl;
				break;
			case 5:
				cout << "�޸�Ա��" << endl;
				break;
			case 6:
				cout << "���Ա��" << endl;
				break;
			case 7:
				em.saveData();
				em.exitProgram();
				break;
			default:
				cout << "��������, ����������" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
}