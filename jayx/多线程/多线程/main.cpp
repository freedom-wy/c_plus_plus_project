#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>


using namespace std;


/*
��C++�У����ࡢ�����ͱ�����������ѭһ����Լ�������ʵ������ȷ������������Ϳ�ά���ԡ�������һЩ����������������

1. **������**��
   - ʹ���շ���������CamelCase��������ÿ�����ʵ�����ĸ��д�����磺`MyClass`, `AudioProcessor`��
   - ����Ӧ�������ʻ����ʶ�������ر�����Ĺ��ܻ����ԡ�

2. **��������**��
   - ͨ��Ҳʹ���շ���������������ĸСд�����磺`calculateTotal`, `readFromFile`��
   - ������Ӧ���Ƕ��ʻ򶯴ʶ��׼ȷ������������Ϊ�������
   - ���ڷ�������getter�����޸�����setter��������ͨ��ʹ��`get`��`set`��Ϊǰ׺�����磺`getAge`, `setName`��

3. **��������**��
   - ������ͨ��ʹ��Сд��ĸ������֮�����»��߷ָ������Ϊ������������snake_case�������磺`current_speed`, `file_name`��
   - ������Ӧ�þ��������ԣ�ʹ�������������ܹ��������;��
   - ����ȫ�ֱ�������ĳ�Ա��������ʱ��ʹ���ض���ǰ׺���׺����`g_`��`m_`�����֡����磺`g_globalCounter`, `m_memberData`��

4. **�����ͺ�����**��
   - �����ͺ�ͨ��ʹ��ȫ��д��ĸ������֮�����»��߷ָ������磺`MAX_HEIGHT`, `DEFAULT_VALUE`��

5. **ģ�����Ͳ�������**��
   - ģ�����Ͳ���ͨ��ʹ�ô�д��ĸ����`T`, `U`, `V`�����߸��������Ե����ƣ���`KeyType`, `ValueType`��

��ס����Щֻ��ָ��ԭ�򣬲�ͬ����Ŀ���Ŷӿ��ܻ����Լ�������Լ������Ҫ������������Ŀ�б���һ���ԡ�
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
    // ��ͨ�Ķ��߳�
    /*int i = 10;
    thread t(output, i);*/
    //for (int i = 0; i < 1000; i++)
    //{
    //        // cout << "main" << i << endl;
    //        thread t(output, i);
    //        //t.detach();
    //        t.join();
    //}


    // ͨ������Զ��߳̽��в���
    /*thread th[10];
    for (int i = 0; i < 10; i++)
    {
            th[i] = thread(output, i);
    }

    for (int i = 0; i < 10; i++)
    {
            th[i].join();
    }*/


    // ���̲߳���һ������ʱ�������Դ����
    /*thread th[10000];
    for (int i = 0; i < 10000; i++)
    {
            th[i] = thread(addNum);
    }

    for (int i = 0; i < 10000; i++)
    {
            th[i].join();
    }

    cout << "n��ֵΪ: " << n << endl;*/

    // ������
    /*thread th[10000];
    for (int i = 0; i < 10000; i++)
    {
            th[i] = thread(mutexAddNum);
    }

    for (int i = 0; i < 10000; i++)
    {
            th[i].join();
    }

    cout << "n��ֵΪ: " << n << endl;*/

	thread th[10000];
	for (int i = 0; i < 10000; i++)
	{
		th[i] = thread(atomicAddNum);
	}

	for (int i = 0; i < 10000; i++)
	{
		th[i].join();
	}

	cout << "n��ֵΪ: " << n << endl;
	system("pause");
	return 0;
}

