/*!
 * \file 1049. Counting Ones.cpp
 * \date 2017/02/18 16:50
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1049
 * \note
*/
#include <stdio.h>
#include <iostream>
using namespace std;

int Ones(int i)
{
	int ones = 0;
	while (i > 0)
	{
		ones += ((i % 10) == 1);
		i = i / 10;
	}
	return ones;
}
long CountOne(int n)
{
	if (n < 10)
		return n >= 1;
	long t = CountOne(n / 10);
	return t * 10 + n / 10 - Ones(n / 10)*(9 - n % 10) + ((n % 10) != 0);
}

int main(int argc, const char* argv[])
{
	int N;
	long count;
	cin >> N;
	int i = N;
	count = CountOne(N);
	cout << count;
	return 0;
}