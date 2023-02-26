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
//	void DeleteNode(BiNode* parent, BiNode* root,int num)
//	{
//		if (num == root->data)
//		{
//			if (root->left == NULL && root->right == NULL)
//			{
//				if (num < parent->data) { parent->left = NULL; }
//				else { parent->right = NULL; }
//				delete root;
//			}
//			else if (root->left == NULL && root->right != NULL)
//			{
//				if (num < parent->data) { parent->right = root->right; }
//				else { parent->right = root->right;}
//				delete root;
//			}
//			else if (root->left != NULL && root->right == NULL)
//			{
//				if (num < parent->data) { parent->left = root->left; }
//				else { parent->right = root->left; }
//				delete root;
//			}
//			else if (root->left != NULL && root->right != NULL)
//			{
//				BiNode* del = root;
//				BiNode* pre = root->left;
//				BiNode* prefront = NULL;
//				while (pre->right)
//				{
//					prefront = pre;
//					pre = pre->right;
//				}
//				if (pre == root->left)
//				{
//					pre->right = root->right;
//				}
//				else
//				{
//					pre->right = root->right;
//					prefront->right = pre->left;
//					pre->left = root->left;
//				}
//				delete del;
//				root = pre;
//			}
//		}
//		else if (num < root->data)
//		{
//			if (root->left == NULL)
//				return;
//			else
//			{
//				parent = root;
//				DeleteNode(parent, root->left, num);
//			}
//		}
//		else if (num > root->data)
//		{
//			if (root->right == NULL)
//				return;
//			else
//			{
//				parent = root;
//				DeleteNode(parent, root->right, num);
//			}
//		}
//	}
//	void Delete(BiNode* root)
//	{
//		if (root->left)
//			Delete(root->left);
//		if (root->right)
//			Delete(root->right);
//		if (root != NULL)
//			delete root;
//		return;
//	}
//public:
//	BiSortTree() { root = NULL; }
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
//	void DeleteNode(int num)
//	{
//		if (num == root->data)
//		{
//			if (root->left == NULL && root->right == NULL)
//			{
//				delete root;
//			}
//			else if (root->left == NULL && root->right != NULL)
//			{
//				BiNode* del = root;
//				root = root->right;
//				delete del;
//			}
//			else if (root->left != NULL && root->right == NULL)
//			{
//				BiNode* del = root;
//				root = root->left;
//				delete del;
//			}
//			else if (root->left != NULL && root->right != NULL)
//			{
//				BiNode* del = root;
//				BiNode* pre = root->left;
//				BiNode* prefront = NULL;
//				while (pre->right)
//				{
//					prefront = pre;
//					pre = pre->right;
//				}
//				if (pre == root->left)
//				{
//					pre->right = root->right;
//				}
//				else
//				{
//					pre->right = root->right;
//					prefront->right = pre->left;
//					pre->left = root->left;
//				}
//				delete del;
//				root = pre;
//			}
//		}
//		else
//		{
//			BiNode* parent = root;
//			if (num < root->data)
//			{
//				DeleteNode(parent, root->left, num);
//			}
//			else
//			{
//				DeleteNode(parent, root->right, num);
//			}
//		}
//		
//		
//	}
//	void InorderTraverse()
//	{
//		InorderTraverse(root);
//		cout << endl;
//	}
//	~BiSortTree()
//	{
//		Delete(root);
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
//			BT.DeleteNode(num);
//			BT.InorderTraverse();
//		}
//
//		delete[]arr;
//	}
//	return 0;
//}