/*!
 * \file 1043. Is It a Binary Search Tree.cpp
 * \date 2017/02/17 23:21
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1043
 * \note
*/
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Node
{
	int value;
	Node *left, *right;
	Node():value(-1), left(nullptr), right(nullptr){}
};
int tree[1001], N, PostOrder[1001], index;
bool CheckBST(Node *node, int start, int end)
{
	node->value = tree[start];
	if (start + 1 == end)
		return true;
	int split = end;
	for (int i = start + 1; i < end; i++)
	{
		if (tree[i] >= tree[start])
		{
			split = i;
			break;
		}
	}
	for (int i = split; i < end; i++)
	{
		if (tree[i] < tree[start])
			return false;
	}
	Node *Left, *Right;
	if (split < end && split > start + 1)
	{
		Left = new Node();
		Right = new Node();
		node->left = Left;
		node->right = Right;
		return (CheckBST(Left, start + 1, split) && CheckBST(Right, split, end));
	}
	else if (split == end)
	{
		Left = new Node();
		node->left = Left;
		return CheckBST(Left, start + 1, split);
	}
	else if (split == start + 1)
	{
		Right = new Node();
		node->right = Right;
		return CheckBST(Right, split, end);
	}
	return false;
}

bool CheckMirrorBST(Node *node, int start, int end)
{
	node->value = tree[start];
	if (start + 1 == end)
		return true;
	int split = end;
	for (int i = start + 1; i < end; i++)
	{
		if (tree[i] < tree[start])
		{
			split = i;
			break;
		}
	}
	for (int i = split; i < end; i++)
	{
		if (tree[i] >= tree[start])
			return false;
	}
	Node *Left, *Right;
	if (split < end && split > start + 1)
	{
		Left = new Node();
		Right = new Node();
		node->left = Left;
		node->right = Right;
		return (CheckMirrorBST(Left, start + 1, split) && CheckMirrorBST(Right, split, end));
	}
	else if (split == end)
	{
		Left = new Node();
		node->left = Left;
		return CheckMirrorBST(Left, start + 1, split);
	}
	else if (split == start + 1)
	{
		Right = new Node();
		node->right = Right;
		return CheckMirrorBST(Right, split, end);
	}
	return false;
}

void PostorderPrint(Node *node)
{
	if (node->left != nullptr)
		PostorderPrint(node->left);
	if (node->right != nullptr)
		PostorderPrint(node->right);
	PostOrder[index++] = node->value;
}



int main(int argc, const char* argv[])
{
#ifdef ONLINE_JUDGE
#else
	ifstream ifs("input3.txt");
	streambuf *cinbackup = cin.rdbuf(ifs.rdbuf());
#endif
	// input
	cin >> N;
	for (auto i = 0; i < N; i++)
	{
		cin >> tree[i];
	}
	// algorithm
	Node *head = new Node();
	if (!CheckBST(head, 0, N))
	{
		head = new Node();
		if (!CheckMirrorBST(head, 0, N))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
	PostorderPrint(head);
	for (int i = 0; i < index - 1; i++)
		cout << PostOrder[i] << " ";
	cout << PostOrder[index - 1];
	return 0;
}