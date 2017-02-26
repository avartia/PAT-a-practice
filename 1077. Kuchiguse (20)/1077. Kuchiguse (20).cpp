/*!
 * \file 1077. Kuchiguse (20).cpp
 * \date 2017/02/26 13:10
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1077
 * \note
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	int N;
	string line, kuchiguse="";
	cin >> N;
	cin.get();
	for (auto j = 0; j < N; j++)
	{
		getline(cin, line);
		if (j == 0)
			kuchiguse = line;
		else
		{
			int i;
			for (i = 0; i < kuchiguse.size() && i < line.size(); i++)
			{
				if (*(kuchiguse.rbegin() + i) != *(line.rbegin() + i))
					break;
			}
			kuchiguse = kuchiguse.substr(kuchiguse.length() - i, i);
		}
	}
	if (kuchiguse.empty())
		cout << "nai" << endl;
	else
		cout << kuchiguse << endl;
	return 0;
}