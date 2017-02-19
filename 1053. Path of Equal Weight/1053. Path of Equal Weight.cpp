/*!
 * \file 1053. Path of Equal Weight.cpp
 * \date 2017/02/18 21:18
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1053
 * \note
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node 
{
	int Weight;
	int FirstChild, NextSibling;
	Node():Weight(-1), FirstChild(-1), NextSibling(-1){}
};
int N, M, S;
Node tree[100];
vector<int> path;
vector<vector<int> > equal_weight_paths;

void trace(int head, int &weight)
{
	weight += tree[head].Weight;
	path.push_back(tree[head].Weight);
	if (tree[head].FirstChild == -1)
	{
		if (weight == S)
			equal_weight_paths.push_back(path);
	}
	else
	{
		trace(tree[head].FirstChild, weight);
	}
	path.pop_back();
	weight -= tree[head].Weight;
	if (tree[head].NextSibling != -1)
		trace(tree[head].NextSibling, weight);
}

bool cmp(vector<int> v1, vector<int> v2)
{
	vector<int>::iterator it1 = v1.begin(), it2 = v2.begin();
	for (; it1 != v1.end() && it2 != v2.end(); it1++, it2++)
	{
		if (*it1 > *it2)
			return true;
		if (*it1 < *it2)
			return false;
	}
	if (it1 == v1.end())
		return false;
	return true;
}

int main(int argc, char const* argv[])
{
	memset(tree, -1, 100 * sizeof(Node));
	// ÊäÈë
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i].Weight;
	}
	int parent, num, t1, t2;
	for (int i = 0; i < M; i++)
	{
		cin >> parent >> num;
		cin >> t1;
		tree[parent].FirstChild = t1;
		for (int j = 1; j < num; j++)
		{
			cin >> t2;
			tree[t1].NextSibling = t2;
			t1 = t2;
		}
	}
	// ±éÀú
	int weight = 0;
	trace(0, weight);
	sort(equal_weight_paths.begin(), equal_weight_paths.end(), cmp);
	// output
	for (auto it : equal_weight_paths)
	{
		cout << it[0];
		for (vector<int>::iterator i = it.begin()+1; i != it.end(); i++)
		{
			cout << " " << *i;
		}
		cout << endl;
	}
	return 0;
}