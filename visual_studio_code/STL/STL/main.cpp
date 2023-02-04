#include <iostream>
#include <vector>
using namespace std;

void test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);

	/*vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	while (pBegin != pEnd)
	{
		cout << "����Ϊ: " << *pBegin << endl;
		pBegin++;
	}*/

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����Ϊ: " << *it << endl;
	}
}

void test2()
{
	// �Զ�����������
	class Person
	{
	public:
		string name;
		int age;
	public:
		Person(string name, int age)
		{
			this->name = name;
			this->age = age;
		}
	};

	//vector<Person> v;
	//// �����Զ������
	//Person p1("����", 1);
	//Person p2("����", 2);

	//// ��������
	//v.push_back(p1);
	//v.push_back(p2);

	//// ����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "����Ϊ: " << (*it).name << ", ����Ϊ: " << (*it).age << endl;
	//}
	
	// ����ָ��
	vector<Person*> v;
	Person p1("����", 3);
	Person p2("����", 4);
	v.push_back(&p1);
	v.push_back(&p2); 

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����Ϊ: " << (*it)->name << ", ����Ϊ: " << (*it)->age << endl;
	}



}

void test3()
{
	// ��������
	class Person
	{
	private:
		string name;
		int* age;
	public:
		Person(string name, int age)
		{
			cout << "���췽��" << endl;
			this->name = name;
			this->age = new int(age);
		}
		Person(const Person& p)
		{
			cout << "��������" << endl;
			//this->age = p.age;
			this->age = new int(*(p.age)); // ���
			this->name = p.name;
		}
		~Person()
		{
			cout << "��������" << endl;
			delete this->age;
			this->age = NULL;
		}

		void showInfo()
		{
			cout << "����Ϊ: " << this->name << ", ����Ϊ: " << *(this->age) << endl;
		}
	};

	Person p1("����", 1);
	Person p2(p1);
	p2.showInfo();
}

void test4()
{
	string s1;
	cout << "s1��ֵΪ: " << s1 << endl;
}

int main()
{
	test4();
	return 0;
}