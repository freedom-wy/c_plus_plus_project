#include <iostream>
using namespace std;


/*
在C++中，对类、函数和变量的命名遵循一定的约定和最佳实践，以确保代码的清晰和可维护性。以下是一些常见的命名方法：

1. **类命名**：
   - 使用驼峰命名法（CamelCase），其中每个单词的首字母大写。例如：`MyClass`, `AudioProcessor`。
   - 类名应该是名词或名词短语，清晰地表明类的功能或特性。

2. **函数命名**：
   - 通常也使用驼峰命名法，但首字母小写。例如：`calculateTotal`, `readFromFile`。
   - 函数名应该是动词或动词短语，准确描述函数的行为或操作。
   - 对于访问器（getter）和修改器（setter）函数，通常使用`get`和`set`作为前缀。例如：`getAge`, `setName`。

3. **变量命名**：
   - 变量名通常使用小写字母，单词之间用下划线分隔，这称为蛇形命名法（snake_case）。例如：`current_speed`, `file_name`。
   - 变量名应该具有描述性，使得其他开发者能够理解其用途。
   - 对于全局变量或类的成员变量，有时会使用特定的前缀或后缀，如`g_`或`m_`来区分。例如：`g_globalCounter`, `m_memberData`。

4. **常量和宏命名**：
   - 常量和宏通常使用全大写字母，单词之间用下划线分隔。例如：`MAX_HEIGHT`, `DEFAULT_VALUE`。

5. **模板类型参数命名**：
   - 模板类型参数通常使用大写字母，如`T`, `U`, `V`，或者更具描述性的名称，如`KeyType`, `ValueType`。

记住，这些只是指导原则，不同的项目或团队可能会有自己的命名约定。重要的是在整个项目中保持一致性。
*/


// 默认构造和拷贝构造相同



// 拷贝构造
/*
(1)如果一个类A没有拷贝构造函数，但是含有一个类类型CTB的成员变量m_ctb。该类型CTB含有拷贝构造函数，那么当代码中有涉及到类A的拷贝构造时，编译器就会为类A合成一个拷贝构造函数。
编译器合成的拷贝构造函数往往都是干一些特殊的事情。如果只是一些类成员变量值的拷贝这些事，编译器是不用专门合成出拷贝构造函数来干的，编译器内部就干了；
(2)如果一个类CTBSon没有拷贝构造函数，但是它有一个父类CTB，父类有拷贝构造函数，
当代码中有涉及到类CTBSon的拷贝构造时，编译器会为CTBSon合成一个拷贝构造函数 ，调用父类的拷
(3)如果一个类CTBSon没有拷贝构造函数，但是该类声明了或者继承了虚函数。当代码中有涉及到类CTBSon的拷贝构造时，编译器会为CTBSon合成一个拷贝构造函数 ,往这个拷贝构造函数里插入语句：
这个语句的含义 是设定类对象myctbson2的虚函数表指针值。虚函数表指针，虚函数表等概念
(4)如果 一个类没有拷贝构造函数， 但是该类含有虚基类当代码中有涉及到类的拷贝构造时，编译器会为该类合成一个拷贝构造函数；
综上所述：涉及由拷贝构造去构造一个函数时，如果有虚函数，类成员，虚基类，父类拷贝构造函数等特殊事情需要处理时，就会生成默认的拷贝构造函数。
*/





// 无继承关系，仅调用
class AClass
{
public:
	int a_number;
public:
	// 若AClass中不写默认构造方法,则不会创建默认构造方法, 若写了构造方法,则在创建类时候会创建构造方法
	AClass()
	{
		this->a_number = 0;
		cout << "AClass的默认构造方法" << endl;
	}
	AClass(int number)
	{
		this->a_number = number;
	}
};

class BClass
{
	// 若AClass中写了默认构造方法并且在BClass中进行了调用,则会生成AClass的默认构造和BClass的默认构造
public:
	int b_number;
	AClass a1;
};

// 有继承关系
class CClass
{
public:
	int c_number;
public:
	CClass()
	{
		cout << "默认构造方法" << endl;
		this->c_number = 0;
	}
	CClass(int number)
	{
		cout << "有参构造方法" << endl;
		this->c_number = number;
	}
};

class DClass: public CClass
{
	// 仅继承,编译器会为子类生成默认构造方法
};

class EClass
{
	// 当类中有虚函数时,会生成默认构造
	virtual void eclassFunction()
	{
		cout << "虚函数的输出" << endl;
	}
};

class FClass
{
	// 未创建拷贝构造
public:
	int f_number;
};

class GClass
{
public:
	FClass f; // 即使在成员变量中使用了FClass也未创建拷贝构造
	int g_number;
};

class HClass
{
public:
	int h_number;
	HClass()
	{
		this->h_number = 0;
		cout << "HClass默认构造方法" << endl;
	}
	HClass(int number)
	{
		cout << "HClass默认有参方法" << endl;
		this->h_number = number;
	}
	HClass(const HClass& obj) // 写拷贝构造后必须要写默认构造
	{
		this->h_number = obj.h_number;
		cout << "HClass的拷贝构造方法" << endl;
	}
};

class IClass
{
public:
	HClass h;
};




int main()
{
	/*IClass* i1 = new IClass();
	i1->h.h_number = 1;
	IClass* i2 = i1;
	cout << "h_number的值为: " << i2->h.h_number << endl;
	cout << "==============" << endl;*/
	IClass i3;
	i3.h.h_number = 3;
	IClass i4 = i3;
	cout << "h_number的值为: " << i4.h.h_number << endl;
	return 0;
}

/*AClass* a = new AClass();
	a->a_number = 1;
	delete a;*/
	/*BClass* b = new BClass();
	delete b;*/
	/*CClass* c = new CClass();
	delete c;*/
	/*EClass* e = new EClass();
	delete e;*/
	/*FClass* f1 = new FClass();
	f1->f_number = 1;
	FClass* f2 = f1;
	cout << "f_number的值为: " << f2->f_number << endl;*/
	/*GClass* g1 = new GClass();
	g1->g_number = 2;
	g1->f.f_number = 3;
	GClass* g2 = g1;
	cout << "f_number的值为: " << g2->f.f_number << ", g_number的值为: " << g2->g_number << endl;*/