#include <iostream>
using namespace std;

// 多态

class Animal
{
    public:
        virtual void speak()
        {
            cout << "动物在说话" << endl;
        }
};

class Cat :public Animal
{
    public:
        void speak() //子类重写父类中的虚函数
        {
            cout << "猫在说话" << endl;
        }
};

// 父类指针或引用指向子类对象
void doSpeak(Animal &animal)
{
    animal.speak();
}

void test1()
{
    // Cat cat; // 父类指针或引用指向子类对象
    // doSpeak(cat);
    Animal* cat = new Cat();
    cat->speak();
}

int main()
{
    test1();
    return 0;
}