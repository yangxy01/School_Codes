//#include<iostream>
//#include<string>
//#include<queue>
//#include<stack>
//using namespace std;
//
//struct BiTreeNode
//{
//	char data;
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
//	int maxdepth;
//	void DeleteNode(BiTreeNode* node)
//	{
//		if (node == NULL)
//			return;
//		DeleteNode(node->left);
//		DeleteNode(node->right);
//		delete node;
//	}
//	BiTreeNode* CreateTree(BiTreeNode* node)
//	{
//		if (str[pos] == '#' || pos >= str.length())
//		{
//			pos++;
//			return NULL;
//		}
//		BiTreeNode* newnode = new BiTreeNode;
//		newnode->data = str[pos];
//		pos++;
//		newnode->parent = node;
//		newnode->left = CreateTree(newnode);
//		newnode->right = CreateTree(newnode);
//		return newnode;
//	}
//	void FindBottom(BiTreeNode* node)
//	{
//		queue< BiTreeNode*> que;
//		stack< BiTreeNode*> record;
//		que.push(node);
//		while (que.size() > 0)
//		{
//			BiTreeNode* p = que.front();
//			record.push(p);
//			que.pop();
//			if (p->left)
//				que.push(p->left);
//			if (p->right)
//				que.push(p->right);
//		}
//		cout << record.top()->data;
//	}
//	void GetDepth(BiTreeNode* node,int i)
//	{
//		if (node == NULL)
//			return;
//		if (i > maxdepth)
//			maxdepth = i;
//		GetDepth(node->left, i + 1);
//		GetDepth(node->right, i + 1);
//	}
//
//
//public:
//	BiTree() { root = NULL; pos = 0; str = ""; maxdepth = 1; }
//	~BiTree() { DeleteNode(root); }
//	void CreateTree(string str) { this->str = str; root = CreateTree(root);}
//	int GetDepth(BiTreeNode* node)
//	{
//		if (node == NULL)
//			return 0;
//		maxdepth = 1;
//		GetDepth(node, 1);
//		return maxdepth;
//	}
//	void GetMaxNode()
//	{
//		if (root->left == NULL && root->right == NULL)
//		{
//			cout << "0:" << endl;
//			return;
//		}
//		BiTreeNode* MaxNode = root;
//		BiTreeNode* MaxLeftHead = NULL;
//		BiTreeNode* MaxRightHead = NULL;
//		int maxlen = 1;
//		queue< BiTreeNode*> que;
//		que.push(root);
//		while (que.size() > 0)
//		{
//			BiTreeNode* p = que.front();
//			que.pop();
//			int len = 0;
//			if (p->left)
//				len += GetDepth(p->left);
//			if(p->right)
//				len += GetDepth(p->right);
//			if (len > maxlen)
//			{
//				maxlen = len;
//				MaxLeftHead = p->left;
//				MaxRightHead = p->right;
//			}
//			if (p->left)
//				que.push(p->left);
//			if (p->right)
//				que.push(p->right);
//		}
//		
//		cout << maxlen<<":";
//		FindBottom(MaxLeftHead);
//		cout << " ";
//		FindBottom(MaxRightHead);
//		cout << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str;
//	while (t--)
//	{
//		cin >> str;
//		BiTree T;
//		T.CreateTree(str);
//		T.GetMaxNode();
//	}
//	return 0;
//}