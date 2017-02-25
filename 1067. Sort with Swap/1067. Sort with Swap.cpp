/*!
 * \file 1067. Sort with Swap.cpp
 * \date 2017/02/25 10:27
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1067
 * \note
*/
#include <stdio.h>
#include <stdlib.h>
#define Max 100000
int A[Max];
int flag[Max]; /*flag[i] checks whether A[i] has been routed, if so set flag[i] to 1*/
int main()
{
	int N, i, k = 0, count = 0, min_of_swap;
	/* N stands for the number of element to be input
	k stands for the number of such i's that A[i]==i
	count stands for the number of circuits like A[1]=2 -> A[2]=4 -> A[4]=1*/
	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d", &A[i]);
		if (A[i] == i)
		{
			k++;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (flag[i] == 1)
			continue;
		count++;
		while (1)
		{
			if (flag[i] == 0)
			{
				flag[i] = 1;
				i = A[i];
			}
			else
				break;
		}
	}
	min_of_swap = N - 2 - 2 * k + count;
	if (A[0] == 0)/*a special condition: if A[0]=0 at first, then it'll need two more swaps*/
		min_of_swap += 2;
	printf("%d", min_of_swap);
}