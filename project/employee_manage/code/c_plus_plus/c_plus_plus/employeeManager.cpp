#include "employeeManager.h"

employeeManager::employeeManager()
{
	// 构造具体实现
    // 初始化人数和指针
    cout << "employeeManager构造方法" << endl;
    int num = getEmployeeNum();
    if (num > 0)
    {
        this->e_EmpNum = num;
        loadData();
    }
}

employeeManager::~employeeManager()
{
    cout << "employeeManager析构方法" << endl;
	// 析构具体实现
    saveData();
    if (this->e_EmpArry != NULL)
    {
        for (int i = 0; i < this->e_EmpNum; i++)
        {
            delete this->e_EmpArry[i];
        }
        delete[] this->e_EmpArry;
        this->e_EmpNum = 0;
        this->e_EmpArry = NULL;
    }
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
    // 添加员工
    cout << "请输入添加员工的数量: " << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0)
    {
        // 附加原有空间
        int newSize = this->e_EmpNum + addNum;
        
        // 在堆区创建指针数组
        Worker** newSpace = new Worker* [newSize];
        if (this->e_EmpArry != NULL)
        {
            // 将原有数组中的数据拷贝到新的数组中
            for (int i = 0; i < this->e_EmpNum; i++)
            {
                newSpace[i] = this->e_EmpArry[i];
            }
        }

        // 添加新的数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int select;
            cout << "请输入第 " << i + 1 << " 个新员工编号: " << endl;
            cin >> id;

            cout << "请输入第 " << i + 1 << " 个新员工姓名: " << endl;
            cin >> name;

            cout << "请输入第 " << i + 1 << " 个新员工岗位: " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、总经理" << endl;
            cout << "3、老板" << endl;
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
        
        // 释放原有空间
        delete[] this->e_EmpArry;
        // 更改新空间指向
        this->e_EmpArry = newSpace;
        this->e_EmpNum = newSize;

        cout << "成功添加" << addNum << "名新员工" << endl;
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
    if (this->e_EmpNum == 0)
    {
        cout << "通讯录中无数据, 请添加信息" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "现有员工数量: " << this->e_EmpNum << endl;
    // 显示员工信息
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
        cout << "通讯录中无数据, 请添加信息" << endl;
        system("pause");
        system("cls");
        return;
    }
    // 删除员工
    cout << "请输入员工ID号码: " << endl;
    int id = 0;
    cin >> id;
    int index = employeeIsExist(id);
    if (index != -1)
    {
        for (int i = index; i < this->e_EmpNum; i++)
        {
            this->e_EmpArry[i] = this->e_EmpArry[i + 1];
            this->e_EmpNum--;
        }
        cout << "员工删除成功" << endl;
    }
    else
    {
        cout << "未找到员工" << endl;
    }
    system("pause");
    system("cls");
}

int employeeManager::employeeIsExist(int id)
{
    // 判断员工是否存在
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
    // 修改员工信息
    if (this->e_EmpNum == 0)
    {
        cout << "通讯录中无数据, 请添加信息" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请输入要修改的员工编号: " << endl;
    int id = 0;
    cin >> id;
    int index = employeeIsExist(id);
    if (index != -1)
    {
        // 删除在堆中的数据
        delete this->e_EmpArry[index];
        // 重新创建数据
        int id;
        string name;
        int select;
        cout << "请输入新员工编号: " << endl;
        cin >> id;

        cout << "请输入新员工姓名: " << endl;
        cin >> name;

        cout << "请输入新员工岗位: " << endl;
        cout << "1、普通职工" << endl;
        cout << "2、总经理" << endl;
        cout << "3、老板" << endl;
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
        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void employeeManager::findEmployee()
{
    // 查找员工
    if (this->e_EmpNum == 0)
    {
        cout << "通讯录中无数据, 请添加信息" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请输入查找方式:" << endl;
    cout << "1、通过姓名查找" << endl;
    cout << "2、通过员工编号查找" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // 姓名
        cout << "请输入员工姓名: " << endl;
        string name;
        cin >> name;
        // 查找标志
        bool flag = false;

        for (int i = 0; i < this->e_EmpNum; i++)
        {
            if (this->e_EmpArry[i]->w_Name == name)
            {
                cout << "查找成功, 信息为: " << endl;
                this->e_EmpArry[i]->showInfo();
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << "查无此人" << endl;
        }
    }
    else if(select == 2)
    {
      // 编号
        int id;
        cout << "请输入员工编号: " << endl;
        cin >> id;

        int index = employeeIsExist(id);
        if (index != -1)
        {
            cout << "查找成功, 信息为: " << endl;
            this->e_EmpArry[index]->showInfo();
        }
        else
        {
            cout << "查找失败" << endl;
        }
    }
    else
    {
        cout << "输入有误, 请重新输入" << endl;
    }

    system("pause");
    system("cls");
}

void employeeManager::saveData()
{
    // 保存数据
    if (this->e_EmpNum == 0)
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

    // 按行写入数据
    for (int i = 0; i < this->e_EmpNum; i++)
    {
        ofs << this->e_EmpArry[i]->w_ID << " "
            << this->e_EmpArry[i]->w_Name << " "
            << this->e_EmpArry[i]->w_DeptID << endl;
    }
    // 关闭文件
    ofs.close();
}

void employeeManager::loadData()
{
    // 加载数据
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int w_ID; // 工号
    string w_Name; // 姓名
    int w_DeptID; // 部门编号
    //cout << this->e_EmpNum << "构造方法" << endl;
    this->e_EmpArry = new Worker * [this->e_EmpNum];
    
    int index = 0;
    while (ifs >> w_ID && ifs >> w_Name && ifs >> w_DeptID)
    {
        Worker* worker = NULL;
        switch (w_DeptID)
        {
        case 1:
            worker = new Employee(w_ID, w_Name, w_DeptID);
            break;
        case 2:
            worker = new Manager(w_ID, w_Name, w_DeptID);
            break;
        case 3:
            worker = new Boss(w_ID, w_Name, w_DeptID);
            break;
        default:
            break;
        }
        this->e_EmpArry[index] = worker;
        index++;
    }
    ifs.close();
}

int employeeManager::getEmployeeNum()
{
    // 加载数据
    // 无数据源文件
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        //cout << "数据源文件不存在" << endl;
        this->e_EmpNum = 0;
        this->e_EmpArry = NULL;
        //this->e_FileIsEmpty = true;
        ifs.close();
        return -1;
    }
    // 有数据源文件但无数据
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //cout << "文件中无数据" << endl;
        this->e_EmpNum = 0;
        this->e_EmpArry = NULL;
        //this->e_FileIsEmpty = true;
        ifs.close();
        return -1;
    }
    // 有数据
    ifstream ifs_num;
    ifs_num.open(FILENAME, ios::in);
    int num = 0;
    int w_ID; // 工号
    string w_Name; // 姓名
    int w_DeptID; // 部门编号
    while (ifs_num >> w_ID && ifs_num >> w_Name && ifs_num >> w_DeptID)
    {
        num++;
    }
    ifs_num.close();
    //this->e_FileIsEmpty = false;
    return num;
}

void employeeManager::emptyEmployee()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::trunc);
    ofs.close();

    if (this->e_EmpArry != NULL)
    {
        for (int i = 0; i < this->e_EmpNum; i++)
        {
            delete this->e_EmpArry[i];
        }
        delete[] this->e_EmpArry;
        this->e_EmpNum = 0;
        this->e_EmpArry = NULL;
    }
    cout << "清除员工数据成功" << endl;
    system("pause");
    system("cls");
}
