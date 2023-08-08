#include <iostream>
#include <assert.h>
using namespace std;

static_assert(sizeof(void*) == 4, "不支持64位平台"); // 静态断言, 编译断言

template<class T1, class T2>
int check_value(T1& n1, T2& n2)
{
	assert(sizeof(n1) == sizeof(n2), "length must be same"); // 运行期断言
	return 0;
}

int main()
{
	int n1 = 1;
	double n2 = 1.1;
	int n3 = 2;
	check_value<int, double>(n1, n2);
	cout << sizeof(void*) << endl;
	return 0;
}