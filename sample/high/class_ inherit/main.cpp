#include <iostream>
using namespace std;

// 基类
class Base
{
    public:
        void haha()
        {
            cout << "公共方法" << endl;
        }
};

class T1: public Base
{
    public:
        void test1()
        {
            cout << "t1的方法" << endl;
        }
};

class T2: public Base
{

};


int main()
{
    T1 t1;
    t1.haha();
    t1.test1();

    T2 t2;
    t2.haha();
    return 0;
}