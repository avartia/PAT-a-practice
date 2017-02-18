/*!
 * \file 1045. Favorite Color Stripe.cpp
 * \date 2017/02/18 13:51
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1045
 * \note
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, L, favor[201], stripe[10001];
int len[201][10001];

int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream ifs("input.txt");
	streambuf *cinbackup = cin.rdbuf(ifs.rdbuf());
#endif
	// input
	scanf("%d", &N);
	scanf("%d", &M);
	for (auto i = 1; i <= M; i++)
		scanf("%d", &favor[i]);
	scanf("%d", &L);
	for (auto i = 1; i <= L; i++)
		scanf("%d", &stripe[i]);
	// algorithm
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			if (favor[i] == stripe[j])
				len[i][j] = len[i][j-1] + 1;
			else
			{
				len[i][j] = max(len[i - 1][j], len[i][j - 1]);
			}
		}
	}
	printf("%d", len[M][L]);
	return 0;
}