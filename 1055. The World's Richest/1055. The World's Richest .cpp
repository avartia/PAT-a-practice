/*!
 * \file 1055. The World's Richest .cpp
 * \date 2017/02/19 13:10
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1055
 * \note
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)
struct Person
{
	char Name[9];
	int Age;
	int Net_Worth;
};

int main(int argc, char const* argv[])
{
	int N, K, M, Amin, Amax;
	Person person[100001];
	vector<Person> part;
	scanf("%d%d", &N, &K);
	for (size_t i = 0; i < N; i++)
	{
		scanf("%s%d%d", person[i].Name, &person[i].Age, &person[i].Net_Worth);
	}
	// ÅÅÐò
	sort(&person[0], &person[N], [](const Person &p1, const Person &p2) {return p1.Net_Worth > p2.Net_Worth || (p1.Net_Worth == p2.Net_Worth && (p1.Age < p2.Age || p1.Age == p2.Age && strcmp(p1.Name, p2.Name) < 0)); });
	// 
	int ageCount[201] = { 0 };
	vector<int> filter;
	for (int i = 0; i < N; i++)
	{
		// max M is 100
		// ¼ôÖ¦
		if (++ageCount[person[i].Age] < 101)
		{
			filter.push_back(i);
		}
	}
	
	for (size_t i = 0; i < K; i++)
	{
		scanf("%d%d%d", &M, &Amin, &Amax);
		printf("Case #%d:\n", i + 1);
		int count = 0;
		for (auto it : filter)
		{
			if (person[it].Age >= Amin && person[it].Age <= Amax && count < M)
			{
				printf("%s %d %d\n", person[it].Name, person[it].Age, person[it].Net_Worth);
				count++;
			}
		}
		if (count == 0)
			printf("None\n");
	}
	return 0;
}