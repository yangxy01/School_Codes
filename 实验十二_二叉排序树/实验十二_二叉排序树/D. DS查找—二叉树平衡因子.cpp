#include<iostream>
using namespace std;

struct BiNode
{
	char data = ' ';
	BiNode* left = NULL;
	BiNode* right = NULL;
	int leftfactor = 0;
	int rightfactor = 0;
};

class BiTree
{
	BiNode* root;
	int len;
	BiNode* Create(int i, char* str)
	{
		if (str[i] == '0')
		{
			return NULL;
		}
		BiNode* node = new BiNode;
		{
			node->data = str[i];
		}
		if (2 * i + 1 < len)
			node->left = Create( 2 * i + 1, str);
		if (2 * i + 2 < len)
			node->right = Create(2 * i + 2, str);
		return node;
	}
	void PostOrderTraverse(BiNode* root)
	{
		if (root->left)
			PostOrderTraverse(root->left);
		if (root->right)
			PostOrderTraverse(root->right);
		cout << root->data << " ";
		cout << (root->leftfactor - root->rightfactor) << endl;
	}
	int SetFactor(BiNode* root)
	{
		if (root->left)
		{
			root->leftfactor = SetFactor(root->left) + 1;
		}
		if (root->right)
		{
			root->rightfactor = SetFactor(root->right) + 1;
		}
		if (root->left == NULL)
			root->leftfactor = 0;
		if (root->right == NULL)
			root->rightfactor = 0;
		if (root->leftfactor > root->rightfactor)
			return root->leftfactor;
		else
			return root->rightfactor;
	}
	
	void DeleteNode(BiNode* root)
	{
		if (root->left)
			DeleteNode(root->left);
		if (root->right)
			DeleteNode(root->right);
		if (root != NULL)
			delete root;
		return;
	}
public:
	BiTree() { root = NULL; len = 0; }
	void Create(char* str,int l)
	{
		len = l;
		root= Create(0, str);
	}
	void PostOrderTraverse()
	{
		PostOrderTraverse(root);
	}
	void SetFactor()
	{
		SetFactor(root);
	}
	~BiTree()
	{
		DeleteNode(root);
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char* str = new char[n];
		for (int i = 0; i < n; i++)
			cin >> str[i];
		BiTree BT;
		BT.Create(str, n);
		BT.SetFactor();
		BT.PostOrderTraverse();
		delete[]str;
	}
	return 0;
}