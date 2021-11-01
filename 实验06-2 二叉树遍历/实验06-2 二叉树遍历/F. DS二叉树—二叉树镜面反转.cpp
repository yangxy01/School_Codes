#include<iostream>
using namespace std;


struct BiTreeNode
{
	char data;
	BiTreeNode* left;
	BiTreeNode* right;
};
struct QueNode
{
	BiTreeNode* data = NULL;
	QueNode* next = NULL;
};

class myqueue
{
	QueNode* head;
	QueNode* tail;
public:
	myqueue() { head = new QueNode; tail = head; }
	void push(BiTreeNode* newnode)
	{
		QueNode* p = new QueNode;
		p->data = newnode;
		if (head == tail)
		{
			head->next = p;
			tail = p;
		}
		else
		{
			QueNode* q = head->next;
			while (q != tail)
				q = q->next;
			q->next = p;
			tail = p;
		}
	}
	int empty()
	{
		if (tail == head)
			return 1;
		return 0;
	}
	BiTreeNode* front()
	{
		QueNode* first = head->next;
		return first->data;
	}
	void pop()
	{
		if (head == tail)
			return;
		else if (head->next == tail)
		{
			QueNode* p = tail;
			tail = head;
			delete p;
		}
		else
		{
			QueNode* q = head->next;
			head->next = q->next;
			delete q;
		}
	}
};

class BiTree
{
private:
	int pos;
	char* str;
	int len;
	BiTreeNode* root;
	void DeleteNode(BiTreeNode* node)
	{
		if (node == NULL)
			return;
		DeleteNode(node->left);
		DeleteNode(node->right);
		delete node;
	}
	BiTreeNode* CreateTree()
	{
		if (str[pos] == '#' || pos >= len)
		{
			pos++;
			return NULL;
		}
		BiTreeNode* newnode = new BiTreeNode;
		newnode->data = str[pos];
		pos++;
		newnode->left = CreateTree();
		newnode->right = CreateTree();
		return newnode;
	}
	void ReversalNode(BiTreeNode* node)//翻转节点的递归部分
	{
		if(node->left)
			ReversalNode(node->left);
		if (node->right)
			ReversalNode(node->right);
		if (node->left == NULL && node->right == NULL)
			return;
		else
		{
			BiTreeNode* tmp = node->left;
			node->left = node->right;
			node->right = tmp;
		}
	}

	void LevelOrder(BiTreeNode* node)
	{
		myqueue que;
		que.push(node);
		while (!que.empty())
		{
			BiTreeNode* p = que.front();
			que.pop();
			cout << p->data << " ";
			if (p->left)
				que.push(p->left);
			if (p->right)
				que.push(p->right);
		}
		cout << endl;
	}
	void PreOrder(BiTreeNode* node)
	{
		if (node == NULL)
			return;
		cout << node->data<<" ";
		PreOrder(node->left);
		PreOrder(node->right);
	}
	void InOrder(BiTreeNode* node)
	{
		if (node == NULL)
			return;
		InOrder(node->left);
		cout << node->data << " ";
		InOrder(node->right);
		
	}
	void PostOrder(BiTreeNode* node)
	{
		if (node == NULL)
			return;
		PostOrder(node->left);
		PostOrder(node->right);
		cout << node->data << " ";
	}

public:
	BiTree(char* s, int l) { root = NULL; pos = 0; str = s; len = l; }
	~BiTree() { DeleteNode(root); }
	void CreateTree(int len) {  root = CreateTree(); }

	void MirrorReversal() { ReversalNode(root); }
	void LevelOrder() { LevelOrder(root); }
	void PreOrder() { PreOrder(root); cout << endl; }
	void InOrder() { InOrder(root); cout << endl; }
	void PostOrder() { PostOrder(root); cout << endl; }
};

int main()
{
	int t;
	cin >> t;
	int len = 0;
	
	while (t--)
	{
		char str[100];
		cin >> str;
		if (str[0]=='#')
		{
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			continue;
		}
		int count = 0;
		while (str[count] != '\0')
			count++;
		len = count;
		BiTree T(str,len);
		T.CreateTree(len);
		T.MirrorReversal();
		T.PreOrder();
		T.InOrder();
		T.PostOrder();
		T.LevelOrder();
		for (int i = 0; i < 100; i++)
			str[i] = '\0';
	}
	return 0;
}