#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	T* pAddress;
	int mCapacity;
	int mSize;

	MyArray(int capacity)
	{
		this->mCapacity = capacity;
		this->mSize = 0;
		pAddress = new T[this->mCapacity];
	}
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->mCapacity = 0;
			this->mSize = 0;
		}
	}

	MyArray(const MyArray& arr)
	{
		// 拷贝构造
		this->mCapacity = arr.mCapacity;
		this->mSize = arr.mSize;
		this->pAddress = new T[this->mCapacity];
		// 将原始数据拷贝到新的空间中
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	MyArray& operator=(const MyArray& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->mCapacity = 0;
			this->mSize = 0;
		}

		this->mCapacity = arr.mCapacity;
		this->mSize = arr.mSize;
		this->pAddress = new T[this->mCapacity];
		// 将原始数据拷贝到新的空间中
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	void PushBack(const T& val)
	{
		if (this->mCapacity == this->mSize)
		{
			return;
		}
		this->pAddress[this->mSize] = val;
		this->mSize++;
	}

	void PopBack()
	{
		if (this->mSize == 0)
		{
			return;
		}
		this->mSize--;
	}
};

