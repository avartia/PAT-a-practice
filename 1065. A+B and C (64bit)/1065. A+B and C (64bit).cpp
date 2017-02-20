/*!
 * \file 1065. A+B and C (64bit).cpp
 * \date 2017/02/20 21:27
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1065
 * \note
*/
#include <iostream>
using namespace std;
int main(int argc, const char* argv[])
{
	int N;
	long long int A, B, C, S;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> C;
		S = A + B;
		bool res = false;
		if (A >= 0 && B <= 0 || A <= 0 && B >= 0)
			res = S > C;
		else if (A > 0)
		{
			if (S < 0)
				res = true;
			else
				res = S > C;
		}
		else
		{
			if (S >= 0)
				res = false;
			else
				res = S > C;
		}
		cout << "Case #" << i+1 << ": ";
		if (res)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}