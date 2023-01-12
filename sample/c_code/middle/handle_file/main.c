#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test1()
{
    // 打开文件
    FILE* f_write = fopen("test1.txt", "a+");
    // FILE* f_read = fopen("test2.txt", "r"); // 打开一个不存在的文件
    if(f_write == NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    // 按字符写文件
    char buf[32] = "hello world";
    int i=0;
    while(buf[i] != 0)
    {
        // printf("字符为: %c\n", buf[i]);
        fputc(buf[i], f_write); // 按字符写文件
        i++;
    }
    // 关闭文件
    fclose(f_write);
}

void test2()
{
    // 打开文件
    FILE* f_read = fopen("test1.txt", "r");
    if(f_read == NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    // 读文件
    char c = 'a';
    while((c = fgetc(f_read))!= EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    // 关闭文件
    fclose(f_read);
}

void test3()
{
    // 文本录入器
    FILE* f_write = fopen("test2.txt", "w");
    if(f_write == NULL)
    {
        printf("文件打开失败\n");
        return;
    }

    // 接收键盘输入
    while(1)
    {
        char buf[1024] = {0};
        fgets(buf, sizeof(buf), stdin);
        // 判断是否输入了退出指令
        if(strncmp(buf, ":quit", 5) == 0)
        {
            break;
        }
        // 写入文件
        int i = 0;
        while(buf[i] !=0)
        {
            fputc(buf[i], f_write);
            i++;
        }
    }

    // 关闭文件
    fclose(f_write);
}

void test4()
{
    // 按行写入文件
    FILE* f_write = fopen("test3.txt", "w");
    if(f_write == NULL)
    {
        printf("文件打开失败");
        return;
    }
    char* buf[] = {"锄禾日当午\n", "汗滴禾下土\n", "谁知盘中餐\n", " \n", "粒粒皆辛苦\n"};
    for(int i=0;i<sizeof(buf)/sizeof(char*);i++)
    {
        fputs(buf[i], f_write);
    }
    fclose(f_write);
}

void test5()
{
    // 按行读文件
    FILE* f_read = fopen("test3.txt", "r");
    if(f_read == NULL)
    {
        printf("文件打开失败");
        return;
    }
// 自定义条件编译
#if 0    
    while(!feof(f_read))
    {
        char buf[1024] = {'0'};
        char* p = fgets(buf, sizeof(buf), f_read);
        if(p == NULL)
        {
            break;
        }
        buf[strlen(buf)-1] = '\0';
        printf("行内容: %s\n", buf);
        // printf("行内容: %s", buf);
    }
#else
    char buf[1024] = {0};
    while(fgets(buf, sizeof(buf), f_read))
    {
        buf[strlen(buf)-1] = '\0';
        printf("%s\n", buf);
    }
#endif

    fclose(f_read);
}

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
    for(int i=0;i<3;i++)
    {
        // fprintf(f_write, "[英雄姓名]%s [英雄攻击力]%d [英雄防御力]%d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
        fprintf(f_write, "英雄姓名: %s, 英雄攻击力: %d, 英雄防御力: %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
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
    while(!feof(f_read))
    {
        // 读文件 [英雄姓名]刘备 [英雄攻击力]20 [英雄防御力]100
        // 英雄姓名: 刘备, 英雄攻击力: 20, 英雄防御力: 100
        // fscanf(f_read, "[英雄姓名]%s [英雄攻击力]%d [英雄防御力]%d\n", heroArray[i].name, &heroArray[i].atk, &heroArray[i].def);
        // 遇到逗号停止
        fscanf(f_read, "英雄姓名: %[^,], 英雄攻击力: %d, 英雄防御力: %d\n", heroArray[i].name, &heroArray[i].atk, &heroArray[i].def);
        i++;
    }
    printf("读取完成\n");
    for(int i = 0;i<3;i++)
    {
        printf("结果为: 英雄姓名: %s, 英雄攻击力: %d, 英雄防御力: %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
    }
    fclose(f_read);
}

void test8()
{
    char buf[32];
    scanf("%s", buf); // 输入helloworld可以正常输出, hello world只能输出hello
    printf("数据为: %s\n", buf);
}

int main()
{
    test7();
    return 0;
}