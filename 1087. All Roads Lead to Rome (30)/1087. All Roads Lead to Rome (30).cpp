/*!
 * \file 1087. All Roads Lead to Rome (30).cpp
 * \date 2017/02/27 13:53
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1087
 * \note
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 26*26*26

inline int Convert2Int(string s)
{
	return (((s[0] - 'A') * 26 + s[1] - 'A') * 26 + s[2] - 'A');
}

inline string Convert2City(int n)
{
	string s = "AAA";
	s[2] = n % 26 + 'A';
	s[1] = n / 26 % 26 + 'A';
	s[0] = n / 26 / 26 + 'A';
	return s;
}
struct CityCost {
	int dest;
	int pair_cost;
};

int N, K, start, destination;	
string city;
int happiness[MAX], min_cost, path_count;	
unsigned int dist[MAX + 1];	// distance of cost
bool traced[MAX];
vector<CityCost> cost[MAX];
unsigned int max_happiness, avg_happiness;
vector<int> path, final_path;
void DFS(int port, int tmp_cost, int tmp_happiness, int tmp_count)
{
	tmp_count++;
	tmp_happiness += happiness[port];
	path.push_back(port);
	if (port == destination)
	{
		if (tmp_cost == min_cost)
		{
			path_count++;
			if (tmp_happiness > max_happiness || tmp_happiness == max_happiness && (tmp_happiness / tmp_count > avg_happiness))
			{
				max_happiness = tmp_happiness;
				avg_happiness = tmp_happiness / tmp_count;
				final_path = path;
			}
		}
		path.pop_back();
		return;
	}
	for (auto i : cost[port])
	{
		if (!traced[i.dest])
		{
			traced[i.dest] = true;
			DFS(i.dest, tmp_cost + i.pair_cost, tmp_happiness, tmp_count);
			traced[i.dest] = false;
		}
	}
	path.pop_back();
}

int main(int argc, const char* argv[])
{
	// 输入
	destination = Convert2Int("ROM");
	cin >> N >> K >> city;
	start = Convert2Int(city);
	for (int i = 0; i < N-1; i++)
	{
		cin >> city;
		cin >> happiness[Convert2Int(city)];
	}
	string city1, city2;
	int c1, c2, tmp_cost;
	CityCost tmp_cc;
	for (int i = 0; i < K; i++)
	{
		cin >> city1 >> city2 >> tmp_cost;
		c1 = Convert2Int(city1);
		c2 = Convert2Int(city2);
		tmp_cc.pair_cost = tmp_cost;
		tmp_cc.dest = c2;
		cost[c1].push_back(tmp_cc);
		tmp_cc.dest = c1;
		cost[c2].push_back(tmp_cc);
	}
	// dijkstra 寻找最小的cost
	memset(dist, 0xFFFFFFFF, (MAX+1) * sizeof(unsigned int));
	dist[start] = 0;
	int u = -1;
	while (true)
	{
		u = find_if(&dist[u+1], &dist[MAX], [](unsigned int i1) {
			return i1 != 0xFFFFFFFF;
		}) - &dist[0];
		if (u == MAX)
			break;
		for (auto i : cost[u])
		{
			if (dist[i.dest] > dist[u] + i.pair_cost)
				dist[i.dest] = dist[u] + i.pair_cost;
		}
	}
	// DFS寻找所有cost最小的路径
	// 并且从这些路径中挑选happiness最大 或者 happiness最大并且avg happiness也最大的路径
	min_cost = dist[destination];
	traced[start] = true;
	for (auto i : cost[start])
	{
		traced[i.dest] = true;
		DFS(i.dest, i.pair_cost, 0, 0);
		traced[i.dest] = false;
	}
	// 输出
	cout << path_count << " " << min_cost << " " << max_happiness << " " << avg_happiness << "\n";
	cout << Convert2City(start);
	for (auto i : final_path)
		cout << "->" << Convert2City(i);
	return 0;
}