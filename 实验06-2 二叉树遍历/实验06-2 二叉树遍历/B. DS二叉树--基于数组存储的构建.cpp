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
	//}
	//BiTreeNode* CreateTree(int i)
	//{
	//	if (i >= str.length()) { return NULL; }
	//	if (str[i] == '0' )
	//	{
	//		return NULL;
	//	}
	//	BiTreeNode* newnode = new BiTreeNode;
	//	newnode->data = str[i];
	//	newnode->left = CreateTree(2*i+1);
	//	newnode->right = CreateTree(2*i+2);
	//	return newnode;
	//}
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
	//void PreOrder(BiTreeNode* node)
	//{
	//	if (node == NULL)
	//		return;
	//	cout << node->data;
	//	PreOrder(node->left);
	//	PreOrder(node->right);
	//}
//
//public:
//	BiTree() { root = NULL; pos = 0; str = ""; }
//	~BiTree() { DeleteNode(root); }
//	void CreateTree(string str) { this->str = str; root = CreateTree(0); }
//	void LevelOrder() { LevelOrder(root); }
//	void PreOrder() { PreOrder(root); cout << endl; }
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
//		T.PreOrder();
//	}
//	return 0;
//}