/*!
 * \file 1071. Speech Patterns (25).cpp
 * \date 2017/02/25 14:41
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1071
 * \note
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

int main(int argc, const char* argv[])
{
	string text;
	map<string, int> word_count;
	map<string, int>::iterator it;
	getline(cin, text);
	string::iterator it1, it2;
	set<string> res;
	int max_count = 0;
	string tmp = "";
	for (size_t i = 0; i < text.length(); i++)
	{
		text[i] = tolower(text[i]);
	}
	it1 = it2 = text.begin();
	while (it1 != text.end())
	{
		if (it2 != text.end() && (*it2 >= '0' && *it2 <= '9' || *it2 >= 'a' && *it2 <= 'z' || *it2 <= 'Z' && *it2 >= 'A'))
		{
			it2++;
		}
		else
		{
			tmp = text.substr(it1 - text.begin(), it2 - it1);
			if (tmp != "")
			{
				if ((it = word_count.find(tmp)) != word_count.end())
				{
					if (++(it->second) > max_count)
					{
						max_count = it->second;
						res = set<string>{ it->first };
					}
					else if (it->second == max_count)
						res.insert(it->first);
				}
				else
				{
					word_count.insert(pair<string, int>(tmp, 1));
					if (max_count == 1)
						res.insert(tmp);
					else if (max_count == 0)
					{
						max_count = 1;
						res.insert(tmp);
					}
				}
			}
			if (it2 != text.end())
				it2++;
			it1 = it2;
			tmp = "";
		}
	}
	for (auto i : res)
		printf("%s %d\n", i.c_str(), max_count);
	return 0;
}