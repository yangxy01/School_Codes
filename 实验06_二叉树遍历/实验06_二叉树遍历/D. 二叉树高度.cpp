//#include<iostream>
//#include<string>
//using namespace std;
//class BiTreeNode
//{
//public:
//	char data;
//	BiTreeNode* LeftNode;
//	BiTreeNode* RightNode;
//	BiTreeNode(char ch) :data(ch)
//	{
//		LeftNode = NULL;
//		RightNode = NULL;
//	}
//};
//
//class BiTree
//{
//	BiTreeNode* root;
//	string StrTree;
//	int pos;
//	int height;
//	void FindLevel(BiTreeNode* node,int level)
//	{
//		if (node)
//		{
//			level++;
//			if (level > height)
//				height = level;
//			FindLevel(node->LeftNode,level);
//			FindLevel(node->RightNode,level);
//		}
//		return;
//	}
//
//	void PreOrder(BiTreeNode* node)
//	{
//		if (node)
//		{
//			cout << node->data;
//			PreOrder(node->LeftNode);
//			PreOrder(node->RightNode);
//		}
//		return;
//	}
//	void InOrder(BiTreeNode* node)
//	{
//		if (node)
//		{
//			InOrder(node->LeftNode);
//			cout << node->data;
//			InOrder(node->RightNode);
//		}
//		return;
//	}
//	void PostOrder(BiTreeNode* node)
//	{
//		if (node)
//		{
//			PostOrder(node->LeftNode);
//			PostOrder(node->RightNode);
//			cout << node->data;
//		}
//		return;
//	}
//	BiTreeNode* CreTree()//递归生成子树
//	{
//		if (pos >= StrTree.length()) return NULL;
//		if (StrTree[pos] == '0')
//		{
//			pos++;
//			return NULL;
//		}
//		BiTreeNode* node = new BiTreeNode(StrTree[pos]);
//		pos++;
//		node->LeftNode = CreTree();
//		node->RightNode = CreTree();
//		return node;
//	}
//public:
//	BiTree(string str) { root = NULL; StrTree = str; pos = 0; height = 0; }
//	~BiTree()
//	{
//		DeleteNode(root);
//	}
//	void DeleteNode(BiTreeNode* N)
//	{
//		if (N->LeftNode)
//			DeleteNode(N->LeftNode);
//		if (N->RightNode)
//			DeleteNode(N->RightNode);
//		delete N;
//	}
//	void CreateTree()//创建树
//	{
//		root = CreTree();
//	}
//	int GetHeight()
//	{
//		FindLevel(root, 0);
//		return height;
//	}
//	void PreOrder() { PreOrder(root); }
//	void InOrder() { InOrder(root); }
//	void PostOrder() { PostOrder(root); }
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string str;
//		cin >> str;
//		BiTree Tree(str);
//		Tree.CreateTree();
//		cout << Tree.GetHeight() << endl;
//	}
//	return 0;
//}