/*!
 * \file main.cpp
 * \date 2017/02/19 15:08
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 * https://www.patest.cn/contests/pat-a-practise/1022
 * TODO: long description
 *
 * \note
*/
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int N,M;
    cin >> N;
	cin.get();
    map<string, set<string> > titleMap;
    map<string, set<string> > authorMap;
    map<string, set<string> > keywordMap;
    map<string, set<string> > publisherMap;
    map<string, set<string> > yearMap;
    map<string, set<string> >::iterator it;
    for (int j = 0;j < N; j++) {
        string ID, title, author, keywords, publisher, year;
		getline(cin, ID);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        getline(cin, year);

        it = titleMap.find(title);
        if (it == titleMap.end()) {
            set<string> IDs;
            titleMap[title] = IDs;
        }
		titleMap[title].insert(ID);

		it = authorMap.find(author);
		if (it == authorMap.end()) {
			set<string> IDs;
			authorMap[author] = IDs;
		}
		authorMap[author].insert(ID);
      
        int index = 0;
        while (true) {
            int end = keywords.find_first_of(' ', index);
			string temp;
            if (end == -1) {
                temp = keywords.substr(index);
            }
            else {
                temp = keywords.substr(index, end - index);
            }
			it = keywordMap.find(temp);
			if (it == keywordMap.end()) {
				set<string> IDs;
				keywordMap[temp] = IDs;
			}
			keywordMap[temp].insert(ID);
			if (end == -1)
				break;
            index = end + 1;
        }

		it = publisherMap.find(publisher);
		if (it == publisherMap.end()) {
			set<string> IDs;
			publisherMap[publisher] = IDs;
		}
		publisherMap[publisher].insert(ID);

		it = yearMap.find(year);
		if (it == yearMap.end()) {
			set<string> IDs;
			yearMap[year] = IDs;
		}
		yearMap[year].insert(ID);
    }
    cin >> M;
    cin.get();
    for (int j = 0; j < M; j++) {
        string query;
        getline(cin, query);
        cout << query << endl;

        string value = query.substr(3);

        switch(query[0]) {
            case '1' : {
                it = titleMap.find(value);
				if (it == titleMap.end())
					cout << "Not Found" << endl;
				else
					for (auto i : it->second)
						cout << i << endl;
                break;
            }
            case '2' : {
                it = authorMap.find(value);
                if (it == authorMap.end())
                    cout << "Not Found" << endl;
                else
					for (auto i : it->second)
						cout << i << endl;
                break;
            }
            case '3' : {
                it = keywordMap.find(value);
                if (it == keywordMap.end())
                    cout << "Not Found" << endl;
                else
					for (auto i : it->second)
						cout << i << endl;
                break;
            }
            case '4' : {
                it = publisherMap.find(value);
                if (it == publisherMap.end())
                    cout << "Not Found" << endl;
                else
					for (auto i : it->second)
						cout << i << endl;
                break;
            }
            case '5' : {
                it = yearMap.find(value);
                if (it == yearMap.end())
                    cout << "Not Found" << endl;
                else
					for (auto i : it->second)
						cout << i << endl;
                break;
            }
        }
    }
    return 0;
}