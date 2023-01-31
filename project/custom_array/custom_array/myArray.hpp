#pragma once
#include <iostream>
using namespace std;

template<class T>
class myArray
{
	// 定义数组属性
	private:
		// 在堆区定义数组
		T* pAddress;
		// 容量
		int mCapacity;
		int mSize;

	public:
		// 构造方法
		myArray(int capacity)
		{
			cout << "构造方法" << endl;
			this->mCapacity = capacity;
			this->mSize = 0;
			this->pAddress = new T[this->mCapacity];
		}

		// 拷贝构造
		myArray(const myArray& arr)
		{
			cout << "拷贝构造方法" << endl;
			this->mCapacity = arr.mCapacity;
			this->mSize = arr.mSize;
			// 重新在堆区创建
			this->pAddress = new T[this->mCapacity];
			// 将原始数据拷贝到新的堆区
			for (int i = 0; i < this->mSize; i++)
			{
				this->pAddress[i] = arr.pAddress[i];
			}
		}

		// 析构方法
		~myArray()
		{
			cout << "析构方法" << endl;
			if (this->pAddress != NULL)
			{
				delete[] this->pAddress;
				this->pAddress = NULL;
				this->mCapacity = 0;
				this->mSize = 0;
			}
		}

		// 尾部插入数据
		void pushBack(const T& val)
		{
			/*cout << "容量大小" << this->mCapacity << endl;
			cout << "数据大小" << this->mSize << endl;*/
			// 空间已满
			if (this->mCapacity == this->mSize)
			{
				return;
			}
			//cout << "进入数据" << val << endl;
			this->pAddress[this->mSize] = val;
			this->mSize++;
		}

		// 尾部删除数据
		void popBack()
		{
			if (this->mSize == 0)
			{
				return;
			}
			//this->pAddress[this->mSize] = NULL;
			this->mSize--;
		}

		// 获取容量
		int getCapacity()
		{
			return this->mCapacity;
		}

		// 获取大小
		int getSize()
		{
			return this->mSize;
		}

		// 重载特殊符号
		T& operator[](int index)
		{
			return this->pAddress[index];
		}
};
