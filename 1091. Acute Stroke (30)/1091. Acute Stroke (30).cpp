/*!
 * \file 1091. Acute Stroke (30).cpp
 * \date 2017/02/27 20:14
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1091
 * \note
*/
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
struct Coordinate
{
	int x, y, z;
};
int main(int argc, const char* argv[])
{
	int M, N, L, T;
	scanf("%d%d%d%d", &M, &N, &L, &T);
	bool stroke[L][M][N];
	bool traced[L][M][N];
	int count = 0;
	memset(traced, false, sizeof(bool)*M*N*L);
	for (auto i = 0; i < L; i++)
	{
		for (auto j = 0; j < M; j++)
		{
			for (auto k = 0; k < N; k++)
				scanf("%d", &stroke[i][j][k]);
		}
	}
	queue<Coordinate> u;
	Coordinate tmp;
	// BFS
	for (auto i = 0; i < L; i++)
	{
		for (auto j = 0; j < M; j++)
		{
			for (auto k = 0; k < N; k++)
			{
				if (stroke[i][j][k] && !traced[i][j][k])
				{
					tmp.x = i; tmp.y = j; tmp.z = k;
					traced[i][j][k] = true;
					u.push(tmp);
					int tmp_cnt = 0;
					while (!u.empty())
					{
						Coordinate t = u.front();
						u.pop();
						tmp_cnt++;
						if (t.x > 0 && stroke[t.x - 1][t.y][t.z] && !traced[t.x - 1][t.y][t.z])
						{
							traced[t.x - 1][t.y][t.z] = true;
							tmp = t;
							tmp.x --;
							u.push(tmp);
						}
						if (t.x < L-1 && stroke[t.x + 1][t.y][t.z] && !traced[t.x + 1][t.y][t.z])
						{
							traced[t.x + 1][t.y][t.z] = true;
							tmp = t;
							tmp.x++;
							u.push(tmp);
						}
						if (t.y > 0 && stroke[t.x][t.y - 1][t.z] && !traced[t.x][t.y-1][t.z])
						{
							traced[t.x][t.y - 1][t.z] = true;
							tmp = t;
							tmp.y--;
							u.push(tmp);
						}
						if (t.y < M - 1 && stroke[t.x][t.y+1][t.z] && !traced[t.x][t.y+1][t.z])
						{
							traced[t.x][t.y + 1][t.z] = true;
							tmp = t;
							tmp.y++;
							u.push(tmp);
						}
						if (t.z > 0 && stroke[t.x][t.y][t.z-1] && !traced[t.x][t.y][t.z-1])
						{
							traced[t.x][t.y][t.z - 1] = true;
							tmp = t;
							tmp.z--;
							u.push(tmp);
						}
						if (t.z < N - 1 && stroke[t.x][t.y][t.z+1] && !traced[t.x][t.y][t.z+1])
						{
							traced[t.x][t.y][t.z + 1] = true;
							tmp = t;
							tmp.z++;
							u.push(tmp);
						}
					}
					if (tmp_cnt >= T)
					{
						count += tmp_cnt;
					}
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}