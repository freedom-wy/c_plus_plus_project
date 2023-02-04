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

int main()
{
	test4();
	return 0;
}