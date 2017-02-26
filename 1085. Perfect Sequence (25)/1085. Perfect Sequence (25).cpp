/*!
 * \file 1085. Perfect Sequence (25).cpp
 * \date 2017/02/26 21:07
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1085
 * \note
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int main(int argc, const char* argv[])
{
	int N;
	long long p;
	scanf("%d%lld", &N, &p);
	vector<long long> num(N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &num[i]);
	sort(num.begin(), num.end());
	int count = 0, j = 0;
	for (auto i = 0; i < num.size(); i++)
	{
		if (num.size() - i <= count)
			break;
		for (; j < num.size(); j++)
		{
			if (num[i] * p < num[j])
				break;
		}
		if (j - i > count)
			count = j - i;
	}
	printf("%d", count);
	return 0;
}