#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

#define SCOREFILENAME "score.txt"

void showMenu()
{
    printf("1 记录比赛分数\n");
    printf("2 查看比赛分数\n");
    printf("3 清空比赛分数\n");
    printf("4 退出程序\n");
}

void addScore()
{
    // 打开一个文件, 以追加模式打开
    FILE* f_write = fopen(SCOREFILENAME, "a");
    int score = 0;
    scanf("%d", &score);
    fprintf(f_write, "%d\n", score);
    fclose(f_write);
    printf("记录比赛成绩成功\n");
}

void showScore()
{
    // 查看分数前判断下文件中是否有内容
    // 读取分数文件
    FILE* f_read = fopen(SCOREFILENAME, "r");
    while (!feof(f_read))
    {
        int score = 0;
        fscanf(f_read, "%d\n", &score);
        printf("比赛分数为: %d\n", score);
    }
    fclose(f_read);
}

void exitProgram()
{
    exit(0);
}

void clearScore()
{
    FILE* f_write = fopen(SCOREFILENAME, "w");
    fclose(f_write);
}

// void pressKey()
// {
//     char ch = 'a';
//     scanf("按任意键继续...%c", &ch);
// }

void test1()
{
    // 1、欢迎界面
    // 2、记录比赛分数
    // 3、查看比赛分数
    // 4、清空比赛分数
    // 5、退出程序
    int select = 0;
    while (1)
    {
        // 显示欢迎界面菜单
        showMenu();

        printf("请输入功能序号\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("请输入比赛分数\n");
            addScore();
            // pressKey();
            system("pause");
            system("cls");
            break;
        case 2:
            printf("查看比赛分数\n");
            showScore();
            system("pause");
            system("cls");;
            break;
        case 3:
            printf("清空比赛分数\n");
            clearScore();
            system("pause");
            system("cls");
            break;
        case 4:
            printf("退出程序\n");
            exitProgram();
            system("pause");
            system("cls");
            break;
        default:
            printf("输入有误, 请重新输入\n");
            system("pause");
            system("cls");
            break;
        }
    }
}


int main()
{
    test1();
    return 0;
}