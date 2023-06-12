#include "CMyString.h"
#include <iostream>
#include <string>
using namespace std;

CMyString::CMyString()
{
    init();
}

void CMyString::init()
{
    this->m_szBuff = NULL;
    this->m_nSize = 0;
    this->m_nLen = 0;
}

CMyString::CMyString(const char* szStr)
{
    cout << "有参构造" << endl;
    if (szStr == NULL) {
        init();
    }
    else {
        this->m_nLen = strlen(szStr);
        this->m_nSize = this->m_nLen + 1;
        this->m_szBuff = new char[this->m_nSize];
        if (this->m_szBuff == NULL) {
            cout << "new 空间失败" << endl;
            init();
            return;
        }
        memset(this->m_szBuff, 0, this->m_nSize);
        strcpy(this->m_szBuff, szStr);
    }
}

CMyString::CMyString(const CMyString& obj)
{
    cout << "拷贝构造" << endl;
}

CMyString::~CMyString()
{
    unit();
}

void CMyString::unit()
{
    if (this->m_szBuff != NULL) {
        delete[] this->m_szBuff;
        this->m_szBuff = NULL;
        this->m_nSize = 0;
        this->m_nLen = 0;
    }
}

char* CMyString::GetStr()
{
    return this->m_szBuff;
}

unsigned int CMyString::GetLen()
{
    return 0;
}

void CMyString::Append(const char* szStr)
{
    cout << "向原字符串添加新的字符串" << endl;
    if (szStr == NULL) {
        return;
    }
    unsigned int szStrLen = strlen(szStr);
    if (szStrLen + this->m_nLen < this->m_nSize) {
        // 缓冲空间足够
        strcat(this->m_szBuff, szStr);
        this->m_nLen = this->m_nLen + szStrLen;
    }
    else {
        unsigned int szStrSize = szStrLen + this->m_nLen + 1;
        // 开辟新的空间
        char* newszBuff = new char[szStrSize];
        if (newszBuff == NULL) {
            cout << "new 空间失败" << endl;
            return;
        }
        memset(newszBuff, 0, szStrSize);
        strcpy(newszBuff, this->m_szBuff);
        strcat(newszBuff, szStr);

        // 释放原始空间
        unit();
        // 更新指向
        this->m_szBuff = newszBuff;
        this->m_nSize = szStrSize;
        this->m_nLen = szStrSize - 1;
    }
}

void CMyString::Append(const CMyString& obj)
{
    cout << "向原字符串添加新的object" << endl;
    this->Append(obj.m_szBuff);
}

void CMyString::Append(int n)
{
}

void CMyString::Append(float f)
{
}

void CMyString::Append(char n)
{
}

int main() {
    CMyString s1("hello world");
    s1.Append(" aaa");
    cout << "str: " << s1.GetStr() << endl;
    CMyString s2("bbb");
    s1.Append(s2);
    cout << "str: " << s1.GetStr() << endl;
    return 0;
}
