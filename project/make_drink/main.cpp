#include <iostream>
using namespace std;

// 创建抽象类
class Base
{
    public:
        Base()
        {
            cout << "抽象类Base的构造方法" << endl;
        }
    public:
        virtual void shaoShui() = 0;
        virtual void fangYuanLiao() = 0;
        virtual void wait() = 0;
        virtual void daoRuBeiZhong() = 0;

    public:
        // 制作饮品
        void _do()
        {
            shaoShui();
            fangYuanLiao();
            wait();
            daoRuBeiZhong();
        }
    
    public:
        // 需要通过虚析构方法或纯虚析构, 解决通过父类指针释放子类对象
        // virtual ~Base()
        // {
        //     cout << "抽象类Base的析构方法" << endl;
        // }
        virtual ~Base()=0;

};

Base::~Base()
{
    cout << "抽象类的纯虚析构" << endl;
}

class Coffee: public Base
{
    public:
        Coffee()
        {
            cout << "子类coffee的构造方法" << endl;
        }

        Coffee(int a)
        {
            cout << "子类coffee的有参构造方法" << endl;
            c_A = new int(a);
        }

    public:
        int *c_A;
    public:
        void shaoShui()
        {
            cout << "烧农夫山泉" << endl;
        }
        void fangYuanLiao()
        {
            cout << "放入咖啡" << endl;
        }
        void wait()
        {
            cout << "搅拌均匀" << endl;
        }
        void daoRuBeiZhong()
        {
            cout << "倒入马克杯" << endl;
        }
    public:
        ~Coffee()
        {
            cout << "子类Coffee的析构方法" << endl;
            if (c_A != NULL)
            {
                delete c_A;
                c_A = NULL;
            }
        }

};

class Tea: public Base
{
    void shaoShui()
    {
        cout << "烧矿泉水" << endl;
    }
    void fangYuanLiao()
    {
        cout << "放入茶叶" << endl;
    }
    void wait()
    {
        cout << "搅拌均匀" << endl;
    }
    void daoRuBeiZhong()
    {
        cout << "倒入紫砂壶" << endl;
    }
};

void makeDrink(Base &b)
{
    b._do();
}


int main()
{
    // Coffee c;
    // makeDrink(c);

    // Tea t;
    // makeDrink(t);
    // int a = 10;
    // int &ref = a;
    // cout << a << endl;
    // cout << ref << endl;
    // ref = 100;
    // cout << a << endl;
    // cout << ref << endl;

    // Coffee c;
    // Base &b = c;
    // b._do();

    Base *b = new Coffee(1);
    b->_do();
    delete b;

    return 0;
}