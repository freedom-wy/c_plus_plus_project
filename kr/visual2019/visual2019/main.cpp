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
	int* arr = new int[10]; // 在堆区开辟数组
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	// 删除堆区数组
	delete[] arr;

	/*for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}*/ // 删除数组对象后无法访问
}

// 值传递
void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 地址传递
void mySwap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 引用传递
void mySwap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

class Person {
public:
	// 构造和析构不写返回值也不写void, 函数名称与类名相同
	Person(string name, int age) 
	{
		cout << "构造方法" << endl;
		this->name = name;
		this->age = new int(age);
	}
	Person(const Person& p)
	{
		cout << "拷贝构造函数" << endl;
		this->name = p.name;
		this->age = new int(*(p.age));
	}
	~Person()
	{
		if (this->age != NULL)
		{
			cout << "析构" << endl;
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
	static int m_A; //静态成员变量，类内声明，类外初始化
private:
	string name;
	int* age;
};

int Person::m_A = 10;

void test2()
{
	Person p1 = Person("哈哈", 18);
	p1.m_A = 100;
	cout << "姓名: " << p1.getName() << ", 年龄: " << p1.getAge() << ", m_A的值为: " << p1.m_A << endl;
	Person p2 = Person(p1); // 调用拷贝构造方法
	p2.m_A = 200;
	cout << "姓名: " << p2.getName() << ", 年龄: " << p2.getAge() << ", m_A的值为: " << p2.m_A << endl;
	cout << "通过类名访问m_A的值: " << Person::m_A << endl;
}


int main() {
	//int* p1 = func1();
	//cout << "不要返回局部变量的地址" << *p1 << endl; // 10
	//cout << "不要返回局部变量的地址" << *p1 << endl; // 2065865096
	//int* p2 = func2();
	//cout << "返回堆区数据" << *p2 << endl;
	//delete p2;
	// cout << "返回堆区数据" << *p2 << endl; // 删除对象后无法查看内存指向数据
	// test1();
	/*int a = 10;
	int b = 20;
	mySwap01(a, b);
	cout << "交换后的a: " << a << ", 交换后的b: " << b << endl;*/
	test2();
	cout << "hello world" << endl;
	return 0;
}