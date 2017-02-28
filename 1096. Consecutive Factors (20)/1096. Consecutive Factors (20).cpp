/*!
 * \file 1096. Consecutive Factors (20).cpp
 * \date 2017/02/28 21:11
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1096
 * \note
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, const char* argv[])
{
	int N, max_num = 0;
	vector<int> factor, final_factor;
	cin >> N;
	int sqrt_N = (int)sqrt(N);
	for (int i = 2; i <= (int)pow(N, 1.0 / (max_num+1)) && i <= sqrt_N; i++)
	{
		int t = N, j = i;
		factor.clear();
		while (t % j == 0) { factor.push_back(j); t /= j; j++; }
		if (j-i > max_num)
		{
			max_num = j-i;
			final_factor = factor;
		}
	}
	if (max_num == 0)
	{
		max_num = 1;
		final_factor.push_back(N);
	}
	cout << max_num << '\n';
	cout << final_factor[0];
	final_factor.erase(final_factor.begin());
	for (auto i : final_factor)
		cout << '*' << i;
	return 0;
}