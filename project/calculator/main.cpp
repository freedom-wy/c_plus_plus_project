#include <iostream>
using namespace std;

// 通过多态方式实现计算器

class AbstractCalculator
{
    public:
        int num1;
        int num2;

    public:
        virtual int getResult()
        {
            return 0;
        }
};

class AddCalculator: public AbstractCalculator
{
    public:
        int getResult()
        {
            return num1 + num2;
        }
};

class SubCalculator: public AbstractCalculator
{
    public:
        int getResult()
        {
            return num1 - num2;
        }
};

void test1(AbstractCalculator &abc)
{
    // // 父类指针或引用指向子类对象
    // AbstractCalculator *abc = new AddCalculator();
    // abc->num1 = 10;
    // abc->num2 = 20;
    // cout << "加法结果: " << abc->getResult() << endl;
    // delete abc;
    cout << "加法结果: " << abc.getResult() << endl;
}

int main()
{
    // test1();
    AddCalculator add;
    add.num1 = 10;
    add.num2 = 20;
    test1(add);
    return 0;
}