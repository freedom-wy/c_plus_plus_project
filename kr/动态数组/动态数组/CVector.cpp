#include "CVector.h"
#include <assert.h>

CVector::CVector()
{
	cout << "无参构造" << endl;
	this->m_pBuff = NULL;
	this->m_nBufLen = 0;
	this->m_nSize = 0;
}

CVector::CVector(int val)
{
	cout << "有参构造" << endl;
	this->m_pBuff = new int[val];
	if (this->m_pBuff == NULL)
	{
		return;
	}
	memset(this->m_pBuff, 0, sizeof(this->m_pBuff)*val);
	this->m_nBufLen = val;
	this->m_nSize = 0;
}

CVector::CVector(const CVector& obj)
{
	cout << "拷贝构造" << endl;
	this->clear();
	*this = obj; // 调用等号运算符重载
}

CVector& CVector::operator=(const CVector& obj)
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

	this->m_pBuff = new int[obj.m_nBufLen];
	memset(this->m_pBuff, 0, sizeof(int) * obj.m_nBufLen);
	memcpy(this->m_pBuff, obj.m_pBuff, sizeof(int) * obj.m_nBufLen);
	this->m_nBufLen = obj.m_nBufLen;
	this->m_nSize = obj.m_nSize;
	return *this;
}

CVector::CVector(CVector&& obj)
{
	this->clear();
	this->m_pBuff = obj.m_pBuff;
	this->m_nBufLen = obj.m_nBufLen;
	this->m_nSize = obj.m_nSize;
	obj.m_pBuff = NULL;
}

void CVector::PushHead(int val)
{
	this->Insert(0, val);
}

void CVector::PushBack(int val)
{
	this->Insert(this->m_nSize, val);
}

void CVector::Insert(int nIdx, int val)
{
	cout << "指定位置: " << nIdx << ", 插入: " << val << endl;
	assert(nIdx <= this->m_nSize); // 必须符合nIdx小于等于size, 否则抛异常
	// 如果使用无参构造, 则需先判断是否申请内存空间
	if (this->m_pBuff == NULL || this->m_nBufLen == 0)
	{
		this->m_pBuff = new int[val];
		if (this->m_pBuff == NULL)
		{
			cout << "申请内存失败" << endl;
			return;
		}
		memset(this->m_pBuff, 0, sizeof(int) * val);
		this->m_nBufLen = val;
		this->m_nSize = 0;
	}

	// 空间不够了
	if (this->m_nSize >= this->m_nBufLen)
	{
		int nNewLen = this->m_nBufLen * 2;
		int* pNewBuf = new int[nNewLen];
		if (pNewBuf == NULL)
		{
			cout << "内存扩容失败" << endl;
			return;
		}
		memset(pNewBuf, 0, nNewLen * sizeof(int));

		// 拷贝原来的数据
		memcpy(pNewBuf, this->m_pBuff, this->m_nSize * sizeof(int));
		// 删除原来的数据
		delete[] this->m_pBuff;
		this->m_pBuff = pNewBuf;
		this->m_nBufLen = nNewLen;
	}

	memcpy(this->m_pBuff + nIdx + 1, this->m_pBuff + nIdx, (this->m_nSize - nIdx) * sizeof(int));
	this->m_pBuff[nIdx] = val;
	this->m_nSize++;
}

void CVector::clear()
{
	if (this->m_pBuff != NULL)
	{
		delete[] this->m_pBuff;
		this->m_pBuff = NULL;
		this->m_nBufLen = 0;
		this->m_nSize = 0;
	}
}

bool CVector::IsEmpty()
{
	return this->m_nSize == 0;
}

CVector::~CVector()
{
	this->clear();
}

void test1()
{
	CVector cv1;
	cv1.Insert(0, 1);
	cv1.Insert(1, 2);
	cv1.Insert(0, 5);
	CVector cv2 = cv1;
	CVector cv3 = std::move(cv2); // 移动构造时将cv2析构
	cout << "hello world" << endl;
}