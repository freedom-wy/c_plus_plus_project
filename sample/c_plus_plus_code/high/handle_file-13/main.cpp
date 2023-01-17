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
        virtual void setAge(int age) = 0;
        virtual void getInfo() = 0;
};

class Person1: public Base
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

class Person2: public Base
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

void doTest(Base &b)
{
    b.getInfo();
}


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
    class Test
    {
        public:
            int num;
            Base** array;
    };

    Test t1;
    t1.num = 2;
    // 在堆区创建数据, 数据为抽象类Base的指针, 因此使用**接
    t1.array = new Base*[t1.num];
    char name1[32] = {"zhangsan"};
    t1.array[0] = new Person1(name1, 18);
    char name2[32] = {"lisi"};
    t1.array[1] = new Person2(name2, 20);

    // 写入文件
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs.write((const char*)&t1, sizeof(t1));
    ofs.close();
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

    class Test
    {
        public:
            int num;
            Base** array;
    };

    Test t1;

    // Person p;
    while(ifs.read((char*)&t1, sizeof(t1)))
    {
        // cout << "姓名: " << p.name << " 年龄: " << p.age << endl;
        for(int i=0;i<t1.num;i++)
        {
            t1.array[i]->getInfo();
        }
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
    test4();
    return 0;
}