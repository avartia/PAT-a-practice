/*!
 * \file 1040. Longest Symmetric String.cpp
 * \date 2017/02/17 21:54
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1040
 * \note
*/

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main(int argc, const char* argv[])
{
	char s[1001];
	gets(s);
	int len = strlen(s);
	for (int i = len; i >= 0; i--)
	{
		for (int j = 0; j < len - i; j++)
		{
			bool sym = true;
			for(int k = j; k <= j+i/2; k++)
				if (s[k] != s[2*j + i - k])
				{
					sym = false;
					break;
				}
			if (sym)
			{
				printf("%d", i+1);
				return 0;
			}
		}
	}
	return 0;
}