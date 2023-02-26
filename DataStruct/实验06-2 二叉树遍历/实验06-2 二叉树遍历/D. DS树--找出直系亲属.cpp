//#include<iostream>
//#include<string>
//#include<queue>
//using namespace std;
//
//struct BiTreeNode
//{
//	char data=' ';
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
//	void CreateTree(BiTreeNode* node)
//	{
//		if (node == root)
//		{
//			BiTreeNode* newnode1 = new BiTreeNode;
//			newnode1->data = str[0];
//			if (str[1] != '-')
//			{
//				BiTreeNode* newnode2 = new BiTreeNode;
//				newnode2->data = str[1];
//				newnode1->left = newnode2;
//				newnode2->parent = newnode1;
//			}
//			if (str[2] != '-')
//			{
//				BiTreeNode* newnode3 = new BiTreeNode;
//				newnode3->data = str[2];
//				newnode1->right = newnode3;
//				newnode3->parent = newnode1;
//			}
//			root = newnode1;
//		}
//		else
//		{
//			if (str[1] != '-')
//			{
//				BiTreeNode* newnode2 = new BiTreeNode;
//				newnode2->data = str[1];
//				node->left = newnode2;
//				newnode2->parent = node;
//			}
//			if (str[2] != '-')
//			{
//				BiTreeNode* newnode3 = new BiTreeNode;
//				newnode3->data = str[2];
//				node->right = newnode3;
//				newnode3->parent = node;
//			}
//		}
//	}
//	BiTreeNode* FindChar(char ch)
//	{
//		queue< BiTreeNode*> que;
//		if (root == NULL)
//			return root;
//		que.push(root);
//		while (que.size() > 0)
//		{
//			BiTreeNode* p = que.front();
//			if (p->data == ch)
//			{
//				return p;
//			}
//			que.pop();
//			if (p->left)
//				que.push(p->left);
//			if (p->right)
//				que.push(p->right);
//		}
//		cout << endl;
//	}
//
//
//public:
//	BiTree() { root = NULL; pos = 0; str = ""; }
//	~BiTree() { DeleteNode(root); }
//	void CreateTree(string str)
//	{
//		this->str = str;
//		BiTreeNode* p = FindChar(str[0]);
//		CreateTree(p);
//	}
//	int Relation(string str)
//	{
//		int count = 0;
//		BiTreeNode* p = FindChar(str[0]);
//		BiTreeNode* s = p;
//		BiTreeNode* q = FindChar(str[1]);
//		while (p)
//		{
//			p = p->parent;
//			if(p)
//				count++;
//			if (p == q)
//				return count;
//		}
//		p = s;
//		count = 0;
//		while (q)
//		{
//			q = q->parent;
//			if (q)
//				count--;
//			if (p == q)
//				return count;
//		}
//		return 0;
//	}
//
//};
//
//int main()
//{
//	int m,n;
//	cin >> m>>n;
//	string str;
//	BiTree T;
//	while (m--)
//	{
//		cin >> str;
//		T.CreateTree(str);
//	}
//	while (n--)
//	{
//		cin >> str;
//		int ret = T.Relation(str);
//		if (ret == 0)
//		{
//			cout << '-' << endl;
//		}
//		else if (ret > 0)
//		{
//			if (ret == 1)
//				cout << "parent" << endl;
//			else if (ret == 2)
//				cout << "grandparent" << endl;
//			else
//			{
//				int num = 2;
//				while (num < ret)
//				{
//					cout << "great-";
//					num++;
//				}
//				cout << "grandparent" << endl;
//			}
//		}
//		else
//		{
//			if (ret == -1)
//				cout << "child" << endl;
//			else if (ret == -2)
//				cout << "grandchild" << endl;
//			else
//			{
//				int num = -2;
//				while (num > ret)
//				{
//					cout << "great-";
//					num--;
//				}
//				cout << "grandchild" << endl;
//			}
//		}
//	}
//	return 0;
//}
///*
//4 3
//ABH
//BCD
//DEF
//EWY
//BF
//CH
//AW
//0 0
//*/