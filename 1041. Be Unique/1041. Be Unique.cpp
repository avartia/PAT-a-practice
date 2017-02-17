/*!
 * \file 1041. Be Unique.cpp
 * \date 2017/02/17 22:45
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1041
 * \note
*/
#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[])
{
	int count[100000];
	int unique[100000];
	memset(count, 0, 100000 * sizeof(int));
	int N, t;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		count[t]++;
		unique[i] = t;
	}
	for (int i = 0; i < N; i++)
	{
		if (count[unique[i]] == 1)
		{
			printf("%d", unique[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
