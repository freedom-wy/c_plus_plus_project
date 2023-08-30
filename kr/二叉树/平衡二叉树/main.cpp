// 任意节点的左子树和右子树的高度相差不超过1
#include "avl_tree.h"
using namespace std;


void test1()
{
	AVLTree at;
	at.Insert(50); 
	at.Insert(30);
	at.Insert(80);
	at.Insert(20);
	at.Insert(40);
	at.Insert(75);
	at.Insert(100);
	at.Insert(25);
	at.Insert(35);
	at.Insert(45);
	at.Insert(90);
	cout << "hello world" << endl;
}

int main()
{
	test1();
	return 0;
}
