/*!
 * \file 1039. Course List for Student.cpp
 * \date 2017/02/17 20:50
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1039
 * \note
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;

int main(int argc, const char* argv[])
{
	int N, K, Ni, Ki, t;
	char s[5];
	// map<string, vector<int> > student;
	vector<vector<int> > student;
	int stu_idx[26 * 26 * 26 * 10];
	memset(stu_idx, -1, 26 * 26 * 26 * 10 * sizeof(int));
	//ÊäÈë
	// cin >> N >> K;
	scanf("%d%d", &N, &K);
	vector<int> tmp;
	for (auto i = 0; i < K; i++)
	{
		// cin >> Ni >> Ki;
		scanf("%d%d", &Ni, &Ki);
		for (auto j = 0; j < Ki; j++)
		{
			// cin >> s;
			scanf("%s", s);
			/*if (student.find(s) == student.end())
				student[s] = vector<int>();
			student[s].push_back(Ni);*/
			t = (((s[0] - 'A') * 26 + (s[1] - 'A'))*26 + s[2]-'A')*10+s[3] -'0';
			if (stu_idx[t] == -1)
			{
				stu_idx[t] = student.size();
				tmp.clear();
				student.push_back(tmp);
			}
			student[stu_idx[t]].push_back(Ni);
		}
	}
	for (auto i = 0; i < N; i++)
	{
		// cin >> s;
		scanf("%s", s);
		/*sort(student[s].begin(), student[s].end());
		cout << s << " " << student[s].size();
		for (auto j : student[s])
			cout << " " << j;*/
		t = (((s[0] - 'A') * 26 + (s[1] - 'A')) * 26 + s[2] - 'A') * 10 + s[3] - '0';
		if (stu_idx[t] != -1)
		{
			sort(student[stu_idx[t]].begin(), student[stu_idx[t]].end());
			printf("%s %d", s, student[stu_idx[t]].size());
			// cout << s << " " << student[stu_idx[t]].size();
			for (auto j : student[stu_idx[t]])
				// cout << " " << j;
				printf(" %d", j);
		}
		else
			// cout << s << " " << "0";
			printf("%s 0", s);
		printf("\n");
	}
	return 0;
}