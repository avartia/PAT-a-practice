/*!
 * \file 1021. Deepest Root.cpp
 *
 * \author Lu Yudi
 * \date 二月 2017
 *
 * https://www.patest.cn/contests/pat-a-practise/1021
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#define MAX 10010
using namespace std;
// definition
int N;					// number of nodes
bool edge[MAX][MAX];	// edge
int d[MAX];	// dist between nodes
set<int> deepest_root;	// deepest root
int traced[MAX];
void ComputeRoot(int node, int dist);

int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream fin("input1.txt");
	streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
#endif
	// input
	int e1 = 0, e2 = 0;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> e1 >> e2;
		edge[e1][e2] = edge[e2][e1] = true;
	}
	// compute root
	int component = 0;
	int max_height = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!traced[i])
		{
			ComputeRoot(i, 0);
			component++;
		}
	}
	// 输出
	if (component > 1)
	{
		printf("Error: %d components", component);
		return 0;
	}
	// 第二次dfs
	max_height = *max_element(&d[1], &d[N + 1]);
	for (int i = 1; i <= N; i++)
	{
		if (d[i] == max_height)
			deepest_root.insert(i);
	}
	memset(traced, 0, sizeof(int)*MAX);
	memset(d, 0, sizeof(int)*MAX);
	ComputeRoot(*deepest_root.begin(), 0);
	max_height = *max_element(&d[1], &d[N + 1]);
	for (int i = 1; i <= N; i++)
	{
		if (d[i] == max_height)
			deepest_root.insert(i);
	}
	// 输出
	for (set<int>::iterator it = deepest_root.begin(); it != deepest_root.end(); it++)
		cout << *it << endl;
	return 0;
}

void ComputeRoot(int node, int dist)
{
	traced[node] = 1;
	dist += 1;
	for (int i = 1; i <= N; i++)
	{
		if (!traced[i] && edge[node][i])
		{
			d[i] = dist;
			ComputeRoot(i, dist);
		}
	}
}