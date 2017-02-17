/*!
 * \file 1035. Password.cpp
 * \date 2017/02/17 16:47
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1035
 * \note
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

struct Account {
	string name;
	string passwd;
};


int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream ifs("input1.txt");
	streambuf *cinbackup = cin.rdbuf(ifs.rdbuf());
#endif
	int N;
	vector<Account> account;
	Account tmp;
	bool modified;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		modified = false;
		cin >> tmp.name >> tmp.passwd;
		for (int j = 0; j < tmp.passwd.size(); j++)
		{
			switch (tmp.passwd[j])
			{
			case '1':
				tmp.passwd[j] = '@';
				modified = true;
				break;
			case '0':
				modified = true;
				tmp.passwd[j] = '%';
				break;
			case 'l':
				modified = true;
				tmp.passwd[j] = 'L';
				break;
			case 'O':
				modified = true;
				tmp.passwd[j] = 'o';
				break;
			default:
				break;
			}
		}
		if (modified)
			account.push_back(tmp);
	}
	if (account.size() == 0 )
	{
		if (N == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified", N);
		return 0;
	}
	printf("%d\n", account.size());
	for (int i = 0; i < account.size(); i++) {
		printf("%s %s\n", account[i].name.c_str(), account[i].passwd.c_str());
	}
	return 0;
}
