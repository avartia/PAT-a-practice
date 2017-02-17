/*!
 * \file 1037. Magic Coupon.cpp
 * \date 2017/02/17 19:19
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1037
 * \note
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream ifs("input.txt");
	streambuf *cinbackup = cin.rdbuf(ifs.rdbuf());
#endif
	int NC, NP;
	deque<int> coupons, products;
	int tmp;
	cin >> NC;
	for (int i = 0; i < NC; i++)
	{
		cin >> tmp;
		coupons.push_back(tmp);
	}
	cin >> NP;
	for (int i = 0; i < NP; i++)
	{
		cin >> tmp;
		products.push_back(tmp);
	}
	sort(coupons.begin(), coupons.end(), less<int>());
	sort(products.begin(), products.end(), less<int>());
	deque<int>::reverse_iterator it1, it2;
	deque<int>::iterator i1, i2;
	it1 = coupons.rbegin();
	it2 = products.rbegin();
	long long int totalMoney = 0;
	while (it1 != coupons.rend() && it2 != products.rend())
	{
		if (*it1 > 0 && *it2 > 0)
		{
			totalMoney += *it1 * *it2;
			it1++;
			it2++;
		}
		else
			break;
	}
	i1 = coupons.begin();
	i2 = products.begin();
	while ((i1 - coupons.begin()) < (coupons.rend() - 1 - it1) &&
		(i2 - products.begin()) < (products.rend() - 1 - it2))
	{
		if (*i1 < 0 && *i2 < 0)
		{
			totalMoney += *i1 * *i2;
			i1++;
			i2++;
		}
		else
			break;
	}
	cout << totalMoney;
	return 0;
}