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
	// 方法声明
	CVector(); // 无参构造
	CVector(int size); // 有参构造
	//CVector(const CVector& obj); // 拷贝构造
	//CVector& operator=(const CVector obj); // 等号运算符重载
	//CVector(CVector&& obj); // 移动构造
	~CVector(); // 析构

	// 成员方法
	void PushHead(int val); // 头部插入
	void PushBack(int val); // 尾部插入
	void Insert(int nIdx, int val); // 指定位置插入

};

void test1();
