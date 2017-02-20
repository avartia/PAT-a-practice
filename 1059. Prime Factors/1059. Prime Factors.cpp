/*!
 * \file 1059. Prime Factors.cpp
 * \date 2017/02/20 14:52
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1059
 * \note
*/
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
#pragma warning(disable:4996)
bool isPrime(long int n)
{
	for (long int i = 2; i < static_cast<long int>(sqrt(n)); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(int argc, const char* argv[])
{
	long int N, t;
	vector<long int> prime, count;
	scanf("%ld", &N);
	t = N;
	if (N == 1)
	{
		printf("1=1");
		return 0;
	}
	int i = 2;
	while (N != 1)
	{
		if (N % i == 0 && isPrime(i))
		{
			prime.push_back(i);
			count.push_back(1);
			N /= i;
			while (N % i == 0)
			{
				*(count.end() - 1) += 1;
				N /= i;
			}
		}
		i++;
	}
	printf("%ld=", t);
	for (int i = 0; i < prime.size()-1; i++)
	{
		if (count[i] == 1)
			printf("%ld*", prime[i]);
		else
			printf("%ld^%ld*", prime[i], count[i]);
	}
	i = prime.size() - 1;
	if (count[i] == 1)
		printf("%ld", prime[i]);
	else
		printf("%ld^%ld", prime[i], count[i]);
	return 0;
}