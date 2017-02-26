/*!
 * \file 1076. Forwards on Weibo (30).cpp
 * \date 2017/02/26 10:41
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1076
 * \note
*/
#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
int main(int argc, const char* argv[])
{
	int N, L, M, K, f;
	scanf("%d%d", &N, &L);
	vector<vector<int> > followers(N+1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &M);
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &f);
			followers[f].push_back(i);
		}
	}
	deque<int> level, tmp_level;
	bool traced[1001];
	int UsrID, count, depth[1001];
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &UsrID);
		// memset(traced, false, sizeof(bool) * 1001);
		memset(depth, -1, sizeof(int) * 1001);
		level.push_back(UsrID);
		depth[UsrID] = 0;
		count = 0;
		// BFS 
		while(!level.empty())
		{
			auto j = level.front();
			level.pop_front();
			if (depth[j] >= L)
				break;
			for (auto k : followers[j])
			{
				if (depth[k] == -1)
				{
					level.push_back(k);
					depth[k] = depth[j] + 1;
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}