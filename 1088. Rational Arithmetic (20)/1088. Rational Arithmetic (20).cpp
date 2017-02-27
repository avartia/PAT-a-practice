/*!
 * \file 1088. Rational Arithmetic (20).cpp
 * \date 2017/02/27 15:25
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1088
 * \note
*/
#include <iostream>
using namespace std;

struct Rational
{
	long long numerator;
	long long denominator;
};

long long int gcd(long long int t1, long long int t2) {
	return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}

void Print(Rational res)
{

	bool isPos = true;
	if (res.denominator == 0)
	{
		cout << "Inf";
		return;
	}
	if (res.numerator == 0)
	{
		cout << '0';
		return;
	}
	if (res.numerator < 0)
	{
		cout << "(-";
		res.numerator = -res.numerator;
		isPos = false;
	}
	long long gcd_num = gcd(res.numerator, res.denominator);
	res.numerator /= gcd_num;
	res.denominator /= gcd_num;
	if (res.numerator / res.denominator > 0)
		cout << res.numerator / res.denominator;
	if (res.numerator % res.denominator != 0)
	{
		if (res.numerator / res.denominator > 0)
			cout << ' ';
		cout << res.numerator % res.denominator << "/" << res.denominator;
	}
	if (!isPos)
		cout << ')';
}

void calculate(Rational r1, Rational r2, int arith)
{
	Rational res;
	
	if (arith == 0)
	{
		res.denominator = r1.denominator * r2.denominator;
		res.numerator = r1.denominator * r2.numerator + r1.numerator * r2.denominator;
	}
	else if (arith == 1)
	{
		res.denominator = r1.denominator * r2.denominator;
		res.numerator = -r1.denominator * r2.numerator + r1.numerator * r2.denominator;
	}
	else if (arith == 2)
	{
		res.denominator = r1.denominator * r2.denominator;
		res.numerator = r1.numerator * r2.numerator;
	}
	else if (arith == 3)
	{
		res.numerator = r1.numerator * r2.denominator;
		res.denominator = r1.denominator * r2.numerator;
		if (res.denominator < 0)
		{
			res.numerator = -res.numerator;
			res.denominator = -res.denominator;
		}
	}
	Print(res);
}


int main(int argc, const char* argv[])
{
	Rational r1, r2;
	long long gcd_num;
	cin >> r1.numerator;
	cin.get();
	cin >> r1.denominator;
	cin >> r2.numerator;
	cin.get();
	cin >> r2.denominator;
	
	Print(r1);
	cout << " + ";
	Print(r2);
	cout << " = ";
	calculate(r1, r2, 0);
	cout << '\n';
	Print(r1);
	cout << " - ";
	Print(r2);
	cout << " = ";
	calculate(r1, r2, 1);
	cout << '\n';
	Print(r1);
	cout << " * ";
	Print(r2);
	cout << " = ";
	calculate(r1, r2, 2);
	cout << '\n';
	Print(r1);
	cout << " / ";
	Print(r2);
	cout << " = ";
	calculate(r1, r2, 3);
	cout << '\n';
	return 0;
}