#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Person
{
	// 选手类
public:
	string name;
	int score;
public:
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
};

void putPersonToVector(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0; // 初始化分数
		Person p(name, score);
		v.push_back(p);
	}
}

void printPersonInfo(vector<Person>& p)
{
	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "选手姓名: " << (*it).name << ", 分数: " << (*it).score << endl;
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 由评委打分, 去掉最高分和最低分, 求平均值
		deque<int>d_score;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d_score.push_back(score);
		}
		// 排序
		sort(d_score.begin(), d_score.end());
		/*for (deque<int>::iterator it = d_score.begin(); it != d_score.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;*/
		// 去掉最高分和最低分
		d_score.pop_back();
		d_score.pop_front();

		// 求平均分
		int sum = 0;
		for (int i = 0; i < d_score.size(); i++)
		{
			sum += d_score[i];
		}

		int avg = sum / d_score.size();
		
		it->score = avg;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	// 1、创建选手类和选手容器
	vector<Person>v1;
	// 2、将选手放入vector容器中
	putPersonToVector(v1);
	//printPersonInfo(v1);
	setScore(v1);
	printPersonInfo(v1);
	return 0;
}