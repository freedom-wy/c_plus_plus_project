#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class CBuff
{

private:
    char* m_pBuff;
    size_t m_nSize;

public:
    CBuff()
    {
        this->m_pBuff = NULL;
        this->m_nSize = 0;

        this->m_pBuff = new char[20];
    }

    CBuff(char* pBuff, size_t nSize)
    {
        this->m_pBuff = NULL;
        this->m_nSize = 0;
    }

	~CBuff()
	{
		delete [] this->m_pBuff;
		this->m_pBuff = NULL;
	}

    void SetData(const char* pBuff, size_t nSize)
    {
        memcpy(this->m_pBuff, pBuff, nSize);
        this->m_nSize = nSize;
    }

    char* GetData() const 
    {
		return this->m_pBuff;
    };

	size_t GetSize() const
	{
		return this->m_nSize;
	}
};

void PrintBuf(CBuff buf)
{
	for(int i=0;i<buf.GetSize();i++)
	{
		printf("%c\n", buf.GetData()[i]);
	}
}



int main()
{
    CBuff buf;
    char str[] = "hello world";
    buf.SetData(str, sizeof(str));
    printf("result = %s\n", buf.GetData());
	PrintBuf(buf);
	return 0;
}