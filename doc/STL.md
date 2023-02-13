#### STL
```c++
// v.begin()返回迭代器，这个迭代器指向容器中第一个数据
// v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
// vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
```
#### stack容器
```txt
stack是一种先进后出的数据结构，它只有一个出口
栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为，行为有入栈和出栈
```
#### queue容器
```txt
queue是一种先进先出的数据结构， 他有两个出口
队列中只有队头和队尾可以被外界使用， 因此队列不允许有遍历行为，入队和出队
```
#### set容器
```txt
所有元素都会在插入时自动排序
set不允许容器中有重复的元素，multiset允许容器中有重复的元素
set插入数据的同时会返回插入结果，表示插入是否成功
set容器默认排序规则为升序, 可以通过仿函数改变排序规则
```
```c++
void test14()
{
	class MyCompare
	{
	public:
		bool operator()(int v1, int v2)const
		{
			// 重写括号运算符, 降序
			return v1 > v2;
		}
	};
	set<int, MyCompare> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	
	for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test14();
	return 0;
}
```
#### map容器
```txt
map中所有容器都为pair
pair中第一个元素为key, 起到索引作用, 第二个元素为value, 为值, 根据key排序
map不允许容器中有重复key值元素
multimap允许容器中有重复key值元素
```
```c++
void PrintMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}
}

void test15()
{
	map<int, int> m;
	// 两种插入方法
	m.insert(make_pair(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	PrintMap(m);
}
```
#### map自定义对比
```c++
void test16()
{
	class Person
	{
	public:
		string name;
		int age;

		Person(string name, int age)
		{
			this->name = name;
			this->age = age;
		}
	};

	class MyCompare
	{
	public:
		bool operator()(Person p1, Person p2)const
		{
			return p1.age > p2.age;
		}
	};

	map<Person, int, MyCompare> m1;
	m1.insert(make_pair(Person("张三", 18), 1));
	m1.insert(pair<Person, int>(Person("李四", 20), 2));
	m1.insert(make_pair(Person("王五", 11), 3));
	m1.insert(make_pair(Person("赵六", 30), 4));
	m1.insert(make_pair(Person("陈七", 25), 5));

	for (map<Person, int, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "key: " << it->first.name << ", age: " << it->first.age << endl;
	}
	
}
```