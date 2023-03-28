#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tagTest{
    int a;
    float b;
    double c;
    char d[20];
};

int main()
{
    struct tagTest test[] = {
        {1, 3.14f, 0.618, "Hello"},
        {2, 4.14f, 1.618, "Jack"},
        {3, 5.14f, 2.618, "jjyy"},
    };

    FILE* fp = NULL;

    fp = fopen("test.bin", "rb+");
    if (fp == NULL)
    {
        fp = fopen("test.bin", "wb+");
        if(fp == NULL)
        {
            exit(-1);
        }
    }

    if(fwrite(test, sizeof(test), 1, fp)!=1)
    // if(fwrite(test, sizeof(test[0]), 3, fp)!=3)
    {
        int nError = ferror(fp);
        exit(nError);
    }

    // commit data
    if(EOF == fflush(fp))
    {
        int nError = ferror(fp);
        exit(nError);
    }

    // rewrite data
    int nSize = sizeof(struct tagTest);
    fseek(fp, -nSize, SEEK_CUR);
    test[2].a = 6;
    if(fwrite(&test[2], sizeof(test[2]), 1, fp)!=1)
    {
        int nError = ferror(fp);
        exit(nError);
    }

    if(fp)
    {
        fclose(fp);
    }


    return 0;
}