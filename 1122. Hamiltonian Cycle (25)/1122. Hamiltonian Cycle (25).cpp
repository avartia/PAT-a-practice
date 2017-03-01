/*!
 * \file 1122. Hamiltonian Cycle (25).cpp
 * \date 2017/03/01 14:34
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1122
 * \note
*/
#include <iostream>
using namespace std;


bool edge[201][201];
int main(int argc, const char* argv[])
{
	int N, M, K, v1, v2;
	cin >> N >> M;
	for (auto i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		edge[v1][v2] = edge[v2][v1] = true;
	}
	cin >> K;
	int n;
	for (auto i = 0; i < K; i++)
	{
		cin >> n;
		int head;
		int v = 0, prev = 0;
		bool flag = (n == N+1);

		for (auto j = 0; j < n; j++)
		{
			cin >> v;
			if (j == 0)
			{
				head = v;
				prev = v;
			}
			else
			{
				if (j < n - 1 && head == v)
				{
					flag = false;
				}
				else if(!edge[prev][v])
				{
					flag = false;
				}
				else if(j == n-1)
				{
					if (head != v)
					{
						flag = false;
					}
				}
				prev = v;
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
