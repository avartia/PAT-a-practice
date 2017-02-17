/*!
 * \file 1018. Public Bike Management.cpp
 * \date 2017/02/17 16:43
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1018
 * \note
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
#define SIZE 510
#define INF 0xffffffff
// first line
// Cmax(<= 100), always an even number, is the maximum capacity of each station; N(<= 500), the total number of stations; Sp, the index of the problem station(the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads.
int Cmax = 0, N = 0, Sp = 0, M = 0;
// second line
// The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively.
int C[SIZE];
// next M lines
unsigned int T[SIZE][SIZE];
unsigned int d[SIZE]; // distance from 0
unsigned int p[SIZE]; // previous of current point
unsigned int Next[SIZE], finalNext[SIZE];
bool traced[SIZE];	// for DFS
					// unsigned int sent[SIZE], take[SIZE];	// number of bikes sent from PBMC and take back to PBMC
unsigned int minSent, minTake;
void DFS(int cur, int dist, int sent, int take);
int main(int argc, char const* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream fin("input.txt");
	streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
#endif
	// init 
	memset(C, 0, SIZE * sizeof(int));
	memset(T, 0xfffffff, SIZE * SIZE * sizeof(unsigned int));
	memset(d, 0xFFFFFFF, SIZE * (sizeof(unsigned int)));
	memset(p, 0, SIZE * (sizeof(unsigned int)));
	for (int i = 0; i <= N; i++)
		T[i][i] = 0;
	minSent = minTake = INF;
	// 输入
	cin >> Cmax >> N >> Sp >> M;
	C[0] = Cmax / 2;
	for (int i = 1; i <= N; i++)
		cin >> C[i];
	int Si = 0, Sj = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> Si >> Sj;
		cin >> T[Si][Sj];
		T[Sj][Si] = T[Si][Sj];	// TO BE NOTICED
	}
	// 寻找最短路径
	// Dijkstra
	d[0] = 0;
	bool visit[SIZE];
	memset(visit, false, SIZE * sizeof(bool));
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if ((double)d[j] > (double)d[i] + T[i][j])
			{
				d[j] = d[i] + T[i][j];
				p[j] = i;
			}
		}
	}
	// DFS for each shortest distance path
	// choose the min sent and take one
	DFS(0, 0, 0, 0);
	//输出
	cout << minSent << " ";
	int t = 0;
	cout << t << "->";
	while (finalNext[t] != Sp)
	{
		cout << finalNext[t] << "->";
		t = finalNext[t];
	}
	cout << Sp << " ";
	cout << minTake;
	return 0;
}

void DFS(int cur, int dist, int sent, int take)
{
	traced[cur] = true;
	int origin_sent = sent;
	int origin_take = take;
	int delta = Cmax / 2 - C[cur];
	if (delta < 0)
		take -= delta;
	else
	{
		if (take < delta)
		{
			sent += delta - take;
			take = 0;
		}
		else
		{
			take -= delta;
		}
	}
	if (cur == Sp)
	{
		if (dist == d[Sp])
		{
			if (sent < minSent || sent == minSent && take < minTake)
			{
				minSent = sent;
				minTake = take;
				memcpy(finalNext, Next, SIZE * sizeof(unsigned int));
			}
		}
	}
	else
	{
		for (int i = 0; i <= N; i++)
		{
			if (!traced[i] && T[cur][i] != INF)
			{
				dist += T[cur][i];
				Next[cur] = i;
				DFS(i, dist, sent, take);
				dist -= T[cur][i];
			}
		}
	}
	sent = origin_sent;
	take = origin_take;
	traced[cur] = false;
}