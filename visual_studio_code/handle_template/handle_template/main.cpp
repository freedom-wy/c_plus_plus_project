#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//template<typename T> // 模板关键字, T是一个通用数据类型
//void MySwap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}

class Findfive
{
public:
	bool operator()(int val)
	{
		return val == 5;
	}
};

void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), Findfive());
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了: " << *it << endl;
	}
}

int main()
{
	test1();
	return 0;
}