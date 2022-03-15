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
//	BiNode* Aroot;
//	BiNode* Sroot;
//	string Astr;
//	string Sstr;
//	int count;
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
//		if (count >= Sstr.length())
//			return NULL;
//		if (Sstr[count] == '#')
//		{
//			count++;
//			return NULL;
//		}
//		BiNode* newnode = new BiNode;
//		newnode->data = Sstr[count];
//		count++;
//		newnode->left = SCreate();
//		newnode->right = SCreate();
//		return newnode;
//	}
//
//	BiNode* ACreate(int pos)
//	{
//		if (pos >= Astr.length())
//			return NULL;
//		if (Astr[pos] == '#')
//		{
//			return NULL;
//		}
//		BiNode* newnode = new BiNode;
//		newnode->data = Astr[pos];
//		newnode->left = ACreate(2*pos+1);
//		newnode->right = ACreate(2*pos+2);
//		return newnode;
//	}
//	
//public:
//	BiTree() { Sroot = NULL; Aroot = NULL; Astr = ""; Sstr = ""; count = 0; }
//	~BiTree() { DeleteTree(Sroot); DeleteTree(Aroot);}
//	void Create(string s1,string s2) 
//	{
//		Astr = s1;
//		Sstr = s2;
//		Sroot=SCreate(); 
//		Aroot = ACreate(0);
//	}
//	int BFS()
//	{
//		queue<BiNode*> que1,que2;
//		que1.push(Aroot);
//		que2.push(Sroot);
//		while (!que1.empty() && !que2.empty())
//		{
//			BiNode* cur1 = que1.front();
//			BiNode* cur2 = que2.front();
//			que1.pop();
//			que2.pop();
//			if (cur1->left && cur2->left)
//			{
//				que1.push(cur1->left);
//				que2.push(cur2->left);
//			}
//			else if (cur1->left && !cur2->left)
//				return 0;
//			else if (!cur1->left && cur2->left)
//				return 0;
//
//			if (cur1->right && cur2->right)
//			{
//				que1.push(cur1->right);
//				que2.push(cur2->right);
//			}
//			else if(cur1->right && !cur2->right)
//				return 0;
//			else if (!cur1->right && cur2->right)
//				return 0;
//
//			if (cur1->data != cur2->data)
//				return 0;
//		}
//		return 1;
//	}
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
//		T.Create(s1,s2);
//		if (T.BFS())
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}