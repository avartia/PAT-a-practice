/*!
 * \file 1056. Mice and Rice.cpp
 * \date 2017/02/19 16:09
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1056
 * \note
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Np, Ng, t;
int W[1001], R[1001];
vector<int> P, tmp;
int main(int argc, char const* argv[])
{
	// input
	cin >> Np >> Ng;
	for (int i = 0; i < Np; i++)
	{
		cin >> W[i];
	}
	for (int i = 0; i < Np; i++)
	{
		cin >> t;
		P.push_back(t);
	}
	vector<int> origin_p = P;
	while (P.size() > 1)
	{
		tmp.clear();
		vector<int> part;
		int i = 0;
		int limit = P.size() - Ng;
		for (; i < limit; i += Ng)
		{
			part = vector<int>(P.begin() + i, P.begin() + i + Ng);
			tmp.push_back(*max_element(part.begin(), part.end(), [](int a, int b) { return W[a] < W[b]; }));
		}
		part = vector<int>(P.begin() + i, P.end());
		tmp.push_back(*max_element(part.begin(), part.end(), [](int a, int b) { return W[a] < W[b]; }));
		int t = tmp.size();
		for (auto j : P)
			R[j] = t+1;
		P = tmp;
	}
	R[P[0]] = 1;
	// output
	cout << R[0];
	for (size_t i = 1; i < Np; i++)
	{
		cout << " " << R[i];
	}
	return 0;
}