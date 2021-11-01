//#include<iostream>
//#include<string>
//#include<queue>
//using namespace std;
//
//struct BiTreeNode
//{
//	char data;
//	BiTreeNode* parent = NULL;
//	BiTreeNode* left = NULL;
//	BiTreeNode* right = NULL;
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
//	BiTreeNode* CreateTree(BiTreeNode* node)
//	{
//		if (str[pos] == '0' || pos >= str.length())
//		{
//			pos++;
//			return NULL;
//		}
//		BiTreeNode* newnode = new BiTreeNode;
//		newnode->data = str[pos];
//		pos++;
//		newnode->parent = node;
//		newnode->left = CreateTree(newnode);
//		newnode->right = CreateTree(newnode);
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
//	void FindLeftLeaf(BiTreeNode* node)
//	{
//		int count = 0;
//		queue< BiTreeNode*> open;
//		open.push(root);
//		while (open.size() > 0)
//		{
//			if (open.front()->left == NULL && open.front()->right == NULL&& open.front()->parent->left == open.front())
//				count++;
//			if (open.front()->left)
//				open.push(open.front()->left);
//			if (open.front()->right)
//				open.push(open.front()->right);
//			open.pop();
//		}
//		cout << count << endl;
//		/*if (node)
//		{
//			if ((node->left) == NULL && (node->right) == NULL)
//			{
//				if (node->parent->left == node)
//					count++;
//			}
//			FindLeftLeaf(node->left);
//			FindLeftLeaf(node->right);
//		}*/
//	}
//
//public:
//	BiTree() { root = NULL; pos = 0; str = ""; }
//	~BiTree() { DeleteNode(root); }
//	void CreateTree(string str) { this->str = str; root = CreateTree(root); }
//	void LevelOrder() { LevelOrder(root); }
//	void FindLeftLeaf() { FindLeftLeaf(root); }
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
//		T.FindLeftLeaf();
//	}
//	return 0;
//}