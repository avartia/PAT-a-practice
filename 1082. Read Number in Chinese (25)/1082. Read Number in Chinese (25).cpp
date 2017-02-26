/*!
 * \file 1082. Read Number in Chinese (25).cpp
 * \date 2017/02/26 16:22
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1082
 * \note
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string ChineseNum[10] = 
{
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

string TenBit[5] =
{
	"Shi", "Bai", "Qian", "Wan", "Yi"
};

bool flag[2], total_flag;

void Read4Digit(int n)
{
	bool zero_flag[3];
	memset(zero_flag, false, 3 * sizeof(bool));
	if (n / 1000)
	{
		cout << ChineseNum[n / 1000] << " " << TenBit[2];
		zero_flag[0] = true;
	}
	if (total_flag && !zero_flag[0])
		cout << ChineseNum[0] << " ";
	if (n / 100 % 10)
	{
		if (zero_flag[0])
			cout << " ";
		cout << ChineseNum[n / 100 % 10] << " " << TenBit[1];
		zero_flag[1] = true;
	}
	if (!zero_flag[1] && zero_flag[0] && n % 100 != 0)
	{
		cout << " " << ChineseNum[0];
	}
	if (n / 10 % 10)
	{
		if (zero_flag[0] || zero_flag[1])
			cout << " ";
		cout << ChineseNum[n / 10 % 10] << " " << TenBit[0];
		zero_flag[2] = true;
	}
	if (!zero_flag[2] && zero_flag[1] && n % 10 != 0)
		cout << " " << ChineseNum[0];
	if (n % 10)
	{
		if (zero_flag[0] || zero_flag[1] || zero_flag[2])
			cout << " ";
		cout << ChineseNum[n % 10];
	}
}

int main(int argc, const char* argv[])
{
	int num, tmp;

	cin >> num;
	if (num < 0)
	{
		cout << "Fu ";
		num = -num;
	}
	if (num == 0)
		cout << ChineseNum[0];
	if (num > 99999999)
	{
		tmp = num / 100000000;
		Read4Digit(tmp);
		cout << " " << TenBit[4];
		num = num % 100000000;
		flag[0] = true;
	}
	if (num > 9999)
	{
		tmp = num / 10000;
		if (flag[0])
		{
			cout << " ";
			total_flag = true;
		}
		Read4Digit(tmp);
		cout << " " << TenBit[3];
		num = num % 10000;
		flag[1] = true;
	}
	total_flag = false;
	if ((flag[0] || flag[1]) && num != 0)
	{
		cout << " ";
		total_flag = true;
	}
	Read4Digit(num);
	return 0;
}