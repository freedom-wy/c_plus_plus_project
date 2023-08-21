#include <iostream>
#include <assert.h>
using namespace std;


template<typename T>
class TCList
{
public:
    struct Node
    {
        Node(T val) :m_pPre(nullptr), m_pNext(nullptr), m_data(val) {}
        Node() :m_pPre(nullptr), m_pNext(nullptr), m_data(0) {}
        Node* m_pPre;
        Node* m_pNext;
        T m_data;
    };
public:
    TCList()
    {
        cout << "clist默认构造" << endl;
        this->Init();
    };
    TCList(const TCList& lst)
    {
        cout << "clist拷贝构造" << endl;
        this->Init();
        *this = lst;
    };

    //TCList(TCList&& lst);

    TCList& operator=(const TCList& lst)
    {
        cout << "等号运算符重载" << endl;
        //清空自己
        Clear();
        Node* pNode = lst.m_pHeadSoldier->m_pNext;
        while (pNode != lst.m_pTailSoldier) {
            PushTail(pNode->m_data);
            pNode = pNode->m_pNext;
        }
        return *this;
    };

    Node* Insert(Node* pPos, T& nVal) {
        assert(pPos != nullptr);
        //创建新节点
        Node* pNewNode = new Node(nVal);
        //修改节点
        Node* pPre = pPos->m_pPre;
        pNewNode->m_pPre = pPre;
        pNewNode->m_pNext = pPos;
        pPre->m_pNext = pNewNode;
        pPos->m_pPre = pNewNode;
        return pNewNode;
    }//指定位置插入

    Node* PushTail(T& nVal) {
        return Insert(m_pTailSoldier, nVal);
    }//尾插

    Node* PushHead(T& nVal) {
        return Insert(m_pHeadSoldier->m_pNext, nVal);
    }//头插

    //Node* Update(Node* pPos, T nVal) {
    //    assert(pPos != nullptr);
    //    pPos->m_data = nVal;
    //    return nullptr;
    //};//修改

    //Node* Find(T nVal) {
    //    Node* pNode = m_pHeadSoldier->m_pNext;
    //    while (pNode != m_pTailSoldier)
    //    {
    //        if (pNode->m_data == nVal)
    //        {
    //            return pNode;
    //        }
    //        pNode = pNode->m_pNext;
    //    }
    //    return nullptr;
    //};


    //void Delete(Node* pPos);//指定位置删除

    //void PopTail();//尾删除

    //void PopHead();//头删除

    void Clear(){
        while (!IsEmpty())
        {
            PopHead();
        }
    };

    uint32_t Size() const
    {
        uint32_t nSize = 0;
        Node* pNode = m_pHeadSoldier->m_pNext;
        while (pNode != m_pTailSoldier)
        {
            ++nSize;
            pNode = pNode->m_pNext;
        }
        return nSize;
    };

    bool IsEmpty() const
    {
        return m_pHeadSoldier->m_pNext = m_pTailSoldier;
    };

    virtual ~TCList()
    {
        Clear();
    };

    void Delete(Node* pPos)
    {
        assert(pPos != nullptr);
        assert(pPos != m_pHeadSoldier);
        assert(pPos != m_pTailSoldier);
        Node* pPre = pPos->m_pPre;
        Node* pNext = pPos->m_pNext;
        pPre->m_pNext = pNext;
        pNext->m_pPre = pPre;
        delete pPos;
    }
    
    void PopTail()
    {
        return Delete(m_pTailSoldier->m_pPre);
    }

    void PopHead()
    {
        return Delete(m_pHeadSoldier->m_pNext);
    }

private:
    void Init()
    {
        m_pHeadSoldier = new Node;
        m_pTailSoldier = new Node;
        m_pHeadSoldier->m_pNext = m_pTailSoldier;
        m_pTailSoldier->m_pPre = m_pHeadSoldier;
    };
private:
    Node* m_pHeadSoldier;//头哨兵节点指针
    Node* m_pTailSoldier;//尾哨兵节点指针
};



class CFoo
{
public:
    CFoo()
    {
        cout << "cfoo的默认构造" << endl;
        this->m_sz = NULL;
    }

    explicit CFoo(const char* sz)
    {
        if (sz == NULL)
        {
            char name[64] = "hello";
            this->m_sz = name;
        }
        else
        {
            cout << "cfoo的有参构造" << endl;
            int nLen = strlen(sz) + 1;
            m_sz = new char[nLen];
            strcpy_s(m_sz, nLen, sz);
        }
    }

    CFoo(const CFoo& foo)
    {
        cout << "cfoo拷贝构造" << endl;
        *this = foo;
    }
    
    /*CFoo(CFoo&& foo)
    {
        m_sz = foo.m_sz;
        foo.m_sz = nullptr;
    }*/

    CFoo& operator=(const CFoo& foo)
    {
        cout << "cfoo等号运算符重载" << endl;
        int nLen = strlen(foo.m_sz) + 1;
        m_sz = new char[nLen];
        strcpy_s(m_sz, nLen, foo.m_sz);
        return *this;
    }

    ~CFoo()
    {
        if (m_sz != nullptr)
        {
            delete[]m_sz;
        }
    };

    char* Data() { return m_sz; }

private:
    char* m_sz;
};

int main()
{
    TCList<CFoo> lst;
    CFoo foo("hello");
    lst.PushTail(foo);
    /*lst.PushTail(CFoo("11111"));
    lst.PushTail(CFoo("222222"));
    lst.PushTail(CFoo("333333"));
    lst.PushTail(CFoo("world"));*/
    return 0;
}