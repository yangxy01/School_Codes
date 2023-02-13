//#include<iostream>
//#include<string>
//#include<queue>
//using namespace std;
//
//struct Node
//{
//	char data='0';
//	Node* left=NULL;
//	Node* right=NULL;
//};
//
//class BiTree
//{
//	Node* root1;
//	Node* root2;
//	string s1, s2;
//	string a, b;
//	int pos;
//	Node* Create1(int i)
//	{
//		if (i >= s1.length())return NULL;
//		if(s1[i]=='#')return NULL;
//		Node* newnode = new Node;
//		newnode->data = s1[i];
//		newnode->left = Create1(2 * i + 1);
//		newnode->right = Create1(2 * i + 2);
//		return newnode;
//	}
//	Node* Create2()
//	{
//		if (pos >= s2.length())return NULL;
//		if (s2[pos] == '#')
//		{
//			pos++;
//			return NULL;
//		}
//		Node* newnode = new Node;
//		newnode->data = s2[pos];
//		pos++;
//		newnode->left = Create2();
//		newnode->right = Create2();
//		return newnode;
//	}
//	void Delete(Node* node)
//	{
//		if (node == NULL)return;
//		if (node->left)Delete(node->left);
//		if (node->right)Delete(node->right);
//		delete node;
//	}
//public:
//	BiTree()
//	{
//		root1 = root2 = NULL;
//		pos = 0;
//	}
//	void Create(string s1, string s2)
//	{
//		this->s1 = s1;
//		this->s2 = s2;
//		root1 = Create1(0);
//		root2 = Create2();
//	}
//	string BFS1()
//	{
//		queue<Node*> que;
//		que.push(root1);
//		while (que.size() > 0)
//		{
//			Node* p = que.front();
//			que.pop();
//			if (p->left)que.push(p->left);
//			if (p->right)que.push(p->right);
//			a+= p->data;
//		}
//		return a;
//	}
//	string BFS2()
//	{
//		queue<Node*> que;
//		que.push(root2);
//		while (que.size() > 0)
//		{
//			Node* p = que.front();
//			que.pop();
//			if (p->left)que.push(p->left);
//			if (p->right)que.push(p->right);
//			b+= p->data;
//		}
//		return b;
//	}
//	~BiTree() { Delete(root1); Delete(root2);}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string s1, s2;
//		cin >> s1 >> s2;
//		BiTree T;
//		T.Create(s1, s2);
//		cout << T.BFS1() << endl;
//		cout << T.BFS2() << endl;
//		if (T.BFS1() == T.BFS2())
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}