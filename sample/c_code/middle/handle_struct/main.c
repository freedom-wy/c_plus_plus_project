#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 结构体
struct Student
{
    int id;
    char name[20]; //姓名
    int score;
};

void test1()
{
    struct Student s1; // 在c++中struct可以省略
    s1.id = 1;
    // s1.name = "张三"; // 在C语言中不能使用该方式对字符串进行赋值
    strcpy(s1.name, "张三");
    s1.score = 100;
    printf("学生的ID为: %d\n", s1.id);
    printf("学生的姓名为: %s\n", s1.name);
    struct Student s2 = {2, "李四", 80}; //第二种赋值方式
}

 void test2()
 {
    // 结构体指针
    struct Student s3;
    struct Student* p = &s3;
    p->id = 1;
    strcpy(p->name, "王五");
    p->score = 60;
    printf("通过指针访问结构体变量: \n");
    printf("学号: %d\n", p->id);
    printf("姓名: %s\n", p->name);
    printf("分数: %d\n", p->score);
 }

 void test3()
 {
    // 在堆区创建结构体指针
    struct Student* p = NULL;
    p = malloc(sizeof(struct Student));
    p->id = 1;
    strcpy(p->name, "赵六");
    p->score = 70;
    printf("输出在堆区的数据: \n");
    printf("学号: %d\n", p->id);
    printf("姓名: %s\n", p->name);
    free(p);
    p = NULL;
 }

 void test4()
 {
    // 在堆区创建结构体数组
    int num = 0;
    printf("请输入数组大小: \n");
    scanf("%d", &num); // 接受用户输入的数据
    struct Student* arr = malloc(sizeof(struct Student)*num); // 在堆区创建数组
    for(int i=0;i<num;i++)
    {
        // 给结构体数组中数据赋值
        scanf("%d %s %d", &(arr[i].id), arr[i].name, &(arr[i].score));
    }

    for(int i=0;i<num;i++)
    {
        printf("学号为: %d, 姓名为: %s, 分数为: %d\n", arr[i].id, arr[i].name, arr[i].score);
    }
    // 释放内存
    free(arr);
    arr = NULL;
 }

void test5()
{
    // 在堆区申请空间并创建结构体
    struct Teacher
    {
        int id;
        char* name;
    };

    struct Teacher* t1 = NULL;
    t1 = malloc(sizeof(struct Teacher)); // 在堆区开辟空间并创建结构体
    t1->id = 1;
    t1->name = malloc(sizeof(char)*32);
    strcpy(t1->name, "hello");
    printf("教师ID: %d, 教师姓名: %s\n", t1->id, t1->name);
    free(t1->name);
    free(t1);
}

struct Person
{
	char *name;
	int age;
};

//分配内存
struct Person** allocateSpace()
{
	struct Person **temp = malloc(sizeof(struct Person *) * 3);

	for (int i = 0; i < 3; ++i)
	{
		temp[i] = malloc(sizeof(struct Person));

		temp[i]->name = malloc(sizeof(char)* 64);

		sprintf(temp[i]->name, "Name_%d", i + 1);

		temp[i]->age = 100 + i;
	}


	return temp;
}

//打印
void printPerson(struct Person **person)
{
	if (NULL == person)
	{
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		printf("Name:%s Age:%d\n",person[i]->name,person[i]->age);
	}
}

//释放内存
void freeSpace(struct Person **person)
{

	if (NULL == person)
	{
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (person[i] == NULL)
		{
			continue;
		}

		if (person[i]->name != NULL)
		{
			printf("Name:%s的内存被释放!\n", person[i]->name);
			free(person[i]->name);
			person[i]->name = NULL;
		}

		
		free(person[i]);
		person[i] = NULL;
	}

	free(person);
	person = NULL;
}

void test6()
{
	struct Person **person = NULL;
	person = allocateSpace();
	printPerson(person);
	freeSpace(person);
	person = NULL;
}


int main()
{
    test6();
    return 0;
}