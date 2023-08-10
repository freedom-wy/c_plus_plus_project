#include "CVector.h"
#include <assert.h>

CVector::CVector()
{
	cout << "�޲ι���" << endl;
	this->m_pBuff = NULL;
	this->m_nBufLen = 0;
	this->m_nSize = 0;
}

CVector::CVector(int val)
{
	cout << "�вι���" << endl;
	this->m_pBuff = new int[val];
	memset(this->m_pBuff, 0, sizeof(this->m_pBuff)*val);
	this->m_nBufLen = val;
	this->m_nSize = 0;
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
	cout << "ָ��λ��: " << nIdx << ", ����: " << val << endl;
	assert(nIdx <= this->m_nSize); // �������nIdxС�ڵ���size, �������쳣
	// ���ʹ���޲ι���, �������ж��Ƿ������ڴ�ռ�
	if (this->m_pBuff == NULL || this->m_nBufLen == 0)
	{
		this->m_pBuff = new int[val];
		if (this->m_pBuff == NULL)
		{
			cout << "�����ڴ�ʧ��" << endl;
			return;
		}
		memset(this->m_pBuff, 0, sizeof(int) * val);
		this->m_nBufLen = val;
		this->m_nSize = 0;
	}

	// �ռ䲻����
	if (this->m_nSize >= this->m_nBufLen)
	{
		int nNewLen = this->m_nBufLen * 2;
		int* pNewBuf = new int[nNewLen];
		if (pNewBuf == NULL)
		{
			cout << "�ڴ�����ʧ��" << endl;
			return;
		}
		memset(pNewBuf, 0, nNewLen * sizeof(int));

		// ����ԭ��������
		memcpy(pNewBuf, this->m_pBuff, this->m_nSize * sizeof(int));
		// ɾ��ԭ��������
		delete[] this->m_pBuff;
		this->m_pBuff = pNewBuf;
		this->m_nBufLen = nNewLen;
	}

	memcpy(this->m_pBuff + nIdx + 1, this->m_pBuff + nIdx, (this->m_nSize - nIdx) * sizeof(int));
	this->m_pBuff[nIdx] = val;
	this->m_nSize++;

	// ��������
	// this->m_pBuff[nIdx] = val; // ��sizeΪ0ʱ
	// 20 1 5 9 8
	


}

CVector::~CVector()
{
	if (this->m_pBuff != NULL)
	{
		delete[] this->m_pBuff;
		this->m_nBufLen = 0;
		this->m_nSize = 0;
	}
}

void test1()
{
	CVector cv1;
	cv1.Insert(0, 1);
	cv1.Insert(1, 2);
	cv1.Insert(0, 5);
}