//#include<iostream>
//#include<string>
//using namespace std;
//class BiTreeNode
//{
//public:
//	int data;
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
//private:
//	BiTreeNode* root;
//	void PreOrder(BiTreeNode* node)
//	{
//		if (node)
//		{
//			cout << node->data<<" ";
//			PreOrder(node->LeftNode);
//			PreOrder(node->RightNode);
//		}
//		return;
//	}
//	
//	BiTreeNode* CreTree(int*arr,int pos,int n)//µÝ¹éÉú³É×ÓÊ÷
//	{
//		if (pos >= n) return NULL;
//		if (arr[pos] == 0)
//		{
//			return NULL;
//		}
//		BiTreeNode* node = new BiTreeNode(arr[pos]);
//		node->LeftNode = CreTree(arr,2*pos+1,n);
//		node->RightNode = CreTree(arr, 2 * pos + 2, n);
//		return node;
//	}
//public:
//	BiTree(int *arr, int n)
//	{ 
//		root = CreTree(arr, 0,n);
//	}
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
//
//	void PreOrder() { PreOrder(root); }
//
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int* arr = new int[n];
//		for (int i = 0; i < n; i++)
//			cin >> arr[i];
//		BiTree Tree(arr, n);
//		Tree.PreOrder();
//		cout << endl;
//
//		delete[]arr;
//	}
//	return 0;
//}