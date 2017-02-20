/*!
 * \file 1057. Stack.cpp
 * \date 2017/02/19 22:32
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1057
 * \note
*/
#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;
#pragma warning(disable:4996)
int main(int argc, char const* argv[])
{
	vector<int> stack;
	multiset<int, less<int> > upper;
	multiset<int, greater<int> >lower;
	int middle = 100001;
	int N;
	char query[12];
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", query);
		if (strncmp(query, "Pop", 3) == 0)
		{
			if (stack.empty())
				printf("Invalid\n");
			else
			{
				printf("%d\n", stack.back());
				if (stack.back() <= middle)
				{
					lower.erase(lower.find(stack.back()));
					if (lower.size() < upper.size())
					{
						lower.insert(lower.begin(), *upper.begin());
						upper.erase(upper.begin());
					}
				}
				else
				{
					upper.erase(upper.find(stack.back()));
					if (lower.size() - upper.size() > 1)
					{
						upper.insert(upper.begin(), *lower.begin());
						lower.erase(lower.begin());
					}
				}
				stack.pop_back();
				if (stack.empty())
					middle = 100001;
				else
					middle = *lower.begin();
			}
		}
		else if (strncmp(query, "Push", 4) == 0)
		{
			int t;
			scanf("%d", &t);
			stack.push_back(t);
			if (t > middle)
			{
				upper.insert(t);
				if (lower.size() < upper.size())
				{
					lower.insert(lower.begin(), *upper.begin());
					upper.erase(upper.begin());
				}
			}
			else
			{
				lower.insert(t);
				if (lower.size() - upper.size() > 1)
				{
					upper.insert(upper.begin(), *lower.begin());
					lower.erase(lower.begin());
				}
			}
			middle = *lower.begin();
		}
		else if (strncmp(query, "PeekMedian", 10) == 0)
		{
			if (stack.empty())
				printf("Invalid\n");
			else
				printf("%d\n", middle);
		}
	}
	return 0;
}