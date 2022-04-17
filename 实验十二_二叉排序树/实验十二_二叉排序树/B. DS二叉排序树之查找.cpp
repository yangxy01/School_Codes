//#include<iostream>
//using namespace std;
//struct BiNode
//{
//	int data = 0;
//	BiNode* left = NULL;
//	BiNode* right = NULL;
//};
//
//class BiSortTree
//{
//	BiNode* root;
//	int searchNum;
//	void InorderTraverse(BiNode* root)
//	{
//		if (root->left)
//			InorderTraverse(root->left);
//		cout << root->data << " ";
//		if (root->right)
//			InorderTraverse(root->right);
//		return;
//	}
//	void Insert(BiNode* root, int num)
//	{
//		if (num > root->data)
//		{
//			if (root->right == NULL)
//			{
//				BiNode* newnode = new BiNode;
//				newnode->data = num;
//				newnode->left = NULL;
//				newnode->right = NULL;
//				root->right = newnode;
//			}
//			else
//				Insert(root->right, num);
//		}
//		else if (num < root->data)
//		{
//			if (root->left == NULL)
//			{
//				BiNode* newnode = new BiNode;
//				newnode->data = num;
//				newnode->left = NULL;
//				newnode->right = NULL;
//				root->left = newnode;
//			}
//			else
//				Insert(root->left, num);
//		}
//	}
//	void DeleteNode(BiNode* root)
//	{
//		if (root->left)
//			DeleteNode(root->left);
//		if (root->right)
//			DeleteNode(root->right);
//		if (root != NULL)
//			delete root;
//		return;
//	}
//	int Search(BiNode* root, int num)
//	{
//		searchNum++;
//		if (num == root->data)
//			return searchNum;
//		else if (num > root->data)
//		{
//			if (root->right == NULL)
//			{
//				BiNode* newnode = new BiNode;
//				newnode->data = num;
//				newnode->left = NULL;
//				newnode->right = NULL;
//				root->right = newnode;
//				searchNum = -1;
//				return searchNum;
//			}
//			else
//				Search(root->right, num);
//		}
//		else if (num < root->data)
//		{
//			if (root->left == NULL)
//			{
//				BiNode* newnode = new BiNode;
//				newnode->data = num;
//				newnode->left = NULL;
//				newnode->right = NULL;
//				root->left = newnode;
//				searchNum = -1;
//				return searchNum;
//			}
//			else
//				Search(root->left, num);
//		}
//		return searchNum;
//	}
//public:
//	BiSortTree() { root = NULL; searchNum = 0; }
//	void Insert(int num)
//	{
//		Insert(root, num);
//	}
//	void Create(int* a, int n)
//	{
//		root = new BiNode;
//		root->data = a[0];
//		for (int i = 1; i < n; i++)
//			Insert(root, a[i]);
//	}
//	void InorderTraverse()
//	{
//		InorderTraverse(root);
//		cout << endl;
//	}
//	int Search(int num)
//	{
//		searchNum = 0;
//		int ret = Search(root, num);
//		return ret;
//	}
//	~BiSortTree()
//	{
//		DeleteNode(root);
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, m, num;
//		cin >> n;
//		int* arr = new int[n];
//		for (int i = 0; i < n; i++)
//			cin >> arr[i];
//		cin >> m;
//		BiSortTree BT;
//		BT.Create(arr, n);
//		BT.InorderTraverse();
//		for (int i = 0; i < m; i++)
//		{
//			cin >> num;
//			cout << BT.Search(num) << endl;
//		}
//
//		delete[]arr;
//	}
//	return 0;
//}