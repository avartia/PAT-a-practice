/*!
 * \file 1072. Gas Station (30).cpp
 * \date 2017/02/25 16:14
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1072
 * \note
*/
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#pragma warning(disable:4996)
#define MAXN 1000
#define MAXM 10
using namespace std;

int N, M, K, Ds;
// distance between houses and distances between gas stations and house and distances between gas stations
int hg_dist[MAXN + MAXM + 2][MAXN + MAXM + 2];
// distance 
unsigned int gas_dist[MAXN + MAXM + 2];
bool traced[MAXN + MAXM + 2];
int main(int argc, const char* argv[])
{
	scanf("%d%d%d%d", &N, &M, &K, &Ds);
	char P1[5], P2[5];
	int dist, p1, p2;
	for (int i = 0; i < K; i++)
	{
		scanf("%s %s%d", P1, P2, &dist);
		if (P1[0] == 'G' && P2[0] != 'G')
		{
			p1 = atoi(P1 + 1);
			p2 = atoi(P2);
			hg_dist[p1][p2+M] = hg_dist[p2+M][p1] = dist;
		}
		else if (P2[0] == 'G' && P1[0] != 'G')
		{
			p1 = atoi(P1);
			p2 = atoi(P2 + 1);
			hg_dist[p2][p1 + M] = hg_dist[p1 + M][p2] = dist;
		}
		else if (P1[0] == 'G' && P2[0] == 'G')
		{
			p1 = atoi(P1+1);
			p2 = atoi(P2+1);
			hg_dist[p1][p2] = hg_dist[p2][p1] = dist;
		}
		else
		{
			p1 = atoi(P1);
			p2 = atoi(P2);
			hg_dist[p1 + M][p2 + M] = hg_dist[p2 + M][p1 + M] = dist;
		}
	}
	int max_dist = 0;
	double min_avg_dist = 0.0;
	int index = 0;
	// dijkstra algorithm
	for (int i = 1; i <= M; i++)
	{
		memset(gas_dist, 0xFFFFFFFF, (MAXN + MAXM + 2) * sizeof(int));
		memset(traced, 0, (MAXN + MAXM + 2) * sizeof(bool));
		gas_dist[i] = 0;
		int t = i;
		while (t != M + N + 1)
		{
			traced[t] = true;
			for (int j = 1; j <= N + M; j++)
			{
				if (hg_dist[t][j] != 0 && (double)gas_dist[j] > (double)gas_dist[t] + hg_dist[t][j])
					gas_dist[j] = gas_dist[t] + hg_dist[t][j];
			}
			unsigned int min_gas_dist = 0xffffffff;
			t = M+N+1;
			for (int j = 1; j <= N + M; j++)
			{
				if (!traced[j])
				{
					if (gas_dist[j] < min_gas_dist)
					{
						t = j;
						min_gas_dist = gas_dist[j];
					}
				}
			}
		}
		if (find_if(&gas_dist[M + 1], &gas_dist[N + M + 1], [](int a) {return a > Ds; }) == &gas_dist[N + M + 1])
		{
			int tmp_min_dist = *min_element(&gas_dist[M + 1], &gas_dist[N + M + 1]);
			double tmp_avg_dist = accumulate(&gas_dist[M + 1], &gas_dist[N + M + 1], 0.0) / N;
			if (tmp_min_dist > max_dist || (tmp_min_dist == max_dist && tmp_avg_dist < min_avg_dist || min_avg_dist == 0.0))
			{
				max_dist = tmp_min_dist;
				min_avg_dist = tmp_avg_dist;
				index = i;
			}
		}
	}
	if (index == 0)
		printf("No Solution");
	else
	{
		printf("G%d\n", index);
		printf("%.1f %.1f", (double)max_dist, min_avg_dist);
	}
	return 0;
}