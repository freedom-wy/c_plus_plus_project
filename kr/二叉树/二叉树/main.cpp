#include "Ctree.h"
using namespace std;


void test1()
{
	Ctree c1;
	c1.Insert(12);
	c1.Insert(5);
	c1.Insert(18);
	c1.Insert(3);
	c1.Insert(8);
	c1.Insert(15);
	c1.Insert(25);
	c1.Insert(7);
	c1.Insert(11);
	c1.Insert(20);

	// c1.Find(3);
	//c1.Delete(7);
	/*c1.Delete(11);
	c1.Delete(8);*/
	c1.Delete(12);
	c1.Delete(11);

	cout << "hello world" << endl;
}

int main()
{
	test1();
	return 0;
}