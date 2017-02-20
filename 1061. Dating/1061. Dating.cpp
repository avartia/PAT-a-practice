/*!
 * \file 1061. Dating.cpp
 * \date 2017/02/20 15:54
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1061
 * \note
*/
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char* argv[])
{
	string week[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT","SUN" };
	string line[4];
	cin >> line[0] >> line[1] >> line[2] >> line[3];
	int count = 0;
	int day, hour, min;
	for (int i = 0; i < line[0].size() && i < line[1].size(); i++)
	{
		if (count == 0 && line[0].at(i) == line[1].at(i) && line[0].at(i) >= 'A' && line[0].at(i) <= 'G')
		{
			day = line[0].at(i) - 'A';
			count++;
		}
		else if (count == 1 && line[0].at(i) == line[1].at(i))
		{
			if (line[0].at(i) >= 'A' && line[0].at(i) <= 'N')
			{
				hour = line[0].at(i) - 'A' + 10;
				break;
			}
			else if (line[0].at(i) >= '0' && line[0].at(i) <= '9')
			{
				hour = line[0].at(i) - '0';
				break;
			}
		}
	}
	for (int i = 0; i < line[2].size() && i < line[3].size(); i++)
	{
		if (line[2].at(i) == line[3].at(i) && (line[2].at(i) <= 'z' && line[2].at(i) >= 'a'|| line[2].at(i) <= 'Z' && line[2].at(i) >= 'A'))
		{
			min = i;
			break;
		}
	}
	cout << week[day] << " " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min;
	return 0;
}