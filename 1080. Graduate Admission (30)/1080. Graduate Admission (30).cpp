/*!
 * \file 1080. Graduate Admission (30).cpp
 * \date 2017/02/26 14:30
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1080
 * \note
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

struct Student
{
	int ID;
	int GE;
	int GI;
	int FinalGrade;
	int PreSchool[5];
	Student(){}
};

int main(int argc, const char* argv[])
{
	// input
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	int quota[101];
	Student stu[40001];
	int last_rank[101];
	vector<int> admitted[101];
	int school[40001];
	memset(school, -1, sizeof(school));
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &quota[i]);
	}
	
	for (int i = 0; i < N; i++)
	{
		stu[i].ID = i;
		scanf("%d%d", &stu[i].GE, &stu[i].GI);
		stu[i].FinalGrade = (stu[i].GE + stu[i].GI);
		for (int j = 0; j < K; j++)
			scanf("%d", &stu[i].PreSchool[j]);
	}
	// algorithm
	sort(&stu[0], &stu[N], [](Student s1, Student s2)
	{
		if (s1.FinalGrade != s2.FinalGrade)
			return s1.FinalGrade > s2.FinalGrade;
		return s1.GE > s2.GE;
	});
	
	for (auto i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int t = stu[i].PreSchool[j];
			if (quota[t] > 0)
			{
				admitted[t].push_back(stu[i].ID);
				quota[t] --;
				school[i] = t;
				break;
			}
			if (i > 0 && t == school[i - 1] && stu[i].FinalGrade == stu[i-1].FinalGrade && stu[i].GE == stu[i-1].GE)
			{
				admitted[t].push_back(stu[i].ID);
				quota[t] --;
				school[i] = t;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (!admitted[i].empty())
		{
			sort(admitted[i].begin(), admitted[i].end());
			printf("%d", admitted[i].at(0));
			for (auto j = 1; j < admitted[i].size(); j++)
				printf(" %d", admitted[i][j]);
		}
		printf("\n");
	}
	return 0;
}