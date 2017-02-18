/*!
 * \file 1051. Pop Sequence.cpp
 * \date 2017/02/18 20:46
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1051
 * \note
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, K;
bool popped[1001];
bool Check(vector<int> check)
{
	vector<int> stack;
	memset(popped, false, 1001 * sizeof(bool));
	for (auto it : check)
	{
		if (stack.empty())
		{
			popped[it] = true;
			for (int i = 1; i < it; i++)
			{
				if (!popped[i])
					stack.push_back(i);
			}
		}
		else
		{
			if (it < stack.back())
				return false;
			if (it == stack.back())
				stack.pop_back();
			else 
			{
				for (int i = stack.back() + 1; i < it; i++)
				{
					if (!popped[i])
						stack.push_back(i);
				}
			}
			popped[it] = true;
		}
		if (stack.size() >= M)
			return false;
	}
	return true;
}

int main(int argc, char const* argv[])
{
	cin >> M >> N >> K;
	int t;
	vector<int> check;
	for (int i = 0; i < K; i++)
	{
		check.clear();
		for (int j = 0; j < N; j++)
		{
			cin >> t;
			check.push_back(t);
		}
		if (Check(check))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}