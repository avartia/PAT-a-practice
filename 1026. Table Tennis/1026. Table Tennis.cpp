/*!
 * \file 1026. Table Tennis.cpp
 *
 * \author Lu Yudi
 * \date 二月 2017
 * https://www.patest.cn/contests/pat-a-practise/1026
 * 
 */
#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 10010
struct Player
{
	int arrive_time;
	int play_time;
	int vip_tag;
	int wait_time;
};

bool cmp(Player p1, Player p2)
{
	return p1.arrive_time < p2.arrive_time;
}

int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream fin("input.txt");
	streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
#endif
	// definition
	int N, K, M;
	deque<Player> player;
	deque<Player> finish_player;
	bool occupied[MAX];
	bool is_vip[MAX];
	memset(occupied, false, MAX * sizeof(bool));
	memset(is_vip, false, MAX * sizeof(bool));
	int empty_time[MAX];
	memset(empty_time, 0, MAX * sizeof(bool));
	int count[MAX];	// the number of players served by each table
	memset(count, 0, MAX * sizeof(int));
	int limit_time = (21 - 8) * 3600;
	// 输入
	Player p;
	int t, hh, mm, ss;
	string arrive;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arrive >> p.play_time >> p.vip_tag;
		sscanf_s(arrive.c_str(), "%2d:%2d:%2d", &hh, &mm, &ss);
		// 每个人最多两个小时
		p.play_time = (p.play_time > 120 ? 120 : p.play_time) * 60;
		p.arrive_time = ((hh - 8) * 60 + mm) * 60 + ss;
		player.push_back(p);
	}
	cin >> K >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> t;
		is_vip[t - 1] = true;
	}
	// 排序
	sort(player.begin(), player.end(), cmp);
	// 模拟排队
	while (!player.empty())
	{
		deque<Player>::iterator it = player.begin();
		if (it->arrive_time >= limit_time)
			break;
		bool isfull = true;
		int table_index;
		for (int i = 0; i < K; i++)
		{
			if (empty_time[i] <= it->arrive_time)	//注意等号
			{
				empty_time[i] = it->arrive_time;
				isfull = false;
			}
		}
		// time 最小的桌子
		int min_table = min_element(&empty_time[0], &empty_time[K]) - &empty_time[0];
		if (empty_time[min_table] >= limit_time)
			break;
		// 如果没有空桌子
		if (isfull)
		{
			// 如果是vip桌子
			if (is_vip[min_table])
			{
				while (it != player.end())
				{
					if (it->arrive_time > empty_time[min_table])
						break;
					if (it->vip_tag)
						break;
					it++;
				}
				if (it == player.end() || it->arrive_time > empty_time[min_table])
					it = player.begin();
			}
		}
		// 有空桌子
		else
		{
			// 如果是vip player
			// 选择num最小的vip table
			if (it->vip_tag)
			{
				for (int i = 0; i < K; i++)
				{
					if (empty_time[i] <= it->arrive_time)
					{
						if (is_vip[i])
						{
							min_table = i;
							break;
						}
					}
				}
			}
		}
		count[min_table] ++;
		it->wait_time = empty_time[min_table] - it->arrive_time;
		empty_time[min_table] += it->play_time;
		finish_player.push_back(*it);
		player.erase(it);
	}
	// 输出
	for (int i = 0; i < finish_player.size(); i++)
	{
		int finish_time = finish_player[i].arrive_time + finish_player[i].wait_time;
		printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n", finish_player[i].arrive_time / 3600 + 8, (finish_player[i].arrive_time / 60) % 60, finish_player[i].arrive_time % 60, finish_time / 3600 + 8, (finish_time / 60) % 60, finish_time % 60, round((double)finish_player[i].wait_time / 60.0));	 //四舍五入
	}
	for (int i = 0; i < K - 1; i++)
		cout << count[i] << " ";
	cout << count[K - 1];
	return 0;
}
