#include <iostream>
using namespace std;

// class Building
// {
//     // 全局函数做友元
//     friend void goodGay(Building &building);
//     private:
//         string b_BedRoom;
//         string b_SittingRoom;
    
//     public:
//         // 构造方法
//         Building()
//         {
//             this->b_BedRoom = "卧室";
//             this->b_SittingRoom = "客厅";
//         }
// };

// void goodGay(Building &building)
// {
//     cout << "好基友正在访问: " << building.b_BedRoom << endl;
//     cout << "好基友正在访问: " << building.b_SittingRoom << endl;
// }

// void test01()
// {
//     Building b;
//     goodGay(b);
// }

// 声明类
class Building;

class goodGay
{
    private:
        Building *b;
    public:
        // 声明goodGay构造函数, 类外实现
        goodGay();
        void visit();
};


class Building
{
    // 类做友元
    friend class goodGay;
    private:
        string b_SittingRoom;
        string b_BedRoom;
        int age;
    
    public:
        Building(int age)
        {
            this->b_BedRoom = "卧室";
            this->b_SittingRoom = "客厅";
            this->age = age;
        }
};

// 类外实现构造函数
// Building::Building(int age)
// {
//     this->b_BedRoom = "卧室";
//     this->b_SittingRoom = "客厅";
//     this->age = age;
// }

goodGay::goodGay()
{
    this->b = new Building(10);
}

void goodGay::visit()
{
    cout << "好基友正在访问: " << b->b_SittingRoom << endl;
}

void test02()
{
    goodGay gg;
    gg.visit();
}


int main()
{
    // 全局函数做友元
    // test01();
    test02();
    return 0;
}