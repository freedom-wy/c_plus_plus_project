#include "employeeManager.h"
/*
需求:
1、展示菜单
2、添加联系人
3、展示联系人
4、删除联系人
5、查找联系人
6、修改联系人
7、清空联系人
8、保存联系人和加载联系人
9、退出程序
*/

/*
过程:
创建一个基类，成员属性 工号、姓名、部门编号，成员方法 展示员工信息，展示员工title
1、员工类
2、管理层类
3、老板类
4、员工管理类
5、主文件
*/

int main()
{
	employeeManager em;
	int choice = 0;
	while (1)
	{
		em.showMenu();
		cout << "请输入菜单号: " << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				// 添加员工信息
				cout << "添加员工信息" << endl;
				em.addEmployee();
				break;
			case 2:
				cout << "显示员工信息" << endl;
				em.showEmployee();
				break;
			case 3:
				cout << "删除员工" << endl;
				break;
			case 4:
				cout << "查找员工" << endl;
				break;
			case 5:
				cout << "修改员工" << endl;
				break;
			case 6:
				cout << "清空员工" << endl;
				break;
			case 7:
				em.saveData();
				em.exitProgram();
				break;
			default:
				cout << "输入有误, 请重新输入" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
}