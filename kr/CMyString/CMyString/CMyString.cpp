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
    cout << "�вι���" << endl;
    if (szStr == NULL) {
        init();
    }
    else {
        this->m_nLen = strlen(szStr);
        this->m_nSize = this->m_nLen + 1;
        this->m_szBuff = new char[this->m_nSize];
        if (this->m_szBuff == NULL) {
            cout << "new �ռ�ʧ��" << endl;
            init();
            return;
        }
        memset(this->m_szBuff, 0, this->m_nSize);
        strcpy(this->m_szBuff, szStr);
    }
}

CMyString::CMyString(const CMyString& obj)
{
    cout << "��������" << endl;
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
    cout << "��ԭ�ַ�������µ��ַ���" << endl;
    if (szStr == NULL) {
        return;
    }
    unsigned int szStrLen = strlen(szStr);
    if (szStrLen + this->m_nLen < this->m_nSize) {
        // ����ռ��㹻
        strcat(this->m_szBuff, szStr);
        this->m_nLen = this->m_nLen + szStrLen;
    }
    else {
        unsigned int szStrSize = szStrLen + this->m_nLen + 1;
        // �����µĿռ�
        char* newszBuff = new char[szStrSize];
        if (newszBuff == NULL) {
            cout << "new �ռ�ʧ��" << endl;
            return;
        }
        memset(newszBuff, 0, szStrSize);
        strcpy(newszBuff, this->m_szBuff);
        strcat(newszBuff, szStr);

        // �ͷ�ԭʼ�ռ�
        unit();
        // ����ָ��
        this->m_szBuff = newszBuff;
        this->m_nSize = szStrSize;
        this->m_nLen = szStrSize - 1;
    }
}

void CMyString::Append(const CMyString& obj)
{
    cout << "��ԭ�ַ�������µ�object" << endl;
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
