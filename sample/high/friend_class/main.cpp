#include <iostream>
using namespace std;


class Building
{
    // 设置类的友元
    friend class goodGay;
    public:
        string b_sittingRoom; // 客厅
    
    private:
        string b_bedroom; // 卧室
    public:
        Building()
        {
            b_sittingRoom = "客厅";
            b_bedroom = "卧室";
        }
};

class goodGay
{
    private:
        // Building *building;
        Building building;
    public:
        // 声明两个成员方法
        // goodGay();
        void visit();
};

// 实现Building类的Building初始化方法
// Building::Building()
// {
//     b_sittingRoom = "客厅";
//     b_bedroom = "卧室";
// }

// goodGay::goodGay()
// {
//     building = new Building;
// }

void goodGay::visit()
{
    // cout << "好基友正在访问" << building->b_sittingRoom << endl;
	// cout << "好基友正在访问" << building->b_bedroom << endl;

    cout << "好基友正在访问" << building.b_sittingRoom << endl;
	cout << "好基友正在访问" << building.b_bedroom << endl;

}

void test1()
{
    goodGay gg;
    gg.visit();
}

int main()
{
    test1();
    return 0;
}