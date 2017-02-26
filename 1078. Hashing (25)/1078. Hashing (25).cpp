/*!
 * \file 1078. Hashing (25).cpp
 * \date 2017/02/26 13:28
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1078
 * \note
*/
#include <stdio.h>
#include <math.h>
#include <cstring>
using namespace std;
bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i <= (int)sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

#pragma warning(disable:4996)
int main(int argc, const char* argv[]) 
{
	int MSize, N, M;
	scanf("%d%d", &MSize, &N);
	M = MSize;
	while (!isPrime(M)) { M++; }
	int hash_table[10007];
	int hash_index[10007];
	memset(hash_table, 0, 10007 * sizeof(int));
	for (auto i = 0; i < N; i++)
	{
		int quad = 0, t;
		scanf("%d", &t);
		while (hash_table[(quad*quad + t) % M] != 0 && quad < M) { quad++; }
		if (quad == M)
			hash_index[i] = -1;
		else
		{
			hash_table[(quad*quad + t) % M] = t;
			hash_index[i] = (quad*quad + t) % M;
		}
	}
	if (hash_index[0] == -1)
		printf("-");
	else
		printf("%d", hash_index[0]);
	for (auto i = 1; i < N; i++)
	{
		if (hash_index[i] == -1)
			printf(" -");
		else
			printf(" %d", hash_index[i]);
	}
	return 0;
}