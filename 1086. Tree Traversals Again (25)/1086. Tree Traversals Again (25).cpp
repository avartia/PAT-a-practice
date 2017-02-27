/*!
 * \file 1086. Tree Traversals Again (25).cpp
 * \date 2017/02/26 21:37
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1086
 * \note
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Node
{
	int left;
	int right;
	Node():left(-1),right(-1){}
};

int N, head, element;
string instr;
stack<int> s1, s2;
vector<Node> tree;

void PostOrder(int t)
{
	if (tree[t].left != -1)
		PostOrder(tree[t].left);
	if (tree[t].right != -1)
		PostOrder(tree[t].right);
	cout << t << " ";
}

int main(int argc, const char* argv[])
{	
	cin >> N;
	tree = vector<Node>(N + 1);
	for (int i = 0; i < 2*N; i++)
	{
		cin >> instr;
		if (instr == "Push")
		{
			cin >> element;
			if (i == 0)
				head = element;
			else
			{
				if (!s1.empty() && tree[s1.top()].left == -1)
					tree[s1.top()].left = element;
				else
					tree[s2.top()].right = element;
			}
			s1.push(element);
		}
		else if (instr == "Pop")
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	if (tree[head].left != -1)
		PostOrder(tree[head].left);
	if (tree[head].right != -1)
		PostOrder(tree[head].right);
	cout << head;
	return 0;
}