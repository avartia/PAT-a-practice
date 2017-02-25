/*!
 * \file 1070. Mooncake (25).cpp
 * \date 2017/02/25 14:18
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1070
 * \note
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct MoonCake
{
	double weight;
	double price;
	double unit_price;
};
int main(int argc, const char* argv[])
{
	int N;
	double D;
	cin >> N >> D;
	vector<MoonCake> moon_cake(N);
	for (int i = 0; i < N; i++)
		cin >> moon_cake[i].weight;
	for (int i = 0; i < N; i++)
	{
		cin >> moon_cake[i].price;
		moon_cake[i].unit_price = moon_cake[i].price / moon_cake[i].weight;
	}
	sort(moon_cake.begin(), moon_cake.end(), [](MoonCake m1, MoonCake m2) { return m1.unit_price > m2.unit_price; });
	double count = D;
	double profit = 0.0;
	vector<MoonCake>::iterator it = moon_cake.begin();
	while (count > 0.0 && it != moon_cake.end())
	{
		if (it->weight > count)
		{
			profit += count * it->unit_price;
			count -= count;
		}
		else
		{
			profit += it->price;
			count -= it->weight;
		}
		it++;
	}
	printf("%.2f", profit);
	return 0;
}