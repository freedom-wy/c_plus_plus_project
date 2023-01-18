#include <fstream>
#include <iostream>
using namespace std;

// 写入文件
void test1()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);

    ofs << "姓名: 张三" << endl;
    ofs << "年龄: 18" << endl;
    ofs << "性别: 男" << endl;

    ofs.close();
}

// 读取文件
void test2()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 按行输出
    char buf[1024] = {0};
    while(ifs.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
    }

    ifs.close();

}

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
        virtual void getInfo() = 0;
};

class Person1: public Base
{
    public:
        Person1(int age)
        {
            char name[32] = "zhangsan";
            strcpy(this->name, name);
            this->age = age;
            cout << "Person1的构造方法" << endl;
        }
        ~Person1()
        {
            cout << "Person1的析构方法" << endl;
        }
        void getInfo()
        {
            cout << "姓名: " << this->name << " 年龄: " << this->age << endl;
        }
};

class Person2: public Base
{
    public:
        Person2(int age)
        {
            cout << "person2的构造方法" << endl;
            char name[32] = "lisi";
            strcpy(this->name, name);
            this->age = age;
        }
        ~Person2()
        {
            cout << "Person2的析构方法" << endl;
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
        Test()
        {
            cout << "Test类的构造方法" << endl;
            this->num = 2;
            this->array = new Base*[this->num];
        }
        ~Test()
        {
            cout << "test类的析构方法" << endl;
        }

        void handle()
        {
            for(int i=1;i<3;i++)
            {
                Base* base = NULL;
                if(i==1)
                {
                    base = new Person1(i);
                }
                else
                {
                    base = new Person2(i);
                }
                this->array[i-1] = base;
            }
        }
};


void test3()
{
    // 通过二进制形式写文件
    // Person p1;
    // char name[32] = "zhangsan";
    // p1.setName(name);
    // p1.setAge(18);
    // p1.showPerson();

    // char name[32] = "zhangsan";
    // Person p2 = Person(name, 18);
    // // p2.showPerson();
    // ofstream ofs;
    // ofs.open("person_binary.txt", ios::out | ios::binary);
    // ofs.write((const char *)&p2, sizeof(p2));
    // ofs.close();

    // 多态父类指针或引用指向子类对象
    // Person1 p1;
    // p1.setName("zhangsan");
    // p1.setAge(18);
    // doTest(p1);

    // Base* p2 = new Person2("lisi");
    // p2->setAge(19);
    // p2->getInfo();
}

void test4()
{
    // 通过二进制方式读取文件
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    // 按行输出
    // char buf[1024] = {0};
    // while(ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    ifs.close();

}

int main()
{
    test3();
    return 0;
}