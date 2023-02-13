//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* left = NULL;
//	Node* right = NULL;
//	Node* parent = NULL;
//};
//
//class BiTree
//{
//	Node* root;
//	int* arr;
//	int len;
//	int height;
//
//	Node* Create(Node* root,int i)
//	{
//		if (i >= len) { return NULL; }
//		if (arr[i] == 0) { return NULL; }
//		Node* newnode = new Node;
//		newnode->data = arr[i];
//		newnode->left = Create(root, 2 * i + 1);
//		newnode->right = Create(root, 2 * i + 2);
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
//	void PreOrder(Node* root)
//	{
//		if (root==NULL)
//		{
//			return;
//		}
//		cout << root->data << " ";
//		PreOrder(root->left);
//		PreOrder(root->right);
//	}
//
//public:
//	BiTree() { root = NULL; len = 0; height = 0; arr = NULL; }
//	void Create(int *a,int l)
//	{
//		arr = a;
//		len = l;
//		root = Create(root,0);
//	}
//	void PreOrder()
//	{
//		PreOrder(root);
//		cout << endl;
//	}
//
//	~BiTree() { Delete(root); }
//};
//
//int main()
//{
//	int t;
//	string s;
//	int* arr;
//	int len;
//	cin >> t;
//	while (t--)
//	{
//		BiTree T;
//		cin >> len;
//		arr = new int[len];
//		for (int i = 0; i < len; i++)
//			cin >> arr[i];
//		T.Create(arr,len);
//		T.PreOrder();
//	}
//	return 0;
//}