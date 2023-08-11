#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class CVector
{
private:
	T* m_pBuff;
	int m_nSize;
	int m_nBufLen;
public:
	// 方法声明
	CVector(); // 无参构造
	CVector(int size); // 有参构造
	CVector(const CVector& obj); // 拷贝构造
	CVector& operator=(const CVector& obj); // 等号运算符重载
	CVector(CVector&& obj); // 移动构造
	~CVector(); // 析构

	// 成员方法
	void PushHead(T val); // 头部插入
	void PushBack(T val); // 尾部插入
	void Insert(int nIdx, T val); // 指定位置插入

	void Delete(int nIdx);
	void PopHead();
	void PopBack();

	void clear();
	bool IsEmpty();

};

template<class T>
CVector<T>::CVector()
{
	cout << "无参构造" << endl;
	this->m_pBuff = NULL;
	this->m_nBufLen = 0;
	this->m_nSize = 0;
}

template<class T>
CVector<T>::CVector(int val)
{
	cout << "有参构造" << endl;
	this->m_pBuff = new T[val];
	if (this->m_pBuff == NULL)
	{
		return;
	}
	memset(this->m_pBuff, 0, sizeof(T) * val);
	this->m_nBufLen = val;
	this->m_nSize = 0;
}

template<class T>
CVector<T>::CVector(const CVector<T>& obj)
{
	cout << "拷贝构造" << endl;
	this->clear();
	*this = obj; // 调用等号运算符重载
}

template<class T>
CVector<T>& CVector<T>::operator=(const CVector<T>& obj)
{
	cout << "等号运算符重载" << endl;
	// 检查是否是自身
	if (this == &obj)
	{
		return *this;
	}
	this->clear();
	/*if (obj.IsEmpty())
	{
		return *this;
	}*/

	this->m_pBuff = new T[obj.m_nBufLen];
	memset(this->m_pBuff, 0, sizeof(T) * obj.m_nBufLen);
	memcpy(this->m_pBuff, obj.m_pBuff, sizeof(T) * obj.m_nBufLen);
	this->m_nBufLen = obj.m_nBufLen;
	this->m_nSize = obj.m_nSize;
	return *this;
}

template<class T>
CVector<T>::CVector(CVector<T>&& obj) // 移动构造
{
	this->clear();
	this->m_pBuff = obj.m_pBuff;
	this->m_nBufLen = obj.m_nBufLen;
	this->m_nSize = obj.m_nSize;
	obj.m_pBuff = NULL;
}

template<class T>
void CVector<T>::PushHead(T val)
{
	this->Insert(0, val);
}

template<class T>
void CVector<T>::PushBack(T val)
{
	this->Insert(this->m_nSize, val);
}

template<class T>
void CVector<T>::Insert(int nIdx, T val)
{
	cout << typeid(T).name() << endl;
	//cout << "指定位置: " << nIdx << ", 插入: " << val << endl;
	assert(nIdx <= this->m_nSize); // 必须符合nIdx小于等于size, 否则抛异常
	// 如果使用无参构造, 则需先判断是否申请内存空间
	if (this->m_pBuff == NULL || this->m_nBufLen == 0)
	{
		this->m_pBuff = new T[1];
		if (this->m_pBuff == NULL)
		{
			cout << "申请内存失败" << endl;
			return;
		}
		memset(this->m_pBuff, 0, sizeof(T));
		this->m_nBufLen = 1;
		this->m_nSize = 0;
	}

	// 空间不够了
	if (this->m_nSize >= this->m_nBufLen)
	{
		int nNewLen = this->m_nBufLen * 2;
		T* pNewBuf = new T[nNewLen];
		if (pNewBuf == NULL)
		{
			cout << "内存扩容失败" << endl;
			return;
		}
		memset(pNewBuf, 0, nNewLen * sizeof(T));

		// 拷贝原来的数据
		memcpy(pNewBuf, this->m_pBuff, this->m_nSize * sizeof(T));
		// 删除原来的数据
		delete[] this->m_pBuff;
		this->m_pBuff = pNewBuf;
		this->m_nBufLen = nNewLen;
	}

	memcpy(this->m_pBuff + nIdx + 1, this->m_pBuff + nIdx, (this->m_nSize - nIdx) * sizeof(T));
	this->m_pBuff[nIdx] = val;
	this->m_nSize++;
}

template<class T>
void CVector<T>::Delete(int nIdx)
{
	// 后面数据向前移动，长度减一
	// 0 5 1 2 6 7  容量6 长度6 删除索引为2的数据
	// 0 5 2 6 7 7 
	if (nIdx < 0 || nIdx >= this->m_nSize)
	{
		cout << "删除的索引有误" << endl;
		return;
	}
	memcpy(this->m_pBuff + nIdx, this->m_pBuff + nIdx + 1, (this->m_nSize - nIdx - 1) * sizeof(T));
	this->m_nSize--;
}

template<class T>
void CVector<T>::PopHead()
{
	this->Delete(0); // 删除索引为0的数据
}

template<class T>
void CVector<T>::PopBack()
{
	this->Delete(this->m_nSize - 1);
}

template<class T>
void CVector<T>::clear()
{
	if (this->m_pBuff != NULL)
	{
		delete[] this->m_pBuff;
		this->m_pBuff = NULL;
		this->m_nBufLen = 0;
		this->m_nSize = 0;
	}
}

template<class T>
bool CVector<T>::IsEmpty()
{
	return this->m_nSize == 0;
}

template<class T>
CVector<T>::~CVector()
{
	this->clear();
}


class Person
{
private:
	int age;
public:
	Person()
	{
		cout << "默认构造方法" << endl;
	}
	Person(int val)
	{
		this->age = val;
	}
};

int main()
{
	/*CVector<int>cv2;
	cv2.PushBack(1);
	cv2.PushBack(2);*/
	CVector<Person>cv1;
	Person p1(1);
	Person p2(2);
	cv1.PushBack(p1);
	cv1.PushBack(p2);
	cv1.PopBack();
	cout << "hello world" << endl;
	return 0;
}
