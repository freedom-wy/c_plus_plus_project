#pragma once
class CMyString
{
public:
    CMyString(); // 默认构造方法
    CMyString(const char* szStr); // 有参构造
    CMyString(const CMyString& obj); // 拷贝构造
    ~CMyString(); // 析构

    char* GetStr();
    unsigned int GetLen();

    void Append(const char* szStr);
    void Append(const CMyString& obj);
    void Append(int n);
    void Append(float f);
    void Append(char n);
private:
    void init();
    void unit();

private:
    char* m_szBuff;
    unsigned int m_nSize; // 缓冲区大小
    unsigned int m_nLen; // 字符串长度
};