#include<iostream>
#include<string>
#include<queue>
using namespace std;
class BiTreeNode
{
public:
	char data;
	BiTreeNode* LeftNode;
	BiTreeNode* RightNode;
	BiTreeNode(char ch) :data(ch)
	{
		LeftNode = NULL;
		RightNode = NULL;
	}
};

class BiTree
{
	BiTreeNode* root;
	string StrTree;
	int pos;
	void PreOrder(BiTreeNode* node)
	{
		if (node)
		{
			cout << node->data;
			PreOrder(node->LeftNode);
			PreOrder(node->RightNode);
		}
		return;
	}
	void InOrder(BiTreeNode* node)
	{
		if (node)
		{
			InOrder(node->LeftNode);
			cout << node->data;
			InOrder(node->RightNode);
		}
		return;
	}
	void PostOrder(BiTreeNode* node)
	{
		if (node)
		{
			PostOrder(node->LeftNode);
			PostOrder(node->RightNode);
			cout << node->data;
		}
		return;
	}
	BiTreeNode* CreTree()//递归生成子树
	{
		if (pos >= StrTree.length()) return NULL;
		if (StrTree[pos] == '0')
		{
			pos++;
			return NULL;
		}
		BiTreeNode* node = new BiTreeNode(StrTree[pos]);
		pos++;
		node->LeftNode = CreTree();
		node->RightNode = CreTree();
		return node;
	}
public:
	BiTree(string str) { root = NULL; StrTree = str; pos = 0; }
	~BiTree()
	{
		DeleteNode(root);
	}
	void DeleteNode(BiTreeNode* N)
	{
		if (N->LeftNode)
			DeleteNode(N->LeftNode);
		if (N->RightNode)
			DeleteNode(N->RightNode);
		delete N;
	}
	void CreateTree()//创建树
	{
		root = CreTree();
	}

	int NumOfLeaf()
	{
		int count = 0;
		queue< BiTreeNode*> open;
		open.push(root);
		while (open.size() > 0)
		{
			if (open.front()->LeftNode == NULL && open.front()->RightNode == NULL)
				count++;
			if (open.front()->LeftNode)
				open.push(open.front()->LeftNode);
			if (open.front()->RightNode)
				open.push(open.front()->RightNode);
			open.pop();
		}
		return count;
	}
	void PreOrder() { PreOrder(root); }
	void InOrder() { InOrder(root); }
	void PostOrder() { PostOrder(root); }
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		BiTree Tree(str);
		Tree.CreateTree();
		cout << Tree.NumOfLeaf() << endl;
	}
	return 0;
}