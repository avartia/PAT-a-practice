/*!
 * \file 1079. Total Sales of Supply Chain (25).cpp
 * \date 2017/02/26 13:52
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1079
 * \note
*/
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
struct Supply
{
	bool isRetailer;
	double price;
	vector<int> ID;
	int amount;
	Supply():isRetailer(false),price(0.0), amount(0){}
};

int main(int argc, const char* argv[])
{
	int N, Ki, t;
	double P, r;
	scanf("%d%lf%lf", &N, &P, &r);
	vector<Supply> supplier(N);
	queue<int> ids;
	for (auto i = 0; i < N; i++)
	{
		scanf("%d", &Ki);
		if (Ki == 0)
		{
			supplier[i].isRetailer = true;
			scanf("%d", &supplier[i].amount);
		}
		else
		{
			for (auto j = 0; j < Ki; j++)
			{
				scanf("%d", &t);
				supplier[i].ID.push_back(t);
			}
		}
	}
	// BFS
	supplier[0].price = P;
	ids.push(0);
	double total = 0.0;
	while (!ids.empty())
	{
		t = ids.front();
		ids.pop();
		if (supplier[t].isRetailer)
			total += supplier[t].price * supplier[t].amount;
		else
		{
			for (auto i = 0; i < supplier[t].ID.size(); i++)
			{
				supplier[supplier[t].ID[i]].price = supplier[t].price * (1 + r / 100);
				ids.push(supplier[t].ID[i]);
			}
		}
	}
	printf("%.1f", total);
	return 0;
}