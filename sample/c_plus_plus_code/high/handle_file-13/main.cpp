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

class Person
{
    public:
        char name[32];
        int age;
    
    public:
        Person()
        {
            cout << "无参构造法" << endl;
        }
        Person(char* name, int age)
        {
            cout << "有参构造法" << endl;
            strcpy(this->name, name);
            this->age = age;
        }
        ~Person()
        {
            cout << "析构方法" << endl;
        }
    
    public:
        void setName(char* name)
        {
            strcpy(this->name, name);
        }
        
        void setAge(int age)
        {
            this->age = age;
        }

        void showPerson()
        {
            cout << "姓名为: " << name << " 年龄为: " << age << endl;
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

    char name[32] = "zhangsan";
    Person p2 = Person(name, 18);
    // p2.showPerson();
    ofstream ofs;
    ofs.open("person_binary.txt", ios::out | ios::binary);
    ofs.write((const char *)&p2, sizeof(p2));
    ofs.close();
    
}

void test4()
{
    // 通过二进制方式读取文件
    ifstream ifs;
    ifs.open("person_binary.txt", ios::in|ios::binary);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    Person p;
    ifs.read((char*)&p, sizeof(p));
    cout << "姓名: " << p.name << " 年龄: " << p.age << endl;
}

int main()
{
    test4();
    return 0;
}