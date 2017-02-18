/*!
 * \file 1048. Find Coins.cpp
 * \date 2017/02/18 16:30
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1048
 * \note
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int main(int argc, char const* argv[])
{
	int N, M;
	int coin[100001];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &coin[i]);
	sort(&coin[0], &coin[N]);
	for (int i = 0, j = N-1; i!=j;)
	{
		if (coin[i] + coin[j] < M)
		{
			i++;
		}
		else if (coin[i] + coin[j] == M)
		{
			printf("%d %d", coin[i], coin[j]);
			return 0;
		}
		else
		{
			j--;
		}
	}
	printf("No Solution");
	return 0;
}