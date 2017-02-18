/*!
 * \file 1046. Shortest Distance.cpp
 * \date 2017/02/18 14:45
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1046
 * \note
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(int argc, const char* argv[])
{
	int N, M, D[100001], t, e1, e2;
	D[0] = 0;
	// input
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		D[(i+1)%N] = D[i] + t;
	}
	int sum = D[0];
	D[0] = 0;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &e1, &e2);
		if (e2 < e1)
			swap(e1, e2);
		printf("%d\n", min(sum - D[e2-1] + D[e1-1], D[e2-1] - D[e1-1]));
	}
	return 0;
}