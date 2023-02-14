#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入 key(部门编号) value(员工)
分部门显示员工信息

创建10名员工，放到vector中
遍历vector容器，取出每个员工，进行随机分组
分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
分部门显示员工信息
*/

// 通过枚举定义数据
enum GROUP
{
	CEHUA = 0,
	MEISHU,
	YANFA
};

class Employee
{
public:
	string name;
	int salary;
	Employee(string name, int salary)
	{
		this->name = name;
		this->salary = salary;
	}
};

void PrintEmployeeInfo(vector<Employee>& v)
{
	for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "员工姓名: " << it->name << ", 员工工资: " << it->salary << endl;
	}
}

void PrintEmployeeGroupInfo(multimap<int, Employee>& m)
{
	/*for (multimap<int, Employee>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "分组: " << it->first << ", 姓名: " << it->second.name << endl;
	}*/
	cout << "策划组: " << endl;
	multimap<int, Employee>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
	}
	cout << "美术组: " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
	}
	cout << "研发组: " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
	}
}

void SetEmployeeGroup(vector<Employee>& v, multimap<int, Employee>& m)
{
	// 给员工分组
	for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "员工姓名: " << it->name << ", 员工工资: " << it->salary << endl;
		int deptId = rand() % 3; // 0 1 2
		m.insert(make_pair(deptId, *it));
	}
}

void test1()
{
	srand((unsigned int)time(NULL));
	vector<Employee> v1;
	string sub_name = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "员工";
		name += sub_name[i];

		int salary = rand() % 10000 + 10000; // 10000 ~ 19999
		Employee e(name, salary);
		v1.push_back(e);
	}
	
	//PrintEmployeeInfo(v1);
	multimap<int, Employee> m1;
	SetEmployeeGroup(v1, m1);
	PrintEmployeeGroupInfo(m1);
}

void test2()
{
	// 创建枚举类型, 如不赋初始值, 则从0开始, 每个变量递增, 定义后不可修改, 相当于定义常量
	enum PUKER
	{
		HONGTAO = 100,
		HEITAO,
		MEIHUA,
		FANGPIAN
	};

	/*enum PUKER puker;
	puker = HONGTAO;
	printf("红桃的值为: %d\n", puker);*/
	printf("黑桃的值为: %d\n", HEITAO);
	printf("梅花的值为: %d\n", MEIHUA);
	printf("方片的值为: %d\n", FANGPIAN);
}


int main()
{
	test1();
	return 0;
}