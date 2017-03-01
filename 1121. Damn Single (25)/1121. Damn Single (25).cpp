/*!
 * \file 1121. Damn Single (25).cpp
 * \date 2017/03/01 14:15
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1121
 * \note
*/
#include <stdio.h>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char* argv[])
{
	int companion[100000];
	bool present[100000];
	memset(companion, -1, sizeof(companion));
	memset(present, false, sizeof(present));
	int N, M, t1, t2, t;
	// input
	scanf("%d", &N);
	for (auto i = 0; i < N; i++)
	{
		scanf("%d%d", &t1, &t2);
		companion[t1] = t2;
		companion[t2] = t1;
	}
	int query[10000];
	scanf("%d", &M);
	for (auto i = 0; i < M; i++)
	{
		scanf("%d", &t);
		present[t] = true;
		query[i] = t;
	}
	// check for lonely guy
	vector<int> lonely;
	for (auto i = 0; i < M; i++)
	{
		if (companion[query[i]] != -1 && present[companion[query[i]]]);
		else
			lonely.push_back(query[i]);
	}
	set<int> lonely_guy(lonely.begin(), lonely.end());
	printf("%d\n", lonely_guy.size());
	if (!lonely_guy.empty())
	{
		printf("%05d", *lonely_guy.begin());
		lonely_guy.erase(lonely_guy.begin());
		for (auto i : lonely_guy)
		{
			printf(" %05d", i);
		}
	}
	return 0;
}