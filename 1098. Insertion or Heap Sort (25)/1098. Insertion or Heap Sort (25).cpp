/*!
 * \file 1098. Insertion or Heap Sort (25).cpp
 * \date 2017/02/28 22:01
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1098
 * \note
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PercDown(vector<int> &A, int i, int n)
{
	int Child;
	int Tmp;
	for (Tmp = A[i]; (2 * i + 1) < n; i = Child)
	{
		Child = 2 * i + 1;
		if (Child != n - 1 && A[Child + 1] > A[Child])
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;
}

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
	for (; i < N - 1; i++)
	{
		if (partial[i] > partial[i + 1])
			break;
	}
	if (equal(partial.begin() + i + 1, partial.end(), initial.begin() + i + 1))
	{
		cout << "Insertion Sort\n";
		sort(partial.begin(), partial.begin() + i + 2);
		for (auto j = partial.begin(); j != partial.end() - 1; j++)
			cout << *j << ' ';
		cout << *partial.rbegin();
	}
	else
	{
		cout << "Heap Sort\n";
		// build heap
		for (int i = N / 2; i >= 0; i--)
		{
			PercDown(initial, i, N);
		}
		for (i = N - 1; i > 0; i--)
		{
			if (equal(initial.begin(), initial.end(), partial.begin()))
			{
				swap(initial[0], initial[i]);
				PercDown(initial, 0, i);
				for (auto j = initial.begin(); j != initial.end() - 1; j++)
					cout << *j << ' ';
				cout << *initial.rbegin();
				break;
			}
			swap(initial[0], initial[i]);
			PercDown(initial, 0, i);
		}
	}
	return 0;
}