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
}

CMyString::~CMyString()
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

void CMyString::Append(char* szStr)
{
}

void CMyString::Append(const CMyString& obj)
{
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
    // CMyString s1("hello world");
    CMyString* s1 = new CMyString("hello world");
    cout << "str: " << s1->GetStr() << endl;
    delete s1;
    return 0;
}
