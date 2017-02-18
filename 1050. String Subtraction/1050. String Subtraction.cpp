/*!
 * \file 1050. String Subtraction.cpp
 * \date 2017/02/18 20:35
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1050
 * \note
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, char const* argv[])
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	set<char> s(s2.begin(), s2.end());
	for (string::iterator it = s1.begin(); it != s1.end(); )
	{
		if (s.find(*it) != s.end())
		{
			it = s1.erase(it);
		}
		else 
			it++;
	}
	cout << s1;
	return 0;
}