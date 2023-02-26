//#include<iostream>
//#include<string>
//#include<map>
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
//private:
//	Node* root;
//	string str;
//	int pos;
//	Node* Create(Node* node)
//	{
//		if (str[pos] == '0')
//		{
//			pos++;
//			return NULL;
//		}
//		if (pos < str.length())
//		{
//			Node* newnode = new Node;
//			newnode->data = str[pos];
//			pos++;
//			newnode->parent = node;
//			newnode->left = Create(newnode);
//			newnode->right = Create(newnode);
//			return newnode;
//		}
//		else
//			return NULL;
//	}
//	void Destory(Node* node)
//	{
//		if (node == NULL)
//			return;
//		Destory(node->left);
//		Destory(node->right);
//		delete node;
//	}
//	void WPL(Node* node,int i, map<char, int> mymap,int &sum)
//	{
//		if(node->left)
//			WPL(node->left, i+1, mymap, sum);
//		if (node->right)
//			WPL(node->right, i + 1, mymap, sum);
//		if (node->data >= 'A' && node->data <= 'Z')
//		{
//			sum = sum+(i*mymap[node->data]);
//		}
//	}
//public:
//	BiTree() { root = NULL; str = " "; pos = 0; }
//	~BiTree() { Destory(root); }
//	void Create(string s)
//	{
//		str = s;
//		root = Create(root);
//	}
//	int WPL(map<char, int> mymap)
//	{
//		int sum = 0;
//		WPL(root,0, mymap, sum);
//		return sum;
//	}
//};
//
//int main()
//{
//	int t;
//	string str;
//	int n,x;
//	cin >> t;
//	while (t--)
//	{
//		cin >> str;
//		BiTree T;
//		T.Create(str);
//		cin >> n;
//		map<char, int> mymap;
//		for (int i = 0; i < str.length(); i++)
//		{
//			if (str[i] >= 'A' && str[i] <= 'Z')
//			{
//				cin >> x;
//				mymap[str[i]] = x;
//			}
//		}
//		cout<<T.WPL(mymap)<<endl;
//	}
//	return 0;
//}