#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encodeProgram()
{
    // ����������
	char szCode[] = {0X48, 0X65, 0X6C, 0X6C, 0X6F, 0X20, 0X57, 0X6F, 0X72, 0X6C, 0X64, 0X00};
    // ���ܺ�        0X3A, 0X0A, 0X03, 0X18, 0X0E, 0X42, 0X34, 0X0B, 0X43, 0X5E, 0X57, 0X34
	char szAccount[] = "root";
	char szPassword[] = "abcd1234";
	char szKey[32] = {0};
	char szEncode[32] = {0};
	int nCheckValue = 0;

    int i=0;

	// �û�������ϳ�key
	strcpy(szKey, szAccount);
	strcat(szKey, szPassword);
	
	printf("szKey= %s\n", szKey);
    
	// ͨ�������ܴ���������
	for(i=0; i < sizeof(szCode) / sizeof(szCode[0]); i++)
	{
        /*
            ����^��������������λ��ͬʱ�����Ϊ 1����ͬʱ���Ϊ 0������0^1Ϊ1��0^0Ϊ0��1^1Ϊ0��
            001001000   ʮ����72  ʮ������48
            001110010   ʮ����114 ʮ������72
            000111010   ʮ����58  ʮ������3A
        */
		szEncode[i] = szCode[i] ^ szKey[i];
	}

    // nCheckValue
    for(i=0; i < sizeof(szCode)/sizeof(szCode[0]); i++)
    {
        nCheckValue = nCheckValue + szCode[i];
    }

    printf("nCheckValue=%d\n", nCheckValue);
    
    // �鿴���ܺ�����
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