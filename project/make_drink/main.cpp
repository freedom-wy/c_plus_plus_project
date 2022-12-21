#include <iostream>
using namespace std;

// 创建抽象类
class Base
{
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

};

class Coffee: public Base
{
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
    Coffee c;
    makeDrink(c);

    Tea t;
    makeDrink(t);
    return 0;
}