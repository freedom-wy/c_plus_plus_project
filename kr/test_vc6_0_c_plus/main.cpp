#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    /*
        δ��ʼ�������԰棩��CD CD�����ַ����͡�,������Ѳ�����ʼ������,����  ��FE FE ���еĲ���ϵͳ��DD DD�������ַ����ݡ����ߡ�������
    */
    char* psz = NULL;
    psz = (char*)malloc(10);
    if(psz == NULL)
    {
        printf("�����ڴ�ռ�ʧ��");
        return 0;
    }
    memset(psz, 0, 10);
    strcpy(psz, "hello");
    printf("�ַ���Ϊ: %s\n", psz);
    free(psz);
    return 0;
}