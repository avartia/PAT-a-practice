/*!
 * \file 1075. PAT Judge (25).cpp
 * \date 2017/02/25 23:50
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1075
 * \note
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

struct User
{
	int id;
	int total_score;
	bool is_shown;
	vector<int> pscore;
	int NumOfPerfected;
	User():is_shown(false), NumOfPerfected(0), total_score(0){}
	User(int pnum):is_shown(false), NumOfPerfected(0), total_score(0)
	{ pscore = vector<int>(pnum); fill(pscore.begin(), pscore.end(), -1); }
};

int main(int argc, const char* argv[])
{
	int N, K, M, user_id, problem_id, partial_score_obtained;
	scanf("%d%d%d", &N, &K, &M);
	vector<int> problem_score(K+1);
	vector<User> user(N+1);
	fill(user.begin(), user.end(), User(K + 1));
	for (int i = 1; i <= K; i++)
		scanf("%d", &problem_score[i]);
	for (int i = 0; i <= N; i++)
		user[i].id = i;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &user_id, &problem_id, &partial_score_obtained);
		if (partial_score_obtained != -1)
			user[user_id].is_shown = true;
		else if (user[user_id].pscore[problem_id] == -1)
			user[user_id].pscore[problem_id] = 0;
		if (user[user_id].pscore[problem_id] < partial_score_obtained)
		{
			if (partial_score_obtained == problem_score[problem_id])
				user[user_id].NumOfPerfected++;
			user[user_id].pscore[problem_id] = partial_score_obtained;
		}
	}
	for (vector<User>::iterator i = user.begin(); i != user.end(); )
	{
		if (!i->is_shown)
		{
			i = user.erase(i);
			continue;
		}
		i->pscore.erase(i->pscore.begin());
		for (vector<int>::iterator j = i->pscore.begin(); j != i->pscore.end(); j++)
		{
			if (*j >= 0)
				i->total_score += *j;
		}
		i++;
	}
	sort(user.begin(), user.end(), [](User u1, User u2)
	{
		if (u1.total_score > u2.total_score)
			return true;
		if (u1.total_score == u2.total_score)
		{
			if (u1.NumOfPerfected > u2.NumOfPerfected)
				return true;
			if (u1.NumOfPerfected == u2.NumOfPerfected)
			{
				return u1.id < u2.id;
			}
		}
		return false;
	});
	int t1 = 1, t2 = 1, score = user[0].total_score;
	for (auto i : user)
	{
		if (!i.is_shown)
			break;
		if (i.total_score < score)
		{
			score = i.total_score;
			t1 = t2;
		}
		printf("%d %05d %d", t1, i.id, i.total_score);
		for (auto j : i.pscore)
		{
			if (j >= 0)
				printf(" %d", j);
			else
				printf(" -");
		}
		printf("\n");
		t2++;
	}
	return 0;
}