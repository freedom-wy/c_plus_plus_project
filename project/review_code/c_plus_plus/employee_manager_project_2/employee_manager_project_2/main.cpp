#include <iostream>
#include "employeeManager.h"
using namespace std;

/*
1、创建基类, 包含成员属性(id, name, 部门id), 显示员工信息成员方法，虚析构方法
2、创建员工类集成基类, 员工类有参构造方法, 析构方法, 实现抽象基类的方法
3、创建员工管理类, 成员方法包含在堆区的数组, 员工数量, 构造方法中对员工信息进行初始化, 析构方法中删除堆区数据
4、员工管理类 成员方法 添加员工 展示员工信息, 保存员工信息到文件, 从文件中加载员工信息
*/

int main()
{
	EmployeeManager* em = new EmployeeManager();
	while (true)
	{
		int select = 0;
		cout << "请输入功能编号: " << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "添加员工" << endl;
			em->addEmployee();
			break;
		case 2:
			cout << "展示员工信息" << endl;
			em->showEmployee();
			break;
		case 3:
			cout << "退出程序" << endl;
			delete em;
			exit(0);
		default:
			break;
		}
	}
}