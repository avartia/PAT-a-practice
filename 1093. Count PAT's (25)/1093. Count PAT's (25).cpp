/*!
 * \file 1093. Count PAT's (25).cpp
 * \date 2017/02/28 10:26
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1093
 * \note
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string PAT;
	cin >> PAT;
	int tp = 0, ta = 0, tt = 0;
	long long presum = 0, sum = 0;
	for (auto i : PAT)
	{
		switch (i)
		{
		case 'P': { tp++; break; }
		case 'A': { presum += tp; break; }
		case 'T': { sum += presum; break; }
		default:
			break;
		}
	}
	cout << sum % 1000000007;
	return 0;
}