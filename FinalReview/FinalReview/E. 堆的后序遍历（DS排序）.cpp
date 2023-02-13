//#include<iostream>
//using namespace std;
//
//struct Node
//{
//	int data = 0;
//	Node* left = NULL;
//	Node* right = NULL;
//};
//
//class Heap
//{
//	int* arr;
//	int size;
//	Node* root;
//	void Swap(int i, int j)
//	{
//		int tmp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = tmp;
//	}
//	Node* Create(int i)
//	{
//		if (i >= size) { return NULL; }
//		Node* newnode = new Node;
//		newnode->data = arr[i];
//		newnode->left = Create(2 * i + 1);
//		newnode->right = Create(2 * i + 2);
//		return newnode;
//	}
//	void PostOrder(Node* root)
//	{
//		if (root == NULL)return;
//		PostOrder(root->left);
//		PostOrder(root->right);
//		cout << root->data << " ";
//	}
//public:
//	Heap(int l = 10) :size(l)
//	{
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//			cin >> arr[i];
//		root = NULL;
//	}
//	void MakeHeap()
//	{
//		for (int k = (size / 2)-1; k >= 0; k--)
//		{
//			int min = 2 * k + 1;
//			if (2 * k + 2 < size && arr[2 * k + 2] < arr[min])
//				min = 2 * k + 2;
//			if (arr[k] > arr[min])
//			{
//				Swap(k, min);
//				TopToBottom(min);
//			}
//		}
//	}
//	void TopToBottom(int k)
//	{
//		if (2 * k + 1 >= size)return;
//		int min = 2 * k + 1;
//		if (2 * k + 2 < size && arr[2 * k + 2] < arr[min])
//			min = 2 * k + 2;
//		if (arr[k] > arr[min])
//		{
//			Swap(k, min);
//			TopToBottom(min);
//		}
//
//	}
//	void Adjust()
//	{
//		int savesize = size;
//		for (int k = 0; k < savesize-1; k++)
//		{
//			Swap(0, size - 1);
//			size--;
//			TopToBottom(0);
//			
//		}
//		size = savesize;
//	}
//	void Traverse()
//	{
//		for (int i = 0; i < size; i++)
//			cout << arr[i] << " ";
//		cout << endl;
//	}
//
//	void Create()
//	{
//		root = Create(0);
//	}
//	void PostOrder() { PostOrder(root); cout << endl; }
//
//	~Heap() { delete[]arr; }
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	Heap hp(n);
//	hp.MakeHeap();
//	//hp.Adjust();
//	//hp.Traverse();
//	hp.Create();
//	hp.PostOrder();
//	return 0;
//}