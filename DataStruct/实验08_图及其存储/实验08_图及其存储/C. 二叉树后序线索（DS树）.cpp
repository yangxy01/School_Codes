//#include<iostream>
//#include<string>
//#include<queue>
//#include<vector>
//using namespace std;
//
//struct BiNode
//{
//	char data = ' ';
//	BiNode* left = NULL;
//	BiNode* right = NULL;
//	BiNode* parent = NULL;
//};
//
//class BiTree
//{
//private:
//	BiNode* root;
//	string str;
//	int pos;
//	vector<char> Order;
//	void DeleteTree(BiNode* node)
//	{
//		if (node == NULL)
//			return;
//		DeleteTree(node->left);
//		DeleteTree(node->right);
//		delete node;
//	}
//	BiNode* SCreate()
//	{
//		if (pos >= str.length())
//			return NULL;
//		if (str[pos] == '0')
//		{
//			pos++;
//			return NULL;
//		}
//		BiNode* newnode = new BiNode;
//		newnode->data = str[pos];
//		pos++;
//		newnode->left = SCreate();
//		newnode->right = SCreate();
//		return newnode;
//	}
//	void PostOrder(BiNode* node)
//	{
//		if (node->left)
//			PostOrder(node->left);
//		if(node->right)
//			PostOrder(node->right);
//		Order.push_back(node->data);
//		return;
//	}
//
//
//public:
//	BiTree() { root = NULL; str = ""; pos = 0; }
//	~BiTree() { DeleteTree(root); }
//	void Create(string s)
//	{
//		str = s;
//		root = SCreate();
//	}
//	void PostOrder() { PostOrder(root); }
//	void Find(char ch)
//	{
//		int pos = -1;
//		for (int i = 0; i < Order.size(); i++)
//		{
//			if (Order[i] == ch)
//			{
//				pos = i;
//				break;
//			}
//		}
//		if (pos == -1)
//		{
//			cout << "error" << endl;
//			return;
//		}
//		else if (pos == 0)
//		{
//			if (pos + 1 < Order.size())
//				cout << -1 << " " << Order[pos + 1] << endl;
//			else
//				cout << -1 << " " << -1 << endl;
//		}
//		else if (pos == Order.size() - 1)
//		{
//			if (pos - 1 >= 0)
//				cout << Order[pos - 1] << " " << -1 << endl;
//			else
//				cout << -1 << " " << -1 << endl;
//		}
//		else
//			cout << Order[pos - 1] << " " << Order[pos + 1] << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	char ch1, ch2;
//	while (t--)
//	{
//		string s;
//		cin >> s;
//		BiTree T;
//		T.Create(s);
//		cin >> ch1 >> ch2;
//		T.PostOrder();
//		T.Find(ch1);
//		T.Find(ch2);
//	}
//	return 0;
//}