#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ���߻����������з�
�����10��Ա�����䲿�ź͹���
ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
�ֲ�����ʾԱ����Ϣ

����10��Ա�����ŵ�vector��
����vector������ȡ��ÿ��Ա���������������
����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
�ֲ�����ʾԱ����Ϣ
*/

// ͨ��ö�ٶ�������
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
		cout << "Ա������: " << it->name << ", Ա������: " << it->salary << endl;
	}
}

void PrintEmployeeGroupInfo(multimap<int, Employee>& m)
{
	/*for (multimap<int, Employee>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "����: " << it->first << ", ����: " << it->second.name << endl;
	}*/
	cout << "�߻���: " << endl;
	multimap<int, Employee>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary << endl;
	}
	cout << "������: " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary << endl;
	}
	cout << "�з���: " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary << endl;
	}
}

void SetEmployeeGroup(vector<Employee>& v, multimap<int, Employee>& m)
{
	// ��Ա������
	for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "Ա������: " << it->name << ", Ա������: " << it->salary << endl;
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
		string name = "Ա��";
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
	// ����ö������, �粻����ʼֵ, ���0��ʼ, ÿ����������, ����󲻿��޸�, �൱�ڶ��峣��
	enum PUKER
	{
		HONGTAO = 100,
		HEITAO,
		MEIHUA,
		FANGPIAN
	};

	/*enum PUKER puker;
	puker = HONGTAO;
	printf("���ҵ�ֵΪ: %d\n", puker);*/
	printf("���ҵ�ֵΪ: %d\n", HEITAO);
	printf("÷����ֵΪ: %d\n", MEIHUA);
	printf("��Ƭ��ֵΪ: %d\n", FANGPIAN);
}


int main()
{
	test1();
	return 0;
}