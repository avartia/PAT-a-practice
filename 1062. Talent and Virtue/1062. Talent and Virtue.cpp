/*!
 * \file 1062. Talent and Virtue.cpp
 * \date 2017/02/20 16:23
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1062
 * \note
*/
#include <stdio.h>
#include <set>
#include <functional>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
struct Person
{
	int ID;
	int Virtue;
	int Talent;
	bool operator > (const Person &p1) const
	{
		if (this->Virtue + this->Talent > p1.Virtue + p1.Talent)
			return true;
		else if (this->Virtue + this->Talent < p1.Virtue + p1.Talent)
			return false;
		else
		{
			if (this->Virtue > p1.Virtue)
				return true;
			if (this->Virtue < p1.Virtue)
				return false;
			return this->ID < p1.ID;
		}
	}
};

int main(int argc, const char* argv[])
{
	set<Person, greater<Person> > Sage, Nobel, Fool, Small;
	vector<Person> sage, nobel, fool, small;
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	int ID, Virtue, Talent;
	Person tmp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &tmp.ID, &tmp.Virtue, &tmp.Talent);
		if(tmp.Virtue < L || tmp.Talent < L)
			continue;
		if (tmp.Virtue >= H  && tmp.Talent >= H)
		{
			sage.push_back(tmp);
		}
		else if (tmp.Virtue >= H && tmp.Talent < H)
			nobel.push_back(tmp);
		else if (tmp.Virtue >= tmp.Talent)
			fool.push_back(tmp);
		else
			small.push_back(tmp);
	}
	printf("%d\n", sage.size() + nobel.size() + fool.size() + small.size());
	Sage = set<Person, greater<Person> >(sage.begin(), sage.end());
	for (auto it : Sage)
	{
		printf("%08d %d %d\n", it.ID, it.Virtue, it.Talent);
	}
	Nobel = set<Person, greater<Person> >(nobel.begin(), nobel.end());
	for (auto it : Nobel)
	{
		printf("%08d %d %d\n", it.ID, it.Virtue, it.Talent);
	}
	Fool = set<Person, greater<Person> >(fool.begin(), fool.end());
	for (auto it : Fool)
	{
		printf("%08d %d %d\n", it.ID, it.Virtue, it.Talent);
	}
	Small = set<Person, greater<Person> >(small.begin(), small.end());
	for (auto it : Small)
	{
		printf("%08d %d %d\n", it.ID, it.Virtue, it.Talent);
	}
	return 0;
}