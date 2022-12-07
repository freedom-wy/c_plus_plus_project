#include <iostream>
using namespace std;

// 定义点类
class Point
{
    // 定义点的坐标
    private:
        int p_x;
        int p_y;
    public:
        // 定义点的方法
        void setX(int x)
        {
            p_x = x;
        }
        int getX()
        {
            return p_x;
        }
        void setY(int y)
        {
            p_y = y;
        }
        int getY()
        {
            return p_y;
        }
};

// 定义圆类
class Circle
{
    private:
        // 半径
        int c_r;
        // 圆心
        Point center;
    public:
        // 设置半径
        void setR(int r)
        {
            c_r = r;
        }
        int getR()
        {
            return c_r;
        }

        // 设置圆心
        void setCenter(Point p)
        {
            center = p;
        }

        Point getCenter()
        {
            return center;
        }
};

// 判断点在圆外, 圆上, 圆内
void isInCircle(Circle &c, Point &p)
{
    // 计算两点之间的距离 平方
    int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX()-p.getX())+
    (c.getCenter().getY()-p.getY())*(c.getCenter().getY()-p.getY());

    // 计算半径的平方
    int r_distance = c.getR()*c.getR();

    // 判断关系
    if (distance == r_distance)
    {
        cout << "点在圆上" << endl;
    }else if (distance < r_distance)
    {
        cout << "点在圆内" << endl;
    }else
    {
        cout << "点在圆外" << endl;
    }
    
}

int main()
{   
    // 实例化一个圆
    Circle c;
    // 设置半径
    c.setR(10);
    // 实例化圆心
    Point center;
    // 设置圆心坐标
    center.setX(10);
    center.setY(0);
    // 设置圆心
    c.setCenter(center);

    // 创建点
    Point p;
    p.setX(10);
    p.setY(9);

    // 判断关系
    isInCircle(c, p);
    return 0;
}