### x32dbg工具使用方法
```c++
#include <iostream>
using namespace std;

// func add
int add(int x, int y)
{
	int z = 0;
	z = x+y;
	return z;
}


int main()
{
	int n = 0; // set n
	n = add(1, 3); // call add
	cout << n << endl;
	return 0;
}
// vs2019编译
```
#### 使用方法
```txt
1、load程序后停留在ntdll.dll，按f9进入程序领空
2、按f7或f8
3、点第一个call, 按f2断点, 按f9运行到此, 按f7进入
4、点第二个call, 按f2断点, 按f9运行到此, 按f7进入
5、找特征, movzx, test, je, mov, mov, push, call, add, call 该函数为主函数上层的上层, 下断点, f9运行到此, 按f7进入
6、找最后一个call, 下断点, 按f9, 按f7
7、第一个即为主函数, f7
```