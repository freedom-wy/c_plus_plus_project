#pragma once
#include <iostream>
using namespace std;

template<class T>
class myArray
{
	// ������������
	private:
		// �ڶ�����������
		T* pAddress;
		// ����
		int mCapacity;
		int mSize;

	public:
		// ���췽��
		myArray(int capacity)
		{
			cout << "���췽��" << endl;
			this->mCapacity = capacity;
			this->mSize = 0;
			this->pAddress = new T[this->mCapacity];
		}

		// ��������
		myArray(const myArray& arr)
		{
			cout << "�������췽��" << endl;
			this->mCapacity = arr.mCapacity;
			this->mSize = arr.mSize;
			// �����ڶ�������
			this->pAddress = new T[this->mCapacity];
			// ��ԭʼ���ݿ������µĶ���
			for (int i = 0; i < this->mSize; i++)
			{
				this->pAddress[i] = arr.pAddress[i];
			}
		}

		// ��������
		~myArray()
		{
			cout << "��������" << endl;
			if (this->pAddress != NULL)
			{
				delete[] this->pAddress;
				this->pAddress = NULL;
				this->mCapacity = 0;
				this->mSize = 0;
			}
		}

		// β����������
		void pushBack(const T& val)
		{
			/*cout << "������С" << this->mCapacity << endl;
			cout << "���ݴ�С" << this->mSize << endl;*/
			// �ռ�����
			if (this->mCapacity == this->mSize)
			{
				return;
			}
			//cout << "��������" << val << endl;
			this->pAddress[this->mSize] = val;
			this->mSize++;
		}

		// β��ɾ������
		void popBack()
		{
			if (this->mSize == 0)
			{
				return;
			}
			//this->pAddress[this->mSize] = NULL;
			this->mSize--;
		}

		// ��ȡ����
		int getCapacity()
		{
			return this->mCapacity;
		}

		// ��ȡ��С
		int getSize()
		{
			return this->mSize;
		}

		// �����������
		T& operator[](int index)
		{
			return this->pAddress[index];
		}
};
