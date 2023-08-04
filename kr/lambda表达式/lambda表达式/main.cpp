#include <iostream>
using namespace std;

typedef int(*FUNC)(int, float); // 函数指针

int main()
{
	FUNC pfn = [](int n, float f)->int {
		return n + f * 8;
	};

	int val = pfn(1, 1.1f);
	cout << val << endl;
	cout << "hello world" << endl;
	return 0;
}