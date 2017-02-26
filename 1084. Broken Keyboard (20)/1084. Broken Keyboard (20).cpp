/*!
 * \file 1084. Broken Keyboard (20).cpp
 * \date 2017/02/26 19:05
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1084
 * \note
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char* argv[])
{
	string origin, type_out;
	vector<char> broken_key;
	cin >> origin >> type_out;
	auto i1 = origin.begin();
	auto i2 = type_out.begin();
	while (i1 != origin.end())
	{
		if (i2 != type_out.end() && *i1 == *i2)
		{
			i1++;
			i2++;
		}
		else
		{
			if(find(broken_key.begin(), broken_key.end(), toupper(*i1)) == broken_key.end())
				broken_key.push_back(toupper(*i1));
			i1++;
		}
	}
	for (auto i : broken_key)
		cout << i;
	return 0;
}