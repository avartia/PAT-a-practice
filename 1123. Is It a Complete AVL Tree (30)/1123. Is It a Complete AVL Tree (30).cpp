/*!
 * \file 1123. Is It a Complete AVL Tree (30).cpp
 * \date 2017/03/01 15:43
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1123
 * \note
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	int value;
	Node* Left;
	Node* Right;
	int Height;
	Node():value(-1), Left(nullptr), Right(nullptr), Height(-1){}
	Node(int element):value(element), Left(nullptr), Right(nullptr), Height(0) {}
};

int GetHeight(Node* root)
{
	if (root == nullptr)
		return 0;
	return root->Height;
}

Node* SRL(Node* &node)
{
	Node* tmp = node->Left;
	node->Left = tmp->Right;
	tmp->Right = node;
	node->Height = max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
	tmp->Height = max(GetHeight(tmp->Left), GetHeight(tmp->Right)) + 1;
	return tmp;
}

Node* SRR(Node* &node)
{
	Node* tmp = node->Right;
	node->Right = tmp->Left;
	tmp->Left = node;
	node->Height = max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
	tmp->Height = max(GetHeight(tmp->Left), GetHeight(tmp->Right)) + 1;
	return tmp;
}

Node* DRL(Node* &node)
{
	node->Left = SRR(node->Left);
	return SRL(node);
}

Node* DRR(Node* node)
{
	node->Right = SRL(node->Right);
	return SRR(node);
}

void Insert(int element, Node* &root)
{
	if (root == nullptr)
		root = new Node(element);
	else 
	{
		if (element < root->value)
		{
			Insert(element, root->Left);
			if (GetHeight(root->Left) - GetHeight(root->Right) >= 2)
			{
				if (element < root->Left->value)
					root = SRL(root);
				else
					root = DRL(root);
			}
		}
		else 
		{
			Insert(element, root->Right);
			if (GetHeight(root->Right) - GetHeight(root->Left) >= 2)
			{
				if (element > root->Right->value)
					root = SRR(root);
				else
					root = DRR(root);
			}
		}
	}
	root->Height = max(GetHeight(root->Left), GetHeight(root->Right)) + 1;
}

int main(int argc, const char* argv[])
{
	Node* avl_tree = nullptr;
	int N, t;
	cin >> N;
	for (auto i = 0; i < N; i++)
	{
		cin >> t;
		Insert(t, avl_tree);
	}
	// level oreder traversal
	bool isComplete = true;
	vector<Node*> level, tmp_level;
	level.push_back(avl_tree);
	cout << avl_tree->value;
	bool filled = false;
	while (!level.empty())
	{
		tmp_level.clear();
		for (auto i : level)
		{
			if (i->Left != nullptr)
			{
				tmp_level.push_back(i->Left);
				if (filled)
					isComplete = false;
			}
			else
			{
				if (!filled)
					filled = true;
			}
			if (i->Right != nullptr)
			{
				tmp_level.push_back(i->Right);
				if (filled)
					isComplete = false;
			}
			else
			{
				if (!filled)
					filled = true;
			}
		}
		level = tmp_level;
		for (auto i : level)
			cout << " " << i->value;
	}
	cout << '\n';
	if (isComplete)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}