/*!
 * \file 1092. To Buy or Not to Buy (20).cpp
 * \date 2017/02/27 21:11
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1092
 * \note
*/
#include <iostream>
#include <string>
using namespace std;
int needy[128], own[128];
int main()
{
	char c;
	string beads, like_beads;
	cin >> beads;
	for (auto i : beads)
		own[i]++;
	cin >> like_beads;
	for (auto i : like_beads)
		needy[i]++;
	int extra = 0, miss = 0;
	bool hasExtra = true;
	for (int i = 0; i < 128; i++)
	{
		if (own[i] >= needy[i])
			extra += own[i] - needy[i];
		else
		{
			miss += needy[i] - own[i];
			hasExtra = false;
		}
	}
	if (hasExtra)
		cout << "Yes " << extra;
	else
		cout << "No " << miss;
	return 0;
}
