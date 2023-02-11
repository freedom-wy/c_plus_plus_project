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
	// ����vector����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����Ϊ: " << it->name << ", ����Ϊ: " << it->score << endl;
	}
}

void SetScore(vector<Person>& v)
{
	// ���÷���
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// ����deque����
		deque<int> d1;
		// ��ֲ�����������deque����
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d1.push_back(score);
		}

		sort(d1.begin(), d1.end());
		
		// ȥ����߷ֺ���ͷ�
		d1.pop_front();
		d1.pop_back();
		// ��ƽ����
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
		string name = "ѡ��: ";
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