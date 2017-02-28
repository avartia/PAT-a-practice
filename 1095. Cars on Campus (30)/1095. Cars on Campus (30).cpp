/*!
 * \file 1095. Cars on Campus (30).cpp
 * \date 2017/02/28 11:11
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1095
 * \note
*/
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Time {
	int time;
	bool status;
};

struct Car {
	string plate_number;
	vector<Time> in_out;
	int period;
};

int main(int argc, const char* argv[])
{
	int N, K;
	map<string, int> carred;
	cin >> N >> K;
	vector<Car> car;
	vector<int> in_time, out_time;
	string plate, in_out;
	int hh, mm, ss, inout_time;
	map<string, int>::iterator it;
	Car tmp;
	Time tmp_time;
	for (auto i = 0; i < N; i++)
	{
		cin >> plate >> hh;
		cin.get();
		cin >> mm;
		cin.get();
		cin >> ss;
		cin >> in_out;
		tmp_time.time = (hh * 60 + mm) * 60 + ss;
		tmp_time.status = (in_out == "in");
		if ((it=carred.find(plate)) != carred.end())
		{
			car[it->second].in_out.push_back(tmp_time);
		}
		else
		{
			tmp.plate_number = plate;
			tmp.in_out.clear();
			tmp.in_out.push_back(tmp_time);
			carred.insert(pair<string, int>(plate, car.size()));
			car.push_back(tmp);
		}
	}
	// algorithm
	for (auto i = 0; i < car.size(); i++)
	{
		sort(car[i].in_out.begin(), car[i].in_out.end(), [](Time t1, Time t2) {
			return t1.time < t2.time;
		});
		car[i].period = 0;
		for (auto j = car[i].in_out.begin(); j != car[i].in_out.end(); j++)
		{
			if (j + 1 != car[i].in_out.end())
			{
				if (j->status && !(j + 1)->status && j->time < (j + 1)->time)
				{
					car[i].period += (j + 1)->time - j->time;
					in_time.push_back(j->time);
					out_time.push_back((j + 1)->time);
				}
			}
		}
	}
	sort(in_time.begin(), in_time.end());
	sort(out_time.begin(), out_time.end());
	// query
	int query_time;
	for (auto i = 0; i < K; i++)
	{
		cin >> hh;
		cin.get();
		cin >> mm;
		cin.get();
		cin >> ss;
		query_time = (hh * 60 + mm) * 60 + ss;
		auto it1 = lower_bound(in_time.begin(), in_time.end(), query_time) - in_time.begin();
		while (it1 != in_time.size() && in_time[it1] == query_time)
			it1++;
		auto it2 = lower_bound(out_time.begin(), out_time.end(), query_time) - out_time.begin();
		while (it2 != out_time.size() && out_time[it2] == query_time)
			it2++;
		cout << it1 - it2 << '\n';
	}
	// max element
	int max_time = max_element(car.begin(), car.end(), [](Car c1, Car c2)
	{
		return c1.period < c2.period;
	})->period;
	for (auto i : car)
	{
		if (i.period == max_time)
			cout << i.plate_number << ' ';
	}
	printf("%02d:%02d:%02d", max_time / 60 / 60, max_time / 60 % 60, max_time % 60);
	return 0;
}