/*!
 * \file 1120. Friend Numbers (20).cpp
 * \date 2017/03/01 14:06
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1120
 * \note
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, const char* argv[])
{
	int N, integer;
	cin >> N;
	string num;
	set<int> ID;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		integer = 0;
		for (auto j : num)
			integer += j - '0';
		if (ID.find(integer) == ID.end())
			ID.insert(integer);
	}
	cout << ID.size() << '\n';
	if (!ID.empty())
	{
		cout << *ID.begin();
		ID.erase(ID.begin());
		for (auto i : ID)
			cout << ' ' << i;
	}
	return 0;
}