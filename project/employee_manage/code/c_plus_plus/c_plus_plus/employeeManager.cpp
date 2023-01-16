#include "employeeManager.h"

employeeManager::employeeManager()
{
	// 构造具体实现
    // 初始化人数和指针
    this->e_EmpNum = 0;
    this->e_EmpArry = NULL;
}

employeeManager::~employeeManager()
{
	// 析构具体实现
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
        
        // 创建指针数组
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