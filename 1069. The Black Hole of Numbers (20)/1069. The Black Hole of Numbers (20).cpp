/*!
 * \file 1069. The Black Hole of Numbers (20).cpp
 * \date 2017/02/25 14:05
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1069
 * \note
*/
#include <iostream>
#include <functional>
#include <algorithm>
#include <stdio.h>
using namespace std;

int dec_n(int n)
{
	int a[5];
	a[0] = n % 10;
	a[1] = (n / 10) % 10;
	a[2] = (n / 100) % 10;
	a[3] = n / 1000;
	sort(&a[0], &a[4], less<int>());
	return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int inc_n(int n)
{
	int a[5];
	a[0] = n % 10;
	a[1] = (n / 10) % 10;
	a[2] = (n / 100) % 10;
	a[3] = n / 1000;
	sort(&a[0], &a[4], greater<int>());
	return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int main(int argc, const char* argv[])
{
	int N, max_n, min_n;
	cin >> N;
	do 
	{
		max_n = inc_n(N);
		min_n = dec_n(N);
		N = max_n - min_n;
		printf("%04d - %04d = %04d\n", max_n, min_n, N);
	} while (max_n != min_n && N!= 6174);
	return 0;
}