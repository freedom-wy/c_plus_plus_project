#include <iostream>
using namespace std;

int main(){
    // cout << "hello world" << endl;
    // int score = 0;
    // cout << "请输入你的分数: " << endl;
    // cin >> score;
    // cout << "你的分数为: " << score << endl;
    // if (score > 600)
    // {
    //     cout << "恭喜你考上了" << endl;
    // } 
    // else if (score > 500)
    // {
    //     cout << "成绩不错" << endl;
    // }
    // else
    // {
    //     cout << "很遗憾没考上" << endl;
    // }
    // 三目运算符
    // int a = 1;
    // int b = 2;
    // int c = 0;
    // c = (a > b ? a :b);
    // cout << "c的值为: " << c << endl;
    // switch条件选择
    cout << "请给电影打分: " << endl;
    int score = 0;
    cin >> score;
    cout << "您的打分为: " << score << endl;
    switch (score)
    {
    case 10:
        cout << "电影优秀!" << endl;
        break;
    case 9:
        cout << "电影一般!" << endl;
        break;
    default:
        cout << "电影不行!!" << endl;
        break;
    }
    return 0;
}