#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "employeeManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main()
{
#if 1
	/*Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;*/
	/*int array[2] = { 1, 2 };
	for (int i = 0; i < 2; i++)
	{
		cout << "元素的值为: " << array[i] << endl;
	}*/

	/*int a = 1;
	int b = 2;
	int* array[2] = { &a, &b };
	for (int i = 0; i < 2; i++)
	{
		cout << "元素值为: " << *array[i] << endl;
	}*/

	/*int* array[5];
	for (int i = 0; i < 5; i++)
	{
		array[i] = new int(i);
	}
	delete array[0];
	for (int i = 0; i < sizeof(array) / sizeof(int*); i++)
	{
		cout << "元素的值为: " << *array[i] << endl;
	}*/

    class Base
    {
        public:
            char name[32];
            int age;
        public:
            Base()
            {
                cout << "Base的构造方法" << endl;
            }
            virtual ~Base()
            {
                cout << "Base的析构方法" << endl;
            }
            // virtual ~Base() = 0;
            virtual void setAge(int age) = 0;
            virtual void getInfo() = 0;
    };

    class Person1 : public Base
    {
        public:
            Person1(char* name, int age)
            {
                strcpy(this->name, name);
                this->age = age;
                cout << "Person1的构造方法" << endl;
            }
            ~Person1()
            {
                cout << "Person1的析构方法" << endl;
            }
            void setAge(int age)
            {
                this->age = age;
            }
            void setName(char* name)
            {
                strcpy(this->name, name);
            }
            void getInfo()
            {
                cout << "姓名: " << this->name << " 年龄: " << this->age << endl;
            }
    };

    class Person2 : public Base
    {
        public:
            Person2(char* name, int age)
            {
                cout << "person2的构造方法" << endl;
                strcpy(this->name, name);
                this->age = age;
            }
            ~Person2()
            {
                cout << "Person2的析构方法" << endl;
            }
            void setAge(int age)
            {
                this->age = age;
            }
            void getInfo()
            {
                cout << "姓名: " << this->name << " 年龄: " << this->age << endl;
            }
    };


    class Test
    {
    public:
        int num;
        Base** array;
    };

    Test t1;
    //t1.num = 2;
    //// 在堆区创建数据, 数据为抽象类Base的指针, 因此使用**接
    //t1.array = new Base * [t1.num];
    //char name1[32] = { "zhangsan" };
    //t1.array[0] = new Person1(name1, 18);
    //char name2[32] = { "lisi" };
    //t1.array[1] = new Person2(name2, 20);

    //// 写入文件
    //ofstream ofs;
    //ofs.open("test.txt", ios::out);
    //ofs.write((const char*)&t1, sizeof(t1));
    //ofs.close();

    ifstream ifs;
    ifs.open("test.txt", ios::in);
    ifs.read((char*)&t1, sizeof(t1));
    for (int i = 0; i < t1.num; i++)
    {
        t1.array[i]->getInfo();
    }


#else
	employeeManager em;
	int choice = 0;
	while (1)
	{
		em.showMenu();
		cout << "请输入菜单编号: " << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				// 添加联系人
				em.addEmployee();
				break;
			case 2:
				em.showEmployee();
				break;
			case 3:
				em.delEmployee();
				break;
			case 4:
				em.findEmployee();
				break;
			case 5:
				em.modifyEmployee();
				break;
			case 6:
				break;
			case 7:
				//em.saveData();
				em.exitProgram();
				break;
			default:
				cout << "输入有误, 重新输入" << endl;
				system("pause");
				system("cls");
				break;
		}
	}
#endif
	return 0;
}