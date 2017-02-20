/*!
 * \file 1058. A+B in Hogwarts.cpp
 * \date 2017/02/20 14:38
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1058
 * \note
*/
#include <stdio.h>
using namespace std;
#pragma warning(disable:4996)
int main(int argc, const char* argv[])
{
	int G1, S1, K1, G2, S2, K2, G3, S3, K3;
	scanf("%d.%d.%d", &G1, &S1, &K1);
	scanf("%d.%d.%d", &G2, &S2, &K2);
	int carry = 0;
	K3 = (K1 + K2 + carry) % 29;
	carry = (K1 + K2 + carry) / 29;
	S3 = (S1 + S2 + carry) % 17;
	carry = (S1 + S2 + carry) / 17;
	G3 = G1 + G2 + carry;
	printf("%d.%d.%d", G3, S3, K3);
	return 0;
}
