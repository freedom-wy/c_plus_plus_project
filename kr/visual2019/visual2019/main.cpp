#include <iostream>
using namespace std;


int* func1()
{
	int a = 10;
	return &a;
}

int* func2()
{
	int* b = new int(10);
	return b;
}

void test1()
{
	int* arr = new int[10]; // �ڶ�����������
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	// ɾ����������
	delete[] arr;

	/*for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}*/ // ɾ�����������޷�����
}

// ֵ����
void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ��ַ����
void mySwap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ���ô���
void mySwap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

class Person {
public:
	// �����������д����ֵҲ��дvoid, ����������������ͬ
	Person(string name, int age) 
	{
		cout << "���췽��" << endl;
		this->name = name;
		this->age = new int(age);
	}
	Person(const Person& p)
	{
		cout << "�������캯��" << endl;
		this->name = p.name;
		this->age = new int(*(p.age));
	}
	~Person()
	{
		if (this->age != NULL)
		{
			cout << "����" << endl;
			delete this->age;
		}
	}

	string getName()
	{
		return this->name;
	}

	int getAge()
	{
		return *(this->age);
	}
public:
	static int m_A; //��̬��Ա���������������������ʼ��
private:
	string name;
	int* age;
};

int Person::m_A = 10;

void test2()
{
	Person p1 = Person("����", 18);
	p1.m_A = 100;
	cout << "����: " << p1.getName() << ", ����: " << p1.getAge() << ", m_A��ֵΪ: " << p1.m_A << endl;
	Person p2 = Person(p1); // ���ÿ������췽��
	p2.m_A = 200;
	cout << "����: " << p2.getName() << ", ����: " << p2.getAge() << ", m_A��ֵΪ: " << p2.m_A << endl;
	cout << "ͨ����������m_A��ֵ: " << Person::m_A << endl;
}


int main() {
	//int* p1 = func1();
	//cout << "��Ҫ���ؾֲ������ĵ�ַ" << *p1 << endl; // 10
	//cout << "��Ҫ���ؾֲ������ĵ�ַ" << *p1 << endl; // 2065865096
	//int* p2 = func2();
	//cout << "���ض�������" << *p2 << endl;
	//delete p2;
	// cout << "���ض�������" << *p2 << endl; // ɾ��������޷��鿴�ڴ�ָ������
	// test1();
	/*int a = 10;
	int b = 20;
	mySwap01(a, b);
	cout << "�������a: " << a << ", �������b: " << b << endl;*/
	test2();
	cout << "hello world" << endl;
	return 0;
}