/*!
 * \file 1064. Complete Binary Search Tree .cpp
 * \date 2017/02/20 20:54
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1064
 * \note
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

int main(int argc, const char* argv[])
{
	int N, t;
	deque<vector<int> > level;
	vector<int> tree, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		tree.push_back(t);
	}
	sort(tree.begin(), tree.end());
	while (!tree.empty())
	{
		t = 1;
		while (N > 2*t-1)
			t *= 2;
		int count = N - (t-1);
		N = N - count;
		tmp.clear();
		int i = 0;
		for (vector<int>::iterator it = tree.begin(); i < count && it != tree.end(); i++)
		{
			tmp.push_back(*it);
			it = tree.erase(it);
			if (it != tree.end())
				it++;
		}
		level.push_front(tmp);
	}
	printf("%d", *level[0].begin());
	level[0].erase(level[0].begin());
	for (auto i : level)
	{
		for (auto j : i)
			printf(" %d", j);
	}
	return 0;
}