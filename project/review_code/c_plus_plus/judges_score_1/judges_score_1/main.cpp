#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Person
{
public:
	string name;
	int score;
public:
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	void SetScore(int score)
	{
		this->score = score;
	}
};

void PrintPersonInfo(vector<Person>& v)
{
	// 遍历vector容器
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名为: " << it->name << ", 分数为: " << it->score << endl;
	}
}

void SetScore(vector<Person>& v)
{
	// 设置分数
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 创建deque容器
		deque<int> d1;
		// 打分并将分数放入deque容器
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d1.push_back(score);
		}

		sort(d1.begin(), d1.end());
		
		// 去掉最高分和最低分
		d1.pop_front();
		d1.pop_back();
		// 求平均分
		int sum = 0;
		for (int i = 0; i < d1.size(); i++)
		{
			sum += d1[i];
		}

		int avg = sum / d1.size();
		it->score = avg;
	}
}

void test1()
{
	srand((unsigned int)time(NULL));
	vector<Person> v1;
	string sub_name = "ABCDE";
	for (int i = 0; i < sub_name.size(); i++)
	{
		string name = "选手: ";
		name += sub_name[i];
		Person p(name, 0);
		v1.push_back(p);
	}

	SetScore(v1);

	PrintPersonInfo(v1);
}


int main()
{
	test1();
	return 0;
}