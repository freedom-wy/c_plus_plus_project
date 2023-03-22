#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    /*
        未初始化（调试版）：CD CD中文字符“屯”,发布版堆不做初始化动作,空闲  ：FE FE （有的操作系统是DD DD）中文字符“葺”或者“铪”。
    */
    char* psz = NULL;
    psz = (char*)malloc(10);
    if(psz == NULL)
    {
        printf("申请内存空间失败");
        return 0;
    }
    memset(psz, 0, 10);
    strcpy(psz, "hello");
    printf("字符串为: %s\n", psz);
    free(psz);
    return 0;
}