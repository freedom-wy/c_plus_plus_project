#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encodeProgram()
{
    // 待加密数据
	char szCode[] = {0X48, 0X65, 0X6C, 0X6C, 0X6F, 0X20, 0X57, 0X6F, 0X72, 0X6C, 0X64, 0X00};
    // 加密后        0X3A, 0X0A, 0X03, 0X18, 0X0E, 0X42, 0X34, 0X0B, 0X43, 0X5E, 0X57, 0X34
	char szAccount[] = "root";
	char szPassword[] = "abcd1234";
	char szKey[32] = {0};
	char szEncode[32] = {0};
	int nCheckValue = 0;

    int i=0;

	// 用户名密码合成key
	strcpy(szKey, szAccount);
	strcat(szKey, szPassword);
	
	printf("szKey= %s\n", szKey);
    
	// 通过异或加密待加密数据
	for(i=0; i < sizeof(szCode) / sizeof(szCode[0]); i++)
	{
        /*
            参与^运算两个二进制位不同时，结果为 1，相同时结果为 0。例如0^1为1，0^0为0，1^1为0。
            001001000   十进制72  十六进制48
            001110010   十进制114 十六进制72
            000111010   十进制58  十六进制3A
        */
		szEncode[i] = szCode[i] ^ szKey[i];
	}

    // nCheckValue
    for(i=0; i < sizeof(szCode)/sizeof(szCode[0]); i++)
    {
        nCheckValue = nCheckValue + szCode[i];
    }

    printf("nCheckValue=%d\n", nCheckValue);
    
    // 查看加密后数据
    for(i=0; i < sizeof(szEncode)/sizeof(szEncode[0]); i++)
    {
        printf("0X%02X, ", szEncode[i]);
    }
}

/*
int main()
{
    encodeProgram();
	return 0;
}
*/