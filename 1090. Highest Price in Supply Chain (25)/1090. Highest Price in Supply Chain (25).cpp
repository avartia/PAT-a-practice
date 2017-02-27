/*!
 * \file 1090. Highest Price in Supply Chain (25).cpp
 * \date 2017/02/27 19:58
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1090
 * \note
*/
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
#pragma warning(disable:4996)
int main(int argc, const char* argv[])
{
	int N;
	double P, r;
	scanf("%d%lf%lf", &N, &P, &r);
	vector<vector<int> > chain(N);
	int t, supplier;
	for (auto i = 0; i < N; i++)
	{
		scanf("%d", &t);
		if (t == -1)
			supplier = i;
		else
			chain[t].push_back(i);
	}
	vector<int> count(N);
	fill(count.begin(), count.end(), 0);
	deque<int> u;
	u.push_back(supplier);
	// BFS
	while (!u.empty())
	{
		t = u.front();
		u.pop_front();
		for (auto i : chain[t])
		{
			count[i] = count[t] + 1;
			u.push_back(i);
		}
	}
	int max_num = *max_element(count.begin(), count.end());
	int num_retailer = 0;
	for (auto i : count)
	{		
		if (i == max_num)
			num_retailer ++;
	}
	printf("%.2f %d", P*pow(1 + r / 100, max_num), num_retailer);
	return 0;
}