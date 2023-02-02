#include "employeeManager.h"


// Ա������ϵͳ����ʵ��
employeeManager::employeeManager()
{
    cout << "employeeManager���췽��" << endl;
    // ���췽��
    int num = this->getEmployeeNum();
    if (num > 0)
    {
        this->eEmpNum = num;
        this->loadData();
    }
    else
    {
        // ��ʼ��Ա������ϵͳ��Ϣ
        this->eEmpNum = 0;
    }
}

employeeManager::~employeeManager()
{
    // ��������
    cout << "employeeManager��������" << endl;
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
    // ���Ա��  ��̬ ����ָ�������ָ���������
    cout << "���������Ա��������: " << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0)
    {
        // ����ԭ�пռ�
        int newSize = this->eEmpNum + addNum;
        // �ڶ������´�������
        Base** newSpace = new Base* [newSize];
        if (this->eEmpArry != NULL)
        {
            // ��ԭ�����������ݸ��ӵ���������
            for (int i = 0; i < this->eEmpNum; i++)
            {
                newSpace[i] = this->eEmpArry[i];
            }
        }

        //���������
        for (int i = 0; i < addNum; i++)
        {
            int bid;
            string bname;
            int select;

            cout << "�������" << i + 1 << "��Ա�����: " << endl;
            cin >> bid;
            cout << "�������" << i + 1 << "��Ա������: " << endl;
            cin >> bname;
            cout << "�������" << i + 1 << "��Ա����λ: " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2���ܾ���" << endl;
            cout << "3���ϰ�" << endl;
            cin >> select;

            Base* worker = NULL;

            switch (select)
            {
            case 1:
                worker = new Employee(bid, bname, select);
                break;
            case 2:
                worker = new Manager(bid, bname, select);
                break;
            case 3:
                worker = new Boss(bid, bname, select);
                break;
            default:
                break;
            }
            
            newSpace[this->eEmpNum + i] = worker;
        }

        // �ͷ�ԭ�ж����ռ�����
        delete[] this->eEmpArry;
        // �������ݸ�ֵ��employeeManager��
        this->eEmpArry = newSpace;
        this->eEmpNum = newSize;
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
    if (this->eEmpNum == 0)
    {
        cout << "Ա������ϵͳ��������" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < this->eEmpNum; i++)
    {
        this->eEmpArry[i]->showInfo();
    }
    system("pause");
    system("cls");
}

void employeeManager::saveData()
{
    if (this->eEmpNum == 0)
    {
        return;
    }

    // ���ļ�
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    if (!ofs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    for (int i = 0; i < this->eEmpNum; i++)
    {
        ofs << this->eEmpArry[i]->bId << " "
            << this->eEmpArry[i]->bName << " "
            << this->eEmpArry[i]->dId << endl;
    }

    ofs.close();
}

void employeeManager::loadData()
{
    // ��ȡ�ļ�
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int bid;
    string name;
    int did;
    cout << "ԭ������" << this->eEmpNum << "��" << endl;
    // ͬ���Ա���߼� �ڿ��ٿռ�ǰ������ļ����ж���������
    this->eEmpArry = new Base * [this->eEmpNum];

    int index = 0;
    while (ifs >> bid && ifs >> name && ifs >> did)
    {
        Base* worker = NULL;
        switch (did)
        {
        case 1:
            worker = new Employee(bid, name, did);
            break;
        case 2:
            worker = new Manager(bid, name, did);
            break;
        case 3:
            worker = new Boss(bid, name, did);
            break;
        default:
            break;
        }

        this->eEmpArry[index] = worker;
        index++;
    }

    ifs.close();
}

int employeeManager::getEmployeeNum()
{
    // ͳ���ļ�����������
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    if (!ifs.is_open())
    {
        this->eEmpNum = 0;
        this->eEmpArry = NULL;
        ifs.close();
        return -1;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->eEmpNum = 0;
        this->eEmpArry = NULL;
        ifs.close();
        return -1;
    }

    ifs.close();

    ifstream ifs_num;
    ifs_num.open(FILENAME, ios::in);
    
    int bid;
    string name;
    int did;

    int index = 0;

    while (ifs_num >> bid && ifs_num >> name && ifs_num >> did)
    {
        index++;
    }
    ifs_num.close();

    return index;
}