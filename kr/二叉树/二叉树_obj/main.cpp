#include "obj_tree.h"
using namespace std;

int main()
{
	Objtree ot;
	char name[] = "hello";
	ot.Insert(new Person(12, name, 12));
	ot.Insert(new Person(5, name, 5));
	ot.Insert(new Person(18, name, 18));
	ot.Insert(new Person(3, name, 3));
	ot.Insert(new Person(8, name, 8));
	ot.Insert(new Person(15, name, 15));
	ot.Insert(new Person(25, name, 25));
	ot.Insert(new Person(7, name, 7));
	ot.Insert(new Person(11, name, 11));
	ot.Insert(new Person(20, name, 20));
}