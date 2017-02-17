/*!
 * \file 1038. Recover the Smallest Number.cpp
 * \date 2017/02/17 20:22
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1038
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

bool cmp(string s1, string s2)
{
	int i;
	for (i = 0; i < s1.size() && i < s2.size(); i++)
	{
		if (s1[i] < s2[i])
			return true;
		if (s1[i] > s2[i])
			return false;
	}
	int j;
	if (i == s2.size())
	{
		while (i != s1.size())
		{
			for (j = 0; j < s2.size() && i < s1.size(); j++, i++)
			{
				if (s1[i] < s2[j])
					return true;
				if (s1[i] > s2[j])
					return false;
			}
		}
	}
	else
	{
		while (i != s2.size())
		{
			for (j = 0; j < s1.size() && i < s2.size(); j++, i++)
			{
				if (s1[j] < s2[i])
					return true;
				if (s1[j] > s2[i])
					return false;
			}
		}
	}
	return true;
}

int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream ifs("input.txt");
	streambuf *cinbackup = cin.rdbuf(ifs.rdbuf());
#endif
	vector<string> num;
	int N;
	cin >> N;
	string tmp;
	string res = "";
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end(), cmp);
	for (auto i : num)
		res = res + i;
	while (res.find_first_of('0') == 0 && !res.empty())
		res.erase(res.begin());
	if (res.empty())
		cout << "0";
	else
		cout << res;
	return 0;
}