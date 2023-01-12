#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

#define SCOREFILENAME "score.txt"

void showMenu()
{
    printf("1 ��¼��������\n");
    printf("2 �鿴��������\n");
    printf("3 ��ձ�������\n");
    printf("4 �˳�����\n");
}

void addScore()
{
    // ��һ���ļ�, ��׷��ģʽ��
    FILE* f_write = fopen(SCOREFILENAME, "a");
    int score = 0;
    scanf("%d", &score);
    fprintf(f_write, "%d\n", score);
    fclose(f_write);
    printf("��¼�����ɼ��ɹ�\n");
}

void showScore()
{
    // �鿴����ǰ�ж����ļ����Ƿ�������
    // ��ȡ�����ļ�
    FILE* f_read = fopen(SCOREFILENAME, "r");
    while (!feof(f_read))
    {
        int score = 0;
        fscanf(f_read, "%d\n", &score);
        printf("��������Ϊ: %d\n", score);
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
//     scanf("�����������...%c", &ch);
// }

void test1()
{
    // 1����ӭ����
    // 2����¼��������
    // 3���鿴��������
    // 4����ձ�������
    // 5���˳�����
    int select = 0;
    while (1)
    {
        // ��ʾ��ӭ����˵�
        showMenu();

        printf("�����빦�����\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("�������������\n");
            addScore();
            // pressKey();
            system("pause");
            system("cls");
            break;
        case 2:
            printf("�鿴��������\n");
            showScore();
            system("pause");
            system("cls");;
            break;
        case 3:
            printf("��ձ�������\n");
            clearScore();
            system("pause");
            system("cls");
            break;
        case 4:
            printf("�˳�����\n");
            exitProgram();
            system("pause");
            system("cls");
            break;
        default:
            printf("��������, ����������\n");
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