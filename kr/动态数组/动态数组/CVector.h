#pragma once
#include <iostream>
using namespace std;

class CVector
{
private:
	int* m_pBuff;
	int m_nSize;
	int m_nBufLen;
public:
	// ��������
	CVector(); // �޲ι���
	CVector(int size); // �вι���
	//CVector(const CVector& obj); // ��������
	//CVector& operator=(const CVector obj); // �Ⱥ����������
	//CVector(CVector&& obj); // �ƶ�����
	~CVector(); // ����

	// ��Ա����
	void PushHead(int val); // ͷ������
	void PushBack(int val); // β������
	void Insert(int nIdx, int val); // ָ��λ�ò���

};

void test1();
