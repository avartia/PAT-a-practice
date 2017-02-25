/*!
 * \file 1074. Reversing Linked List (25).cpp
 * \date 2017/02/25 19:10
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1074
 * \note
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int main(int argc, const char* argv[])
{
	int Next[100000], Prev[100000], Data[100000], Index[100000];
	int N, K, first_node;
	int tmp_node, node, data, next;
	scanf("%05d%d%d", &first_node, &N, &K);
	Prev[first_node] = -1;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &node, &data, &next);
		Next[node] = next;
		if(next!=-1)
			Prev[next] = node;
		Data[node] = data;
	}
	// 第一遍遍历 先给出node在linked list中的正向索引
	// 注意多个链表存在的情况
	// 找出起点所在的链表，更新N
	int t = 0;
	node = first_node;
	int count = 0;
	while (node != -1)
	{
		Index[t] = node;
		t++;
		node = Next[node];
		count++;
	}
	N = count;
	// 第二遍遍历
	t = 0;
	node = first_node;
	while (t < (N / K) *K)
	{
		if((++t) % K )
			node = Next[node];
		else
		{
			tmp_node = node;
			for (int i = K - 1; i >= 0; i--)
			{
				if (i == 0)
				{
					if (Next[node] != -1)
					{
						if((N / K) *K - t >= K-1)
							printf("%05d %d %05d\n", tmp_node, Data[tmp_node], Index[t+K-1]);
						else
							printf("%05d %d %05d\n", tmp_node, Data[tmp_node], Next[node]);
					}
					else
						printf("%05d %d %d\n", tmp_node, Data[tmp_node], Next[node]);
				}
				else
					printf("%05d %d %05d\n", tmp_node, Data[tmp_node], Prev[tmp_node]);
				tmp_node = Prev[tmp_node];
			}
			node = Next[node];
		}
	}
	while (t < N)
	{
		if(Next[node] != -1)
			printf("%05d %d %05d\n", node, Data[node], Next[node]);
		else
			printf("%05d %d %d\n", node, Data[node], Next[node]);
		t++;
		node = Next[node];
	}
	return 0;
}