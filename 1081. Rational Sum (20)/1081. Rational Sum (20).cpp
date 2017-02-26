/*!
 * \file 1081. Rational Sum (20).cpp
 * \date 2017/02/26 15:52
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long long description
 * https://www.patest.cn/contests/pat-a-practise/1081
 * \note
*/
#include <iostream>
using namespace std;
struct Rational
{
	long long int numerator, denominator;
};

long long gcd(long long int n1, long long int n2)
{
	if (n1 == 0 || n2 == 0)
		return 1;
	if (n1 == 1 || n2 == 1)
		return 1;
	if (n1 >= n2)
	{
		if (n1 % n2 == 0)
			return n2;
		else
			return gcd(n1 - n2, n2);
	}
	else
	{
		if (n2 % n1 == 0)
			return n1;
		else
			return gcd(n1, n2 - n1);
	}
}

Rational sum(Rational r1, Rational r2)
{
	Rational res;
	res.denominator = r1.denominator * r2.denominator;
	res.numerator = r1.numerator * r2.denominator + r1.denominator * r2.numerator;
	if (res.denominator != 0)
	{
		long long int greatest_common_divisor = gcd(res.denominator, res.numerator);
		res.denominator /= greatest_common_divisor;
		res.numerator /= greatest_common_divisor;
	}
	return res;
}
int main(int argc, const char* argv[])
{
	Rational r[100], result;
	int N;
	cin >> N;
	char c;
	for (int i = 0; i < N; i++)
	{
		cin >> r[i].numerator >> c >> r[i].denominator;
		if (i == 0)
			result = r[0];
		else
			result = sum(result, r[i]);
	}
	if (result.numerator == 0 || result.denominator == 0)
		cout << "0";
	else
	{
		if (result.numerator < 0)
		{
			cout << '-';
			result.numerator = -result.numerator;
		}
		if (result.numerator >= result.denominator)
		{
			cout << result.numerator / result.denominator;
			if (result.numerator % result.denominator > 0)
				cout << " ";
		}
		if (result.numerator % result.denominator > 0)
			cout << result.numerator % result.denominator << "/" << result.denominator;
	}
	return 0;
}