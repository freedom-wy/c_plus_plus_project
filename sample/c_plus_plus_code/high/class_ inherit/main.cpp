#include <iostream>
using namespace std;

// 基类
class Base
{
    public:
        void haha()
        {
            cout << "BASE公共方法" << endl;
        }

        void haha(int a)
        {
            cout << "基类方法输入的值为: " << a << endl;
        }
    
    public:
        int b_A;
    protected:
        int b_B;
    private:
        int b_C;
};

class T1: public Base
{
    public:
        void test1()
        {
            cout << "t1的方法" << endl;
        }

        void haha()
        {
            cout << "T1公共方法" << endl;
        }


    
    public:
        void test2()
        {
            b_A = 100;
            b_B = 200;
            // b_c = 300; // 私有权限无法访问
        }
};

class T2: protected Base
{
    public:
        void test2()
        {
            cout << "test2方法" << endl;
            b_A = 100;
            b_B = 200;
            // b_C = 300; // 私有权限无法访问
        }

};

class T3: private Base
{
    public:
        void test2()
        {
            b_A = 100;
            b_B = 200;
            // b_C = 300;
        }

};


int main()
{
    T1 t1;
    t1.haha();
    t1.Base::haha(); // 调用父类方法
    t1.Base::haha(1);
    // t1.test1();
    // t1.test2();

    // T2 t2;
    // t2.haha(); // 继承过来后为protected权限
    // t2.test2(); // T2类自己的public权限

    // T3 t3;
    // t3.haha(); // 继承过来后为private权限
    // t3.test2();
}