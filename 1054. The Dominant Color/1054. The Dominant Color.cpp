/*!
 * \file 1054. The Dominant Color.cpp
 * \date 2017/02/19 12:41
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1054
 * \note
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int main(int argc, char const* argv[])
{
	int M, N, t;
	vector<int> color, count;
	vector<int>::iterator it;
	scanf("%d%d", &M, &N);
	for(int i = 0; i < N;i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &t);
			if ((it=find(color.begin(), color.end(), t)) != color.end())
				count[it - color.begin()] ++;
			else
			{
				color.push_back(t);
				count.push_back(1);
			}
		}
	 }
	it = max_element(count.begin(), count.end());
	printf("%d", color[it - count.begin()]);
	return 0;
}