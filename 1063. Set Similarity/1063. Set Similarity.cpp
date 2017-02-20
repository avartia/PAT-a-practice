/*!
 * \file 1063. Set Similarity.cpp
 * \date 2017/02/20 20:18
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1063
 * \note
*/
#include <stdio.h>
#include <algorithm>
#include <set>
#include <iterator>
#include <vector>
using namespace std;
#pragma  warning(disable:4996)
int main(int argc, const char* argv[])
{
	int N, M, K, t, s1, s2;
	vector<int> v[50];
	set<int> s[50];
	vector<int> inter_set, union_set;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &M);
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &t);
			v[i].push_back(t);
		}
		s[i] = set<int>(v[i].begin(), v[i].end());
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d%d", &s1, &s2);
		inter_set.clear();
		union_set.clear();
		set_intersection(s[s1 - 1].begin(), s[s1 - 1].end(), s[s2 - 1].begin(), s[s2 - 1].end(), back_inserter(inter_set));
		set_union(s[s1 - 1].begin(), s[s1 - 1].end(), s[s2 - 1].begin(), s[s2 - 1].end(), back_inserter(union_set));
		printf("%.1f%%\n", ((double)inter_set.size() / union_set.size())*100);
	}
	return 0;
}