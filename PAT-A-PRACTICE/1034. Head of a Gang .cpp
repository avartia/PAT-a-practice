/*!
 * \file 1034. Head of a Gang .cpp
 * \date 2017/02/17 14:51
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: solve pat a 1034. Head of a Gang
 *  https://www.patest.cn/contests/pat-a-practise/1034
 * \note
*/
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> h1, pair<int, int> h2)
{
	return h1.first < h2.first;
}

int main(int argc, const char *argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream ifs("input2.txt");
	streambuf *cinbackup = cin.rdbuf(ifs.rdbuf());
#endif
	int N, K;
	cin >> N >> K;
	int count[26 * 26 * 26];
	memset(count, 0, sizeof(int) * 26 * 26 * 26);
	string name1, name2;
	int n1, n2, time;
	vector<set<int> > gang;
	vector<int> TotalWeight;
	vector<set<int> >::iterator it1, it2;
	for (int i = 0; i < N; i++)
	{
		cin >> name1 >> name2 >> time;
		n1 = ((name1[0] - 'A') * 26 + name1[1] - 'A') * 26 + name1[2] - 'A';
		n2 = ((name2[0] - 'A') * 26 + name2[1] - 'A') * 26 + name2[2] - 'A';
		it1 = gang.end();
		it2 = gang.end();
		for (vector<set<int> >::iterator it = gang.begin(); it != gang.end(); it++)
		{
			if (it->find(n1) != it->end())
				it1 = it;
			if (it->find(n2) != it->end())
				it2 = it;
		}
		// new gang
		if (it1 == gang.end() && it2 == gang.end())
		{
			set<int> g;
			g.insert(n1);
			g.insert(n2);
			gang.push_back(g);
			TotalWeight.push_back(time);
		}
		else if(it1 != gang.end() && it2 == gang.end())
		{
			it1->insert(n2);
			TotalWeight[it1 - gang.begin()] += time;
		}
		else if (it1 == gang.end() && it2 != gang.end())
		{
			it2->insert(n1);
			TotalWeight[it2 - gang.begin()] += time;
		}
		else
		{
			if (it1 == it2)
				TotalWeight[it1 - gang.begin()] += time;
			else
			{
				// merge set and time
				it1->insert(it2->begin(), it2->end());
				TotalWeight[it1 - gang.begin()] += time + TotalWeight[it2 - gang.begin()];
				gang.erase(it2);
				TotalWeight.erase(it2 - gang.begin() + TotalWeight.begin());
			}
		}
		count[n1] += time;
		count[n2] += time;
	}
	int totalGang = 0;
	vector<pair<int, int> > head;
	for (vector<set<int> >::iterator it = gang.begin(); it != gang.end(); it++)
	{
		if (it->size() > 2 && TotalWeight[it - gang.begin()] > K)
		{
			totalGang++;
			int maxTime = 0;
			pair<int, int> maxHead;
			maxHead.second = it->size();
			for (set<int>::iterator sit = it->begin(); sit != it->end(); sit++)
			{
				if (maxTime < count[*sit])
				{
					maxTime = count[*sit];
					maxHead.first = *sit;	
				}
			}
			head.push_back(maxHead);
		}
	}
	sort(head.begin(), head.end(), cmp);
	// output
	cout << totalGang << endl;
	for (vector<pair<int, int> >::iterator it = head.begin(); it != head.end(); it++)
	{
		cout << (char)(it->first / (26 * 26) + 'A') << (char)((it->first / 26) % 26 + 'A') << (char)(it->first % 26 + 'A' )<< " " << it->second << endl;
	}
	return 0;
}