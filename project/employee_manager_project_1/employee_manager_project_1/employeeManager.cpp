#include "employeeManager.h"


// 员工管理系统具体实现
employeeManager::employeeManager()
{
    cout << "employeeManager构造方法" << endl;
    // 构造方法
    int num = this->getEmployeeNum();
    if (num > 0)
    {
        this->eEmpNum = num;
        this->loadData();
    }
    else
    {
        // 初始化员工管理系统信息
        this->eEmpNum = 0;
    }
}

employeeManager::~employeeManager()
{
    // 析构方法
    cout << "employeeManager析构方法" << endl;
}

void employeeManager::showMenu()
{
    // 显示菜单
    cout << "1、添加联系人" << endl;
    cout << "2、显示联系人" << endl;
    cout << "3、删除联系人" << endl;
    cout << "4、查找联系人" << endl;
    cout << "5、修改联系人" << endl;
    cout << "6、清空联系人" << endl;
    cout << "7、退出联系人" << endl;
}

void employeeManager::exitProgram()
{
    exit(0);
}

void employeeManager::addEmployee()
{
    // 添加员工  多态 父类指针或引用指向子类对象
    cout << "请输入添加员工的数量: " << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0)
    {
        // 附加原有空间
        int newSize = this->eEmpNum + addNum;
        // 在堆区重新创建数组
        Base** newSpace = new Base* [newSize];
        if (this->eEmpArry != NULL)
        {
            // 将原有数组中数据附加到新数组中
            for (int i = 0; i < this->eEmpNum; i++)
            {
                newSpace[i] = this->eEmpArry[i];
            }
        }

        //添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int bid;
            string bname;
            int select;

            cout << "请输入第" << i + 1 << "个员工编号: " << endl;
            cin >> bid;
            cout << "请输入第" << i + 1 << "个员工姓名: " << endl;
            cin >> bname;
            cout << "请输入第" << i + 1 << "个员工岗位: " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、总经理" << endl;
            cout << "3、老板" << endl;
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

        // 释放原有堆区空间数据
        delete[] this->eEmpArry;
        // 将新数据赋值给employeeManager类
        this->eEmpArry = newSpace;
        this->eEmpNum = newSize;
    }
    else
    {
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");
}

void employeeManager::showEmployee()
{
    if (this->eEmpNum == 0)
    {
        cout << "员工管理系统中无数据" << endl;
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

    // 打开文件
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
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
    // 读取文件
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int bid;
    string name;
    int did;
    cout << "原有数据" << this->eEmpNum << "行" << endl;
    // 同添加员工逻辑 在开辟空间前需计算文件内有多少行数据
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
    // 统计文件中数据行数
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