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
    if (this->e_EmpNum == 0)
    {
        cout << "ͨѶ¼��������, �������Ϣ" << endl;
        system("pause");
        system("cls");
        return;
    }
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

void employeeManager::delEmployee()
{
    if (this->e_EmpNum == 0)
    {
        cout << "ͨѶ¼��������, �������Ϣ" << endl;
        system("pause");
        system("cls");
        return;
    }
    // ɾ��Ա��
    cout << "������Ա��ID����: " << endl;
    int id = 0;
    cin >> id;
    int index = employeeIsExist(id);
    // TODO ���������Ŀ����ô�BUG
    if (index != -1)
    {
        for (int i = index; i < this->e_EmpNum - 1; i++)
        {
            this->e_EmpArry[i] = this->e_EmpArry[i + 1];
            this->e_EmpNum--;
        }
        cout << "Ա��ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "δ�ҵ�Ա��" << endl;
    }
    system("pause");
    system("cls");
}

int employeeManager::employeeIsExist(int id)
{
    // �ж�Ա���Ƿ����
    for (int i = 0; i < this->e_EmpNum; i++)
    {
        if (this->e_EmpArry[i]->w_ID == id)
        {
            return i;
        }
    }
    return -1;
}

void employeeManager::modifyEmployee()
{
    // �޸�Ա����Ϣ
    if (this->e_EmpNum == 0)
    {
        cout << "ͨѶ¼��������, �������Ϣ" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "������Ҫ�޸ĵ�Ա�����: " << endl;
    int id = 0;
    cin >> id;
    int index = employeeIsExist(id);
    if (index != -1)
    {
        // ɾ���ڶ��е�����
        delete this->e_EmpArry[index];
        // ���´�������
        int id;
        string name;
        int select;
        cout << "��������Ա�����: " << endl;
        cin >> id;

        cout << "��������Ա������: " << endl;
        cin >> name;

        cout << "��������Ա����λ: " << endl;
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

        this->e_EmpArry[index] = worker;
        cout << "�޸ĳɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

void employeeManager::findEmployee()
{
    // ����Ա��
    if (this->e_EmpNum == 0)
    {
        cout << "ͨѶ¼��������, �������Ϣ" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "��������ҷ�ʽ:" << endl;
    cout << "1��ͨ����������" << endl;
    cout << "2��ͨ��Ա����Ų���" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // ����
        cout << "������Ա������: " << endl;
        string name;
        cin >> name;
        // ���ұ�־
        bool flag = false;

        for (int i = 0; i < this->e_EmpNum; i++)
        {
            if (this->e_EmpArry[i]->w_Name == name)
            {
                cout << "���ҳɹ�, ��ϢΪ: " << endl;
                this->e_EmpArry[i]->showInfo();
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << "���޴���" << endl;
        }
    }
    else if(select == 2)
    {
      // ���
        int id;
        cout << "������Ա�����: " << endl;
        cin >> id;

        int index = employeeIsExist(id);
        if (index != -1)
        {
            cout << "���ҳɹ�, ��ϢΪ: " << endl;
            this->e_EmpArry[index]->showInfo();
        }
        else
        {
            cout << "����ʧ��" << endl;
        }
    }
    else
    {
        cout << "��������, ����������" << endl;
    }

    system("pause");
    system("cls");
}

void employeeManager::saveData()
{
    //// ��������, ����ͨ�������Ʒ�ʽ����
    //// ���ļ�
    //ofstream ofs;
    //ofs.open("employee.txt", ios::app | ios::binary);
    //if (!ofs.is_open())
    //{
    //    cout << "�ļ���ʧ��" << endl;
    //    return;
    //}
    //if (this->e_EmpNum == 0)
    //{
    //    return;
    //}
    //// ����д������
    //for (int i = 0; i < this->e_EmpNum; i++)
    //{
    //    ofs.write((const char*)this->e_EmpArry[i], sizeof(this->e_EmpArry[i]));
    //}
    //// �ر��ļ�
    //ofs.close();
    
}
