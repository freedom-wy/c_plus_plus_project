#include "CVector.h"


//class CA
//{
//public:
//    CA(int n) :m_p(new int(n)) { cout << "CA::CA(int)" << endl; }
//    CA(const CA& obj) : m_p(new int(*obj.m_p)) { cout << "CA::CA(const CA& obj)" << endl; }
//    CA(CA&& obj)    //移动构造，减少内存的额外的申请和释放，提高效率
//    {
//        m_p = obj.m_p;
//        obj.m_p = nullptr;
//    }
//    ~CA()
//    {
//        if (m_p != nullptr)
//        {
//            delete m_p;
//        }
//        cout << "CA::~CA" << endl;
//    }
//private:
//    int* m_p;
//};
//
//CA Foo()
//{
//    CA a(12);
//    return a;
//}
//
//int main()
//{
//    //CA b = Foo();   //返回值优化，去掉了a拷贝构造临时对象的步骤
//    CA a(12);
//    CA a3 = (std::move(a));
//    return 0;
//}

int main()
{
	//"2";
	//"1 2 3 4 5 6 0 0 0 0";
	//buf + nidx; // 原地址
	//buf + nidx + 1; // 目的地
	//(len - nidx)* size;
	test1();
	cout << "hello world" << endl;
	return 0;
}