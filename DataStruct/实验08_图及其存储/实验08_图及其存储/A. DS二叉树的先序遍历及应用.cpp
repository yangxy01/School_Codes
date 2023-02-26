//#include<iostream>
//#include<string>
//#include<queue>
//#include<vector>
//using namespace std;
//
//struct BiNode
//{
//	int data = 0;
//	BiNode* left = NULL;
//	BiNode* right = NULL;
//	BiNode* parent = NULL;
//	int xpos = 0;
//};
//
//class BiTree
//{
//private:
//	BiNode* root;
//	void DeleteTree(BiNode* node)
//	{
//		if (node == NULL)
//			return;
//		DeleteTree(node->left);
//		DeleteTree(node->right);
//		delete node;
//	}
//	void Create(BiNode* &node, int pos)
//	{
//		int tmp = -1;
//		cin >> tmp;
//		if (tmp == -1)
//			node=NULL;
//		else
//		{
//			node = new BiNode;
//			node->data = tmp;
//			node->xpos = pos;
//			Create(node->left, pos-1);
//			Create(node->right, pos+1);
//		}		
//	}
//public:
//	BiTree() { root = NULL; }
//	~BiTree() { DeleteTree(root); }
//	int Create() { Create(root, 0); if (root == NULL)return 0; else return 1; }
//	void BFS()
//	{
//		queue<BiNode*> que;
//		vector<int> right,left;
//		left.push_back(0);
//		right.push_back(0);
//		que.push(root);
//		while (!que.empty())
//		{
//			BiNode* cur = que.front();
//			que.pop();
//			if(cur->left)
//				que.push(cur->left);
//			if (cur->right)
//				que.push(cur->right);
//			if (cur->xpos >= 0)
//			{
//				if ((cur->xpos)+1 > right.size())
//					right.push_back(0);
//				right[cur->xpos]+=cur->data;
//			}
//			else
//			{
//				if (-(cur->xpos) + 1 > left.size())
//					left.push_back(0);
//				left[-(cur->xpos)]+=cur->data;
//			}
//		}
//		vector<int> total;
//		for (int i = left.size()-1; i >= 1; i--)
//			total.push_back(left[i]);
//		for (int i = 0; i < right.size(); i++)
//			total.push_back(right[i]);
//		for (int i = 0; i < total.size() - 1; i++)
//			cout << total[i] << " ";
//		cout << total[total.size() - 1] << endl;
//		cout << endl;
//	}
//};
//
//int main()
//{
//	char ch;
//	int i = 1;
//	while (1)
//	{
//		BiTree T;
//		if (T.Create() == 0)
//			break;
//		cout << "Case " << i << ":" << endl;
//		T.BFS();
//		i++;
//	}
//	return 0;
//}