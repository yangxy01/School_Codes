//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//struct Node
//{
//	char data;
//	Node* left = NULL;
//	Node* right = NULL;
//	Node* parent = NULL;
//};
//
//class BiTree
//{
//	Node* root;
//	string str;
//	int pos;
//	int height;
//
//	Node* Create(Node* root)
//	{
//		if (pos > str.length())
//			return NULL;
//		if (str[pos] == '0')
//		{
//			pos++;
//			return NULL;
//		}
//		Node* newnode = new Node;
//		newnode->data = str[pos];
//		pos++;
//		newnode->parent = root;
//		newnode->left = Create(newnode);
//		newnode->right = Create(newnode);
//		return newnode;
//	}
//	void Delete(Node* root)
//	{
//		if (root->left)
//			Delete(root->left);
//		if (root->right)
//			Delete(root->right);
//		delete root;
//	}
//	void PreOrder(Node* root,int depth)
//	{
//		if (!root)
//		{
//			height = max(height, depth);
//			return;
//		}
//		PreOrder(root->left, depth + 1);
//		PreOrder(root->right, depth + 1);
//	}
//	
//	void InOrder(Node* root)
//	{
//		if (!root)
//			return;
//		InOrder(root->left);
//		cout << root->data;
//		InOrder(root->right);
//	}
//	void PostOrder(Node* root)
//	{
//		if (!root)
//			return;
//		PostOrder(root->left);
//		PostOrder(root->right);
//		cout << root->data ;
//	}
//public:
//	BiTree() { root = NULL; pos = 0; height = 0; }
//	void Create(string s)
//	{
//		str = s;
//		root = Create(root);
//	}
//	void PreOrder()
//	{
//		PreOrder(root,0);
//		cout <<height<<endl;
//	}
//	void InOrder()
//	{
//		InOrder(root);
//	}
//	void PostOrder()
//	{
//		PostOrder(root);
//		cout << endl;
//	}
//	~BiTree() { Delete(root); }
//};
//
//int main()
//{
//	int t;
//	string s;
//	cin >> t;
//	while (t--)
//	{
//		BiTree T;
//		cin >> s;
//		T.Create(s);
//		T.PreOrder();		
//	}
//	return 0;
//}