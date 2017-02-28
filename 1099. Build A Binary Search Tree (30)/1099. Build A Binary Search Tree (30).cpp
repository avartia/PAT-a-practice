/*!
 * \file 1099. Build A Binary Search Tree (30).cpp
 * \date 2017/02/28 22:43
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1099
 * \note
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
struct Node
{
	int value;
	int Left;
	int right;
};

vector<Node> tree;
vector<int> inorder;
vector<int> key;

void InorderTraversal(int node)
{
	if (tree[node].Left != -1)
	{
		InorderTraversal(tree[node].Left);
	}
	inorder.push_back(node);
	if (tree[node].right != -1)
	{
		InorderTraversal(tree[node].right);
	}
}

int main(int argc, const char* argv[])
{
	int N;
	cin >> N;
	tree = vector<Node>(N);
	key = vector<int>(N);
	for (auto i = tree.begin(); i != tree.end(); i++)
	{
		cin >> i->Left >> i->right;
	}
	for (auto i = 0; i < N; i++)
		cin >> key[i];
	sort(key.begin(), key.end());
	// inorder traversal
	InorderTraversal(0);
	for (auto i = 0; i < N; i++)
		tree[inorder[i]].value = key[i];
	// level order traversal
	deque<int> level, tmp_level;
	level.push_back(0);
	cout << tree[0].value;
	while (!level.empty())
	{
		tmp_level.clear();
		for (auto i : level)
		{
			if (tree[i].Left != -1)
				tmp_level.push_back(tree[i].Left);
			if (tree[i].right != -1)
				tmp_level.push_back(tree[i].right);
		}
		level = tmp_level;
		for (auto i : level)
			cout << " " << tree[i].value;
	}
	return 0;
}