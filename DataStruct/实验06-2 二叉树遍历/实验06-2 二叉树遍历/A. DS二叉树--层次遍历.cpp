//#include<iostream>
//#include<string>
//#include<queue>
//using namespace std;
//
//struct BiTreeNode
//{
//	char data;
//	BiTreeNode* left;
//	BiTreeNode* right;
//};
//
//class BiTree
//{
//private:
//	int pos;
//	BiTreeNode* root;
//	string str;
//	void DeleteNode(BiTreeNode* node)
//	{
//		if (node == NULL)
//			return;
//		DeleteNode(node->left);
//		DeleteNode(node->right);
//		delete node;
//	}
//	BiTreeNode* CreateTree()
//	{
//		if (str[pos] == '0' || pos >= str.length())
//		{
//			pos++;
//			return NULL;
//		}
//		BiTreeNode* newnode = new BiTreeNode;
//		newnode->data = str[pos];
//		pos++;
//		newnode->left = CreateTree();
//		newnode->right = CreateTree();
//		return newnode;
//	}
//	void LevelOrder(BiTreeNode* node)
//	{
//		queue< BiTreeNode*> que;
//		que.push(node);
//		while (que.size() > 0)
//		{
//			BiTreeNode* p = que.front();
//			que.pop();
//			cout << p->data;
//			if (p->left)
//				que.push(p->left);
//			if (p->right)
//				que.push(p->right);
//		}
//		cout << endl;
//	}
//
//public:
//	BiTree() { root = NULL; pos = 0; str = ""; }
//	~BiTree() { DeleteNode(root); }
//	void CreateTree(string str) { this->str = str; root = CreateTree(); }
//	void LevelOrder() { LevelOrder(root); }
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str;
//	while (t--)
//	{
//		cin >> str;
//		BiTree T;
//		T.CreateTree(str);
//		T.LevelOrder();
//	}
//	return 0;
//}