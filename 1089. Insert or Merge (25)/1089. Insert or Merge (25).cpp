/*!
 * \file 1089. Insert or Merge (25).cpp
 * \date 2017/02/27 16:33
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1089
 * \note
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(int argc, const char* argv[])
{
	int N;
	cin >> N;
	vector<int> initial(N), partial(N);
	for (auto i = 0; i < N; i++)
	{
		cin >> initial[i];
	}
	for (auto i = 0; i < N; i++)
	{
		cin >> partial[i];
	}
	auto i = 0;
	for (; i < N-1; i++)
	{
		if (partial[i] > partial[i + 1])
			break;
	}
	if(equal(partial.begin()+i+1, partial.end(), initial.begin()+i+1))
	{
		cout << "Insertion Sort\n";
		sort(partial.begin(), partial.begin() + i + 2);
		for (auto j = partial.begin(); j != partial.end() - 1; j++)
			cout << *j << ' ';
		cout << *partial.rbegin();
	}
	else
	{
		cout << "Merge Sort\n";
		bool flag = false;
		vector<int> merge_sort(N);
		for (auto i = 1; i < N; i *= 2)
		{
			for (auto j = 0; j < N; j += 2 * i)
			{
				if(j + 2*i <= N)
					merge(initial.begin() + j, initial.begin() + j + i, initial.begin() + j + i, initial.begin() + j + 2 * i, merge_sort.begin() + j);
				else if(j + i <= N)
					merge(initial.begin() + j, initial.begin() + j + i, initial.begin() + j+ i, initial.end(), merge_sort.begin() + j);
				else
					merge(initial.begin() + j, initial.end(), initial.end(), initial.end(), merge_sort.begin() + j);
			}
			initial = merge_sort;
			if (flag)
				break;
			if (equal(partial.begin(), partial.end(), initial.begin()))
				flag = true;
		}
		for (auto j = initial.begin(); j != initial.end() - 1; j++)
			cout << *j << ' ';
		cout << *initial.rbegin();
	}
	return 0;
}