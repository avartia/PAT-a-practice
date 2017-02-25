/*!
 * \file 1066. Root of AVL Tree.cpp
 * \date 2017/02/20 22:27
 *
 * \author Lu Yudi
 * Contact: avartialu@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 * https://www.patest.cn/contests/pat-a-practise/1066
 * \note
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int Height;
	int Element;
	Node *Left, *Right;
	Node(int e, Node* l = nullptr, Node* r = nullptr):Element(e), Left(l), Right(r){}
};

int GetHeight(const Node* node)
{
	if (node == nullptr)
		return -1;
	return node->Height;
}

Node* SRL(Node* &K)
{
	Node* K2;
	K2 = K->Left;
	K->Left = K2->Right;
	K2->Right = K;
	K->Height = max(GetHeight(K->Left), GetHeight(K->Right)) + 1;
	K2->Height = max(GetHeight(K2->Left), GetHeight(K2->Right) + 1);
	return K2;
}

Node* SRR(Node* &K)
{
	Node* K2;
	K2 = K->Right;
	K->Right = K2->Left;
	K2->Left = K;
	K->Height = max(GetHeight(K->Left), GetHeight(K->Right)) + 1;
	K2->Height = max(GetHeight(K2->Left), GetHeight(K2->Right)) + 1;
	return K2;
}
Node* DRL(Node* &K)
{
	K->Left = SRR(K->Left);
	return SRL(K);
}

Node* DRR(Node* &K)
{
	K->Right = SRL(K->Right);
	return SRR(K);
}

void Insert(int element, Node* &root)
{
	if (root == nullptr)
	{
		root = new Node(element);
	}
	else if (element < root->Element)
	{
		Insert(element, root->Left);
		if (GetHeight(root->Left) - GetHeight(root->Right) == 2)
		{
			if (element < root->Left->Element)
				root = SRL(root);
			else
				root = DRL(root);
		}
	}
	else if (element > root->Element)
	{
		Insert(element, root->Right);
		if (GetHeight(root->Right) - GetHeight(root->Left) == 2)
		{
			if (element > root->Right->Element)
				root = SRR(root);
			else
				root = DRR(root);
		}
	}
	root->Height = max(GetHeight(root->Left), GetHeight(root->Right)) + 1;
}

int main(int argc, const char* argv[])
{
	int N, t;
	cin >> N;
	Node* avl_tree = nullptr;
	for (size_t i = 0; i < N; i++)
	{
		cin >> t;
		Insert(t, avl_tree);
	}
	cout << avl_tree->Element;
	return 0;
}