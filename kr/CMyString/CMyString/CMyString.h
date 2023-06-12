#pragma once
class CMyString
{
public:
    CMyString(); // Ĭ�Ϲ��췽��
    CMyString(const char* szStr); // �вι���
    CMyString(const CMyString& obj); // ��������
    ~CMyString(); // ����

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
    unsigned int m_nSize; // ��������С
    unsigned int m_nLen; // �ַ�������
};