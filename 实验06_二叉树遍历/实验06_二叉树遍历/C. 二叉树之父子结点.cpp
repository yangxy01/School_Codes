//#include<iostream>
//#include<string>
//#include<queue>
//using namespace std;
//class BiTreeNode
//{
//public:
//	char data;
//	BiTreeNode* LeftNode;
//	BiTreeNode* RightNode;
//	BiTreeNode* Father;
//	BiTreeNode(char ch) :data(ch)
//	{
//		LeftNode = NULL;
//		RightNode = NULL;
//		Father = NULL;
//	}
//};
//
//class BiTree
//{
//	BiTreeNode* root;
//	string StrTree;
//	int pos;
//	queue< BiTreeNode*> leaf;
//	queue< BiTreeNode*> father;
//	void LeafPreOrder(BiTreeNode* node)
//	{
//		if (node)
//		{
//			if (node->LeftNode == NULL && node->RightNode == NULL)
//			{
//				leaf.push(node);
//				father.push(node->Father);
//			}
//			LeafPreOrder(node->LeftNode);
//			LeafPreOrder(node->RightNode);
//		}
//		return;
//	}
//	
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
//	BiTreeNode* CreTree(BiTreeNode* Fa)//递归生成子树
//	{
//		if (pos >= StrTree.length()) return NULL;
//		if (StrTree[pos] == '0')
//		{
//			pos++;
//			return NULL;
//		}
//		BiTreeNode* node = new BiTreeNode(StrTree[pos]);
//		node->Father = Fa;
//		pos++;
//		node->LeftNode = CreTree(node);
//		node->RightNode = CreTree(node);
//		return node;
//	}
//public:
//	BiTree(string str) { root = NULL; StrTree = str; pos = 0; }
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
//		root = CreTree(root);
//	}
//
//	void FindLeaf()
//	{
//		LeafPreOrder(root);
//		while (!leaf.empty())
//		{
//			cout << leaf.front()->data << " ";
//			leaf.pop();
//		}
//		cout << endl;
//		while (!father.empty())
//		{
//			cout << father.front()->data << " ";
//			father.pop();
//		}
//		cout << endl;
//	}
//
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
//		Tree.FindLeaf();
//	}
//	return 0;
//}