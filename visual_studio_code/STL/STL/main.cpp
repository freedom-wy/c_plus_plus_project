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
		cout << "数据为: " << *pBegin << endl;
		pBegin++;
	}*/

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "数据为: " << *it << endl;
	}
}

void test2()
{
	// 自定义数据类型
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
	//// 创建自定义对象
	//Person p1("张三", 1);
	//Person p2("李四", 2);

	//// 放入容器
	//v.push_back(p1);
	//v.push_back(p2);

	//// 遍历
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名为: " << (*it).name << ", 年龄为: " << (*it).age << endl;
	//}
	
	// 放入指针
	vector<Person*> v;
	Person p1("王五", 3);
	Person p2("赵六", 4);
	v.push_back(&p1);
	v.push_back(&p2); 

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名为: " << (*it)->name << ", 年龄为: " << (*it)->age << endl;
	}



}

void test3()
{
	// 拷贝构造
	class Person
	{
	private:
		string name;
		int* age;
	public:
		Person(string name, int age)
		{
			cout << "构造方法" << endl;
			this->name = name;
			this->age = new int(age);
		}
		Person(const Person& p)
		{
			cout << "拷贝构造" << endl;
			//this->age = p.age;
			this->age = new int(*(p.age)); // 深拷贝
			this->name = p.name;
		}
		~Person()
		{
			cout << "析构函数" << endl;
			delete this->age;
			this->age = NULL;
		}

		void showInfo()
		{
			cout << "姓名为: " << this->name << ", 年龄为: " << *(this->age) << endl;
		}
	};

	Person p1("张三", 1);
	Person p2(p1);
	p2.showInfo();
}

void test4()
{
	string s1;
	cout << "s1的值为: " << s1 << endl;
	// 将C语言风格的字符串转换为c++的字符串
	const char* str = "hello world";
	cout << "类型为: " << typeid(str).name() << endl;
	string s2(str);
	cout << "字符串为: " << s2 << ", 类型为: " << typeid(s2).name() << endl;
	string s3(s2);
	cout << "调用了拷贝构造函数: " << s3 << endl;

	string s4 = "hello world";
	int pos = s4.find("a"); // 查找到为索引位置, 找不到为-1
	cout << "索引位置为: " << pos << endl;

	string s5 = "hello world";
	s5.replace(1, 2, "abcdefg"); // replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
	cout << "替换后的结果为: " << s5 << endl;

	string s6 = "hello world";
	string s7 = "hello world";
	int value = s6.compare(s7); // 等于0为字符串相等
	cout << "比较结果为: " << value << endl;

	// 字符串遍历
	string s8 = "hello world";
	//for (int i = 0; i < s8.size(); i++) //字符串.size()返回字符串大小
	//{
	//	cout << s8[i] << endl;
	//}
	for (int i = 0; i < s8.size(); i++)
	{
		cout << s8.at(i) << endl;
	}

	s8[0] = 'a';
	s8.at(1) = 'b';
	cout << "字符串结果为: " << s8 << endl;

	string s9 = "hello world";
	s9.insert(1, "abc");
	cout << "字符串结果为: " << s9 << endl;
	s9.erase(1, 3);
	cout << "字符串结果为: " << s9 << endl;

	string email = "test@test.com";
	int pos1 = email.find("@"); // 找到字符串索引
	string username = email.substr(0, pos1);
	cout << "用户名为: " << username << endl;
}

int main()
{
	test4();
	return 0;
}