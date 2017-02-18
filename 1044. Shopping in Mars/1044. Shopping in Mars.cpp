/*!
 * \file 1044. Shopping in Mars.cpp
 * \date 2017/02/18 13:02
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1044
 * \note
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, const char* argv[])
{
	int N, M, D[100001];
	int min_waste = 100000000;
	vector<int> solution_start, solution_end;
	// input
	// cin >> N >> M;
	scanf("%d%d", &N, &M);
	for (auto i = 1; i <= N; i++)
		scanf("%d", &D[i]);
	// algorithm
	int tmp = 0;
	for (int i = 1, j = 0; i <= N && j <= N; )
	{
		if (tmp < M)
		{
			tmp += D[++j];
		}
		else
		{
			if (tmp - M < min_waste)
			{
				solution_start.clear();
				solution_end.clear();
				solution_start.push_back(i);
				solution_end.push_back(j);
				min_waste = tmp - M;
			}
			else if (tmp - M == min_waste)
			{
				solution_start.push_back(i);
				solution_end.push_back(j);
			}
			tmp -= D[i++];
		}
	}
	for (int i = 0; i < solution_start.size(); i++)
	{
		printf("%d-%d\n", solution_start[i], solution_end[i]);
	}
	return 0;
}
