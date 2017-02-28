/*!
 * \file 1094. The Largest Generation (25).cpp
 * \date 2017/02/28 10:59
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1094
 * \note
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, const char* argv[])
{
	int N, M;
	cin >> N >> M;
	vector<vector<int> > tree(N+1);
	for (auto i = 0; i < M; i++)
	{
		int ID, K;
		cin >> ID >> K;
		tree[ID] = vector<int>(K);
		for (auto j = 0; j < K; j++)
			cin >> tree[ID][j];
	}
	// level traversal
	int level = 0;
	int max_generation = 1, max_num = 1;
	deque<int> gen, tmp;
	gen.push_back(1);
	level++;
	while (!gen.empty())
	{
		tmp.clear();
		for (auto i : gen)
		{
			for (auto j : tree[i])
			{
				tmp.push_back(j);
			}
		}
		level++;
		if (tmp.size() > max_num)
		{
			max_num = tmp.size();
			max_generation = level;
		}
		gen = tmp;
	}
	cout << max_num << " " << max_generation;
	return 0;
}