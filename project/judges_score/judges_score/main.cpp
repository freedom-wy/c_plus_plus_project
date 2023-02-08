#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Person
{
	// ѡ����
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
		string name = "ѡ��";
		name += nameSeed[i];
		int score = 0; // ��ʼ������
		Person p(name, score);
		v.push_back(p);
	}
}

void printPersonInfo(vector<Person>& p)
{
	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "ѡ������: " << (*it).name << ", ����: " << (*it).score << endl;
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// ����ί���, ȥ����߷ֺ���ͷ�, ��ƽ��ֵ
		deque<int>d_score;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d_score.push_back(score);
		}
		// ����
		sort(d_score.begin(), d_score.end());
		/*for (deque<int>::iterator it = d_score.begin(); it != d_score.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;*/
		// ȥ����߷ֺ���ͷ�
		d_score.pop_back();
		d_score.pop_front();

		// ��ƽ����
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
	// 1������ѡ�����ѡ������
	vector<Person>v1;
	// 2����ѡ�ַ���vector������
	putPersonToVector(v1);
	//printPersonInfo(v1);
	setScore(v1);
	printPersonInfo(v1);
	return 0;
}