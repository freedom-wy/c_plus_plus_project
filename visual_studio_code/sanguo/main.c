#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test6()
{
    // �ļ����ݸ�ʽ�� fprintf�����Ϊд�ļ� fscanf���뼴Ϊ���ļ�
    struct heroInfo
    {
        char name[32]; //����
        int atk; // ������
        int def; // ������
    };

    struct heroInfo heroArray[3] =
    {
        {"����", 20, 100},
        {"����", 90, 90},
        {"�ŷ�", 80, 80}
    };

    // �����ṹ������
    // for(int i=0;i<3;i++)
    // {
    //     printf("Ӣ������: %s, Ӣ�۹�����: %d, Ӣ�۷�����: %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
    // }

    // ���ṹ������д���ļ�
    FILE* f_write = fopen("hero.txt", "w");
    for (int i = 0; i < 3; i++)
    {
        fprintf(f_write, "[Ӣ������]%s [Ӣ�۹�����]%d [Ӣ�۷�����]%d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
        // fprintf(f_write, "Ӣ������: %s, Ӣ�۹�����: %d, Ӣ�۷�����: %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
    }

    fclose(f_write);
}

void test7()
{
    // ��ȡ�ļ�����
    FILE* f_read = fopen("hero.txt", "r");
    struct heroInfo
    {
        char name[32]; //����
        int atk; // ������
        int def; // ������
    };
    struct heroInfo heroArray[3];

    int i = 0;
    while (!feof(f_read))
    {
        // ���ļ� [Ӣ������]���� [Ӣ�۹�����]20 [Ӣ�۷�����]100
        // Ӣ������: ����, Ӣ�۹�����: 20, Ӣ�۷�����: 100
        fscanf(f_read, "[Ӣ������]%s [Ӣ�۹�����]%d [Ӣ�۷�����]%d\n", heroArray[i].name, &heroArray[i].atk, &heroArray[i].def);
        // fscanf(f_read, "Ӣ������: %s, Ӣ�۹�����: %d, Ӣ�۷�����: %d\n", heroArray[i].name, &heroArray[i].atk, &heroArray[i].def);
        i++;
    }
    printf("��ȡ���\n");
    for (int i = 0; i < 3; i++)
    {
        printf("���Ϊ: Ӣ������: %s, Ӣ�۹�����: %d, Ӣ�۷�����: %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
    }
    fclose(f_read);
}

int main()
{
    test7();
    return 0;
}