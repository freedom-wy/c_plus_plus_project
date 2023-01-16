#include "employeeManager.h"

employeeManager::employeeManager()
{
	// �������ʵ��
    // ��ʼ��������ָ��
    this->e_EmpNum = 0;
    this->e_EmpArry = NULL;
}

employeeManager::~employeeManager()
{
	// ��������ʵ��
}

void employeeManager::showMenu()
{
	// ��ʾ�˵�
    cout << "1�������ϵ��" << endl;
    cout << "2����ʾ��ϵ��" << endl;
    cout << "3��ɾ����ϵ��" << endl;
    cout << "4��������ϵ��" << endl;
    cout << "5���޸���ϵ��" << endl;
    cout << "6�������ϵ��" << endl;
    cout << "7���˳���ϵ��" << endl;
}

void employeeManager::exitProgram()
{
    exit(0);
}

void employeeManager::addEmployee()
{
    // ���Ա��
    cout << "���������Ա��������: " << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0)
    {
        // ����ԭ�пռ�
        int newSize = this->e_EmpNum + addNum;
        
        // ����ָ������
        Worker** newSpace = new Worker* [newSize];
        if (this->e_EmpArry != NULL)
        {
            // ��ԭ�������е����ݿ������µ�������
            for (int i = 0; i < this->e_EmpNum; i++)
            {
                newSpace[i] = this->e_EmpArry[i];
            }
        }

        // ����µ�����
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int select;
            cout << "������� " << i + 1 << " ����Ա�����: " << endl;
            cin >> id;

            cout << "������� " << i + 1 << " ����Ա������: " << endl;
            cin >> name;

            cout << "������� " << i + 1 << " ����Ա����λ: " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2���ܾ���" << endl;
            cout << "3���ϰ�" << endl;
            cin >> select;

            Worker* worker = NULL;
            switch (select)
            {
            case 1:
                worker = new Employee(id, name, select);
                break;
            case 2:
                worker = new Manager(id, name, select);
                break;
            case 3:
                worker = new Boss(id, name, select);
                break;
            default:
                break;
            }
            newSpace[this->e_EmpNum + i] = worker;
        }
        
        // �ͷ�ԭ�пռ�
        delete[] this->e_EmpArry;
        // �����¿ռ�ָ��
        this->e_EmpArry = newSpace;
        this->e_EmpNum = newSize;

        cout << "�ɹ����" << addNum << "����Ա��" << endl;
    }
    else
    {
        cout << "��������" << endl;
    }
    system("pause");
    system("cls");
}

void employeeManager::showEmployee()
{
    cout << "����Ա������: " << this->e_EmpNum << endl;
    // ��ʾԱ����Ϣ
    for (int i = 0; i < e_EmpNum; i++)
    {
        this->e_EmpArry[i]->showInfo();
        //cout << e_EmpArry[i] << endl;
    }

    system("pause");
    system("cls");
}