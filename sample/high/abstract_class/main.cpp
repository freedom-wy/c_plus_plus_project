#include <iostream>
using namespace std;

// 创建抽象类
class Base
{
    public:
        // 纯虚函数
        virtual void test1() = 0;
};

class Son: public Base
{
    public:
        void test1()
        {
            cout << "Son类重写的test1方法" << endl;
        }

};


int main()
{
    Base * b = new Son;
    b->test1();
    return 0;
}