/*!
 * \file 1036. Boys vs Girls.cpp
 * \date 2017/02/17 19:02
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1036
 * \note
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

struct Student
{
	string name;
	string ID;
	int grade;
};

int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream ifs("input.txt");
	streambuf *cinbackup = cin.rdbuf(ifs.rdbuf());
#endif
	int N;
	Student highest_female, lowest_male;
	Student tmp;
	char gender;
	highest_female.grade = -1;
	lowest_male.grade = 101;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp.name >> gender >> tmp.ID >> tmp.grade;
		if (gender == 'M')
		{
			if (tmp.grade < lowest_male.grade)
				lowest_male = tmp;
		}
		else
		{
			if (tmp.grade > highest_female.grade)
				highest_female = tmp;
		}
	}
	bool absent = false;
	if (highest_female.grade == -1)
	{
		cout << "Absent" << endl;
		absent = true;
	}
	else
	{
		cout << highest_female.name << " " << highest_female.ID << endl;
	}
	if (lowest_male.grade == 101)
	{
		cout << "Absent" << endl;
		absent = true;
	}
	else
	{
		cout << lowest_male.name << " " << lowest_male.ID << endl;
	}
	if (absent)
		cout << "NA";
	else
		cout << highest_female.grade - lowest_male.grade;
	return 0;
}