#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include<algorithm>

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
	// ��C���Է����ַ���ת��Ϊc++���ַ���
	const char* str = "hello world";
	cout << "����Ϊ: " << typeid(str).name() << endl;
	string s2(str);
	cout << "�ַ���Ϊ: " << s2 << ", ����Ϊ: " << typeid(s2).name() << endl;
	string s3(s2);
	cout << "�����˿������캯��: " << s3 << endl;

	string s4 = "hello world";
	int pos = s4.find("a"); // ���ҵ�Ϊ����λ��, �Ҳ���Ϊ-1
	cout << "����λ��Ϊ: " << pos << endl;

	string s5 = "hello world";
	s5.replace(1, 2, "abcdefg"); // replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ���
	cout << "�滻��Ľ��Ϊ: " << s5 << endl;

	string s6 = "hello world";
	string s7 = "hello world";
	int value = s6.compare(s7); // ����0Ϊ�ַ������
	cout << "�ȽϽ��Ϊ: " << value << endl;

	// �ַ�������
	string s8 = "hello world";
	//for (int i = 0; i < s8.size(); i++) //�ַ���.size()�����ַ�����С
	//{
	//	cout << s8[i] << endl;
	//}
	for (int i = 0; i < s8.size(); i++)
	{
		cout << s8.at(i) << endl;
	}

	s8[0] = 'a';
	s8.at(1) = 'b';
	cout << "�ַ������Ϊ: " << s8 << endl;

	string s9 = "hello world";
	s9.insert(1, "abc");
	cout << "�ַ������Ϊ: " << s9 << endl;
	s9.erase(1, 3);
	cout << "�ַ������Ϊ: " << s9 << endl;

	string email = "test@test.com";
	int pos1 = email.find("@"); // �ҵ��ַ�������
	string username = email.substr(0, pos1);
	cout << "�û���Ϊ: " << username << endl;
}

void printVectorData(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printConstVectorData(const vector<int>& v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test5()
{
	// ��������
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVectorData(v1);

	vector<int>v2(v1.begin(), v1.end());
	printVectorData(v2);

	vector<int>v3(10, 100);
	printVectorData(v3);

	vector<int>v4(v3);
	printVectorData(v4);

	vector<int>v5;
	v5 = v4;
	printVectorData(v5);

	vector<int>v6;
	v6.assign(v1.begin(), v1.end());
	printVectorData(v6);

	if (v1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ: " << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ: " << v1.size() << endl;
	}

	v1.resize(15); // ������С, ������̬��չ
	cout << "v1������Ϊ: " << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ: " << v1.size() << endl;
	printVectorData(v1);

	/*v1.resize(2);
	cout << "v1������Ϊ: " << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ: " << v1.size() << endl;*/

	v1.pop_back();
	printVectorData(v1);

	v1.insert(v1.begin(), 100);
	printVectorData(v1);

	v1.erase(v1.begin());
	printVectorData(v1);

	/*v1.erase(v1.begin(), v1.end());*/
	v1.clear();
	printVectorData(v1);
}

void test6()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printConstVectorData(v1);

	vector<int>v2;
	for (int i = 100; i < 110; i++)
	{
		v2.push_back(i);
	}
	printConstVectorData(v2);

	v1.swap(v2);
	printConstVectorData(v1);
	printConstVectorData(v2);

}

void test7()
{
	vector<int>v1;
	v1.reserve(100000); // ��Ԥ���ռ�, ����30��
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])
		{
			p = &v1[0];
			num++;
		}
	}

	cout << "����Ϊ: " << num << endl;
}

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test8()
{
	deque<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printDeque(v1);

	v1.push_back(100);
	v1.push_front(200);
	printDeque(v1);
	v1.pop_back();
	v1.pop_front();
	printDeque(v1);

	v1.insert(v1.begin(), 100);
	printDeque(v1);

	deque<int>d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(50);
	d2.push_back(100);
	d2.push_back(1);
	d2.push_back(8);
	printDeque(d2);
	sort(d2.begin(), d2.end());
	printDeque(d2);

}

void test9()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << "ջ��СΪ" << s.size() << endl;
	while (!s.empty())
	{
		cout << "ջ��Ԫ��Ϊ" << s.top() << endl;
		s.pop();
	}
}

void test10()
{
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

	Person p1("��ɮ", 1);
	Person p2("�����", 2);
	Person p3("��˽�", 3);
	Person p4("ɳɮ", 4);

	queue<Person> q;
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while (!q.empty())
	{
		cout << "��ͷԪ������" << q.front().name << endl;
		cout << "��βԪ������" << q.back().name << endl;

		q.pop();
	}
}

int main()
{
	test10();
	return 0;
}