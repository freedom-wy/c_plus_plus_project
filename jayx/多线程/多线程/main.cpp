#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>


using namespace std;


/*
在C++中，对类、函数和变量的命名遵循一定的约定和最佳实践，以确保代码的清晰和可维护性。以下是一些常见的命名方法：

1. **类命名**：
   - 使用驼峰命名法（CamelCase），其中每个单词的首字母大写。例如：`MyClass`, `AudioProcessor`。
   - 类名应该是名词或名词短语，清晰地表明类的功能或特性。

2. **函数命名**：
   - 通常也使用驼峰命名法，但首字母小写。例如：`calculateTotal`, `readFromFile`。
   - 函数名应该是动词或动词短语，准确描述函数的行为或操作。
   - 对于访问器（getter）和修改器（setter）函数，通常使用`get`和`set`作为前缀。例如：`getAge`, `setName`。

3. **变量命名**：
   - 变量名通常使用小写字母，单词之间用下划线分隔，这称为蛇形命名法（snake_case）。例如：`current_speed`, `file_name`。
   - 变量名应该具有描述性，使得其他开发者能够理解其用途。
   - 对于全局变量或类的成员变量，有时会使用特定的前缀或后缀，如`g_`或`m_`来区分。例如：`g_globalCounter`, `m_memberData`。

4. **常量和宏命名**：
   - 常量和宏通常使用全大写字母，单词之间用下划线分隔。例如：`MAX_HEIGHT`, `DEFAULT_VALUE`。

5. **模板类型参数命名**：
   - 模板类型参数通常使用大写字母，如`T`, `U`, `V`，或者更具描述性的名称，如`KeyType`, `ValueType`。

记住，这些只是指导原则，不同的项目或团队可能会有自己的命名约定。重要的是在整个项目中保持一致性。
*/


void output(int i)
{
	cout << "output" << i << endl;
	/*for (int i = 0; i < num; i++)
	{
		cout << "output" << i << endl;
	}*/
}

mutex mtx;
//int n = 0;
//void addNum()
//{
//	n = n + 1;
//}

//mutex mtx;
//int n = 0;
//void mutexAddNum()
//{
//	mtx.lock();
//	n = n + 1;
//	mtx.unlock();
//}


atomic_int n = 0;
void atomicAddNum()
{
	n+=1;
}

int main()
{
    // 普通的多线程
    /*int i = 10;
    thread t(output, i);*/
    //for (int i = 0; i < 1000; i++)
    //{
    //        // cout << "main" << i << endl;
    //        thread t(output, i);
    //        //t.detach();
    //        t.join();
    //}


    // 通过数组对多线程进行操作
    /*thread th[10];
    for (int i = 0; i < 10; i++)
    {
            th[i] = thread(output, i);
    }

    for (int i = 0; i < 10; i++)
    {
            th[i].join();
    }*/


    // 多线程操作一个变量时会造成资源争抢
    /*thread th[10000];
    for (int i = 0; i < 10000; i++)
    {
            th[i] = thread(addNum);
    }

    for (int i = 0; i < 10000; i++)
    {
            th[i].join();
    }

    cout << "n的值为: " << n << endl;*/

    // 引入锁
    /*thread th[10000];
    for (int i = 0; i < 10000; i++)
    {
            th[i] = thread(mutexAddNum);
    }

    for (int i = 0; i < 10000; i++)
    {
            th[i].join();
    }

    cout << "n的值为: " << n << endl;*/

	thread th[10000];
	for (int i = 0; i < 10000; i++)
	{
		th[i] = thread(atomicAddNum);
	}

	for (int i = 0; i < 10000; i++)
	{
		th[i].join();
	}

	cout << "n的值为: " << n << endl;
	system("pause");
	return 0;
}

