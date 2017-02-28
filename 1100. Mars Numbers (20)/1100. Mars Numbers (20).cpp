/*!
 * \file 1100. Mars Numbers (20).cpp
 * \date 2017/02/28 23:26
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1100
 * \note
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string lower_digit[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string higher_digit[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	int N;
	cin >> N;
	cin.get();
	string num;
	for (int i = 0; i < N; i++)
	{
		getline(cin, num);
		if (num[0] >= '0' && num[0] <= '9')
		{
			int earth = stoi(num);
			if (earth / 13 > 0)
			{
				cout << higher_digit[earth / 13] ;
				if (earth % 13 > 0)
					cout << ' ' << lower_digit[earth % 13] << '\n';
				else
					cout << '\n';
			}
			else
				cout << lower_digit[earth % 13] << '\n';
		}
		else
		{
			int t1 = 0, t2 = 0;
			int i, j;
			for (j = 0; j < 13; j++)
			{
				if (lower_digit[j] == num)
				{
					t2 = j;
					break;
				}
			}
			if (j == 13) {
				for (i = 0; i < 13; i++)
				{
					if (higher_digit[i] == num)
					{
						t1 = i;
						break;
					}
				}
			}
			if (i == 13 && j == 13)
			{
				auto it = num.find(' ');
				for (i = 0; i < 13; i++)
				{
					if (higher_digit[i] == num.substr(0, it))
					{
						t1 = i;
						break;
					}
				}
				for (j = 0; j < 13; j++)
				{
					if (lower_digit[j] == num.substr(it+1, num.size() - it -1))
					{
						t2 = j;
						break;
					}
				}
			}
			cout << t1 * 13 + t2 << '\n';
		}
	}
	return 0;
}