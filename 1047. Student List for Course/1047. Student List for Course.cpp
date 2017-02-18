/*!
 * \file 1047. Student List for Course.cpp
 * \date 2017/02/18 16:11
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1047
 * \note
*/

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[])
{
	vector<int> course[2501];
	int N, K;
	// input
	scanf("%d%d", &N, &K);
	int C, t, stu;
	char s[5];
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d", s, &C);
		stu = (((s[0] - 'A') * 26 + s[1] - 'A') * 26 + s[2] - 'A') * 10 + s[3] - '0';
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &t);
			course[t].push_back(stu);
		}
	}
	// output
	for (int i = 1; i <= K; i++)
	{
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end());
		for (auto j : course[i])
		{
			printf("%c%c%c%c\n", j / (26 * 26 * 10) + 'A', j / (26 * 10) % 26 + 'A', j / 10 % 26 + 'A', j % 10 + '0');
		}
	}
	return 0;
}