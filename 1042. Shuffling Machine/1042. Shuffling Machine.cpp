/*!
 * \file 1042. Shuffling Machine.cpp
 * \date 2017/02/17 22:58
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1042
 * \note
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream ifs("input.txt");
	streambuf *cinbackup = cin.rdbuf(ifs.rdbuf());
#endif
	array<string, 54> card = { "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
		"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
		"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
		"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
		"J1", "J2"
	};
	array<string, 54> tmp;
	int shuffle[54];
	int K;
	cin >> K;
	for (int i = 0; i < 54; i++)
		cin >> shuffle[i];
	for (int i = 0; i < K; i++)
	{
		for(int j = 0; j < 54; j++)
			tmp[shuffle[j] - 1] = card[j];
		copy(tmp.begin(), tmp.end(), card.begin());
	}
	for (int i = 0; i < 53; i++)
		cout << card[i] << " ";
	cout << card[53];
	return 0;
}