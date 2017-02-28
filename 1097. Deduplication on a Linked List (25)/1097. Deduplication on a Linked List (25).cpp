/*!
 * \file 1097. Deduplication on a Linked List (25).cpp
 * \date 2017/02/28 21:40
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1097
 * \note
*/
#include <stdio.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)
struct Node
{
	int addr;
	int Key;
	int Next;
};

int main(int argc, const char* argv[])
{
	int N, head, t;
	scanf("%d%d", &head, &N);
	Node linked_list[100000];
	vector<Node> result;
	vector<Node> removed;
	set<int> existed_key;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		linked_list[t].addr = t;
		scanf("%d%d", &linked_list[t].Key, &linked_list[t].Next);
	}
	t = head;
	while (t != -1)
	{
		if (existed_key.find(abs(linked_list[t].Key)) == existed_key.end())
		{
			result.push_back(linked_list[t]);
			existed_key.insert(abs(linked_list[t].Key));
		}
		else
			removed.push_back(linked_list[t]);
		t = linked_list[t].Next;
	}
	if (!result.empty())
	{
		for (auto i = result.begin(); i < result.end() - 1; i++)
			printf("%05d %d %05d\n", i->addr, i->Key, (i + 1)->addr);
		printf("%05d %d -1\n", result.rbegin()->addr, result.rbegin()->Key);
	}
	if (!removed.empty())
	{
		for (auto i = removed.begin(); i < removed.end() - 1; i++)
			printf("%05d %d %05d\n", i->addr, i->Key, (i + 1)->addr);
		printf("%05d %d -1\n", removed.rbegin()->addr, removed.rbegin()->Key);
	}
	return 0;
}