/*!
 * \file 1060. Are They Equal.cpp
 * \date 2017/02/20 15:08
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1060
 * \note
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	int N;
	string A, B;
	cin >> N >> A >> B;
	int KA = A.size(), KB = B.size();
	string SA = "", SB = "";
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] != '.')
			SA.append(1, A[i]);
		else
			KA = i;
	}
	while (SA != "" && SA.front() == '0' )
	{
		KA--;
		SA.erase(SA.begin());
	}
	if (SA == "")
	{
		SA = "0";
		KA = 0;
	}
	if (SA.size() > N)
		SA = SA.substr(0, N);
	else
		SA.append(N - SA.size(), '0');
	for (int i = 0; i < B.size(); i++)
	{
		if (B[i] != '.')
			SB.append(1, B[i]);
		else
			KB = i;
	}
	while (SB != "" && SB.front() == '0')
	{
		KB--;
		SB.erase(SB.begin());
	}
	if (SB == "")
	{
		SB = "0";
		KB = 0;
	}
	if (SB.size() > N)
		SB = SB.substr(0, N);
	else
		SB.append(N - SB.size(), '0');
	if (KA == KB && SA == SB)
	{
		cout << "YES 0." << SA << "*10^" << KA;
	}
	else
	{
		cout << "NO " << "0." << SA << "*10^" << KA << " 0." << SB << "*10^" << KB;
	}
	return 0;
}