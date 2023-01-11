#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test6()
{
    // 文件内容格式化 fprintf输出即为写文件 fscanf输入即为读文件
    struct heroInfo
    {
        char name[32]; //姓名
        int atk; // 攻击力
        int def; // 防御力
    };

    struct heroInfo heroArray[3] =
    {
        {"刘备", 20, 100},
        {"关羽", 90, 90},
        {"张飞", 80, 80}
    };

    // 遍历结构体数组
    // for(int i=0;i<3;i++)
    // {
    //     printf("英雄姓名: %s, 英雄攻击力: %d, 英雄防御力: %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
    // }

    // 将结构体数据写入文件
    FILE* f_write = fopen("hero.txt", "w");
    for (int i = 0; i < 3; i++)
    {
        fprintf(f_write, "[英雄姓名]%s [英雄攻击力]%d [英雄防御力]%d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
        // fprintf(f_write, "英雄姓名: %s, 英雄攻击力: %d, 英雄防御力: %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
    }

    fclose(f_write);
}

void test7()
{
    // 读取文件内容
    FILE* f_read = fopen("hero.txt", "r");
    struct heroInfo
    {
        char name[32]; //姓名
        int atk; // 攻击力
        int def; // 防御力
    };
    struct heroInfo heroArray[3];

    int i = 0;
    while (!feof(f_read))
    {
        // 读文件 [英雄姓名]刘备 [英雄攻击力]20 [英雄防御力]100
        // 英雄姓名: 刘备, 英雄攻击力: 20, 英雄防御力: 100
        fscanf(f_read, "[英雄姓名]%s [英雄攻击力]%d [英雄防御力]%d\n", heroArray[i].name, &heroArray[i].atk, &heroArray[i].def);
        // fscanf(f_read, "英雄姓名: %s, 英雄攻击力: %d, 英雄防御力: %d\n", heroArray[i].name, &heroArray[i].atk, &heroArray[i].def);
        i++;
    }
    printf("读取完成\n");
    for (int i = 0; i < 3; i++)
    {
        printf("结果为: 英雄姓名: %s, 英雄攻击力: %d, 英雄防御力: %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
    }
    fclose(f_read);
}

int main()
{
    test7();
    return 0;
}