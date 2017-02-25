/*!
 * \file 1073. Scientific Notation (20).cpp
 * \date 2017/02/25 17:52
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1073
 * \note
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	string sci_note, conv_note;
	int signal;
	int expo;
	string base = "";
	cin >> sci_note;
	signal = sci_note[0] == '+';
	base.append(1, sci_note[1]);
	int e_pos = sci_note.find('E');
	base.append(sci_note.substr(3, e_pos - 3));
	expo = std::stoi(sci_note.substr(e_pos + 1, sci_note.length() - e_pos - 1));
	
	if (!signal)
	{
		conv_note.append(1, '-');
	}
	conv_note = conv_note + base;
	if (expo < 0)
	{
		conv_note.insert(1-signal, -expo-1, '0');
		conv_note.insert(1-signal, "0.");
	}
	else
	{
		if (base.length() > expo + 1)
			conv_note.insert(expo + 2 - signal, 1, '.');
		else
			conv_note.append(expo - base.length() + 1, '0');
	}
	cout << conv_note;
	return 0;
}