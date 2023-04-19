#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // szEncode 0X3A, 0X0A, 0X03, 0X18, 0X0E, 0X42, 0X34, 0X0B, 0X43, 0X5E, 0X57, 0X34
              //0X48, 0X65, 0X6C, 0X6C, 0X6F, 0X20, 0X57, 0X6F, 0X72, 0X6C, 0X64, 0X00
    // nCheckValue=1052
    char szEncode[] = {0X3A, 0X0A, 0X03, 0X18, 0X0E, 0X42, 0X34, 0X0B, 0X43, 0X5E, 0X57, 0X34};
    char szAccount[] = "root";
    char szPassword[] = "abcd1234";
    char szKey[32] = {0};
    char szDecode[32] = {0};
    int nCheckValue = 0;

    int i = 0;

    // 用户名密码合成key
    strcpy(szKey, szAccount);
    strcat(szKey, szPassword);

    // 解密数据
    for(i=0; i < sizeof(szEncode) / sizeof(szEncode[0]); i++)
    {
        szDecode[i] = szEncode[i] ^ szKey[i];
    }

    // 查看解密后数据
    for(i=0; i < sizeof(szDecode) / sizeof(szDecode[0]); i++)
    {
        printf("0X%02X, ", szDecode[i]);
    }

    printf("\n");
    
    for(i=0; i < sizeof(szDecode) / sizeof(szDecode[0]); i++)
    {
        nCheckValue = nCheckValue + szDecode[i];
    }

    printf("nCheckValue= %d\n", nCheckValue);

    return 0;
}
