#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "employeeManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main()
{
#if 0
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
            Person1(){}
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
        public:
            void handle()
            {
                num = 2;
                this->array = new Base*[2];
                for (int i = 0; i < 2; i++)
                {  
                    Base* base = NULL;
                    if (i == 0)
                    {
                        char name[32] = { "zhangsan" };
                        base = new Person1(name, i);
                    }
                    else
                    {
                        char name[32] = { "lisi" };
                        base = new Person2(name, i);
                    }
                    this->array[i] = base;
                }
            }
            void save()
            {
                ofstream ofs;
                ofs.open("test.txt", ios::out);
                for (int i = 0; i < num; i++)
                {
                    ofs << this->array[i]->name << " " << this->array[i]->age << endl;
                }
                ofs.close();
            }
            void load()
            {
                this->array = new Base * [2];
                int i = 0;
                ifstream ifs;
                ifs.open("test.txt", ios::in);
                char name[32];
                int age;
                while (ifs >> name && ifs >> age)
                {
                    Base* base = NULL;
                    if (age == 0)
                    {
                        base = new Person1(name, age);
                    }
                    else
                    {
                        base = new Person2(name, age);
                    }
                    this->array[i] = base;
                    i++;
                }

                for (int i = 0; i < 2; i++)
                {
                    this->array[i]->getInfo();
                }
            }
    };

    Test t1;
    //t1.handle();
    //t1.save();
    t1.load();

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
                em.emptyEmployee();
				break;
			case 7:
				em.saveData();
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