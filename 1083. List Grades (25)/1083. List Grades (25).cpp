/*!
 * \file 1083. List Grades (25).cpp
 * \date 2017/02/26 17:58
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1083
 * \note
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
struct Student
{
	char name[11];
	char ID[11];
	int grade;
	bool operator < (const Student &s)
	{
		return this->grade < s.grade;
	}
	bool operator > (const Student &s)
	{
		return this->grade > s.grade;
	}
};
int main(int argc, const char* argv[])
{
	int N, grade1, grade2;
	scanf("%d", &N);
	vector<Student> stu(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s %d", stu[i].name, stu[i].ID, &stu[i].grade);
	}
	scanf("%d%d", &grade1, &grade2);
	sort(stu.begin(), stu.end(), [](Student s1, Student s2) {
		return s1.grade > s2.grade; });
	bool exist = false;
	for(auto it : stu)
	{
		if (it.grade >= grade1 && it.grade <= grade2)
		{
			printf("%s %s\n", it.name, it.ID);
			exist = true;
		}
	}
	if (!exist)
		printf("NONE");
	return 0;
}