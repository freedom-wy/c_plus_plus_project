#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test1()
{
    // 打开文件
    FILE* f_write = fopen("test1.txt", "w");
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

int main()
{
    test1();
    return 0;
}