//#include<iostream>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//};
//
//class SList
//{
//private:
//	Node* head;
//public:
//	SList()
//	{
//		head = BuyNode(0);
//	}
//	SList(int* r, int n)
//	{
//		head = BuyNode(0);
//		for (int i = 0; i < n; i++)
//		{
//			PushBack(r[i]);
//		}
//	}
//	~SList()
//	{
//		if (head)
//		{
//			Node* p = head;
//			Node* q = NULL;
//			while (p)
//			{
//				q = p;
//				p = p->next;
//				delete q;
//			}
//		}
//	}
//	Node* GetPointer(int i)
//	{
//		if (i == 0)
//			return head;
//		Node* cur = head->next;
//		int j = 1;
//		while (cur && j < i)
//		{
//			cur = cur->next;
//			j++;
//		}
//		if (cur == NULL)
//			return NULL;
//		return cur;
//	}
//	Node* BuyNode(int x)
//	{
//		Node* newnode = new Node;
//		newnode->data = x;
//		newnode->next = NULL;
//		return newnode;
//	}
//
//	void PushBack(int x)
//	{
//		Node* newnode = BuyNode(x);
//		Node* tail = head;
//		while (tail->next) { tail = tail->next; }
//		tail->next = newnode;
//	}
//
//	int GetLength()
//	{
//		Node* p = head->next;
//		int count = 0;
//		while (p)
//		{
//			count++;
//			p = p->next;
//		}
//		return count;
//	}
//
//	bool DeleteItem(int i)
//	{
//		if (i <= 0 || i > GetLength())
//			return false;
//		Node* p = GetPointer(i - 1);
//		Node* q = p->next;
//		p->next = p->next->next;
//		if (q)
//			delete q;
//		return true;
//	}
//	bool InsertItem(int i, int x)
//	{
//		if (i <= 0 || i > GetLength() + 1)
//			return false;
//
//		Node* newnode = BuyNode(x);
//		if (head->next == NULL)
//			PushBack(x);
//		else
//		{
//			Node* p = GetPointer(i - 1);
//			newnode->next = p->next;
//			p->next = newnode;
//		}
//		return true;
//	}
//
//	int GetVal(int i)
//	{
//		Node* p = GetPointer(i);
//		if (p == NULL)
//			return -1;
//		return p->data;
//	}
//
//	void Traverse()
//	{
//		Node* cur = head->next;
//		while (cur)
//		{
//			cout << cur->data << " ";
//			cur = cur->next;
//		}
//		cout << endl;
//	}
//
//	bool Swap(int pos1, int pos2)
//	{
//		if (pos1 <= 0 || pos1 > GetLength())
//			return false;
//		if (pos2 <= 0 || pos2 > GetLength())
//			return false;
//		if (pos1 > pos2)//pos1Ò»¶¨Òª<pos2
//		{
//			int tmp = pos1;
//			pos1 = pos2;
//			pos2 = tmp;
//		}
//		if (pos1 + 1 == pos2)
//		{
//			Node* a = GetPointer(pos1 - 1);
//			Node* b = GetPointer(pos1);
//			Node* c = GetPointer(pos2);
//			b->next = c->next;
//			c->next = b;
//			a->next = c;
//		}
//		else
//		{
//			Node* a = GetPointer(pos1 - 1);
//			Node* b = GetPointer(pos1);
//			Node* c = GetPointer(pos2 - 1);
//			Node* d = GetPointer(pos2);
//			Node* e = d->next;
//
//			d->next = b->next;
//			b->next = e;
//
//			a->next = d;
//			c->next = b;
//		}
//
//		return true;
//	}
//
//};
//
//int main()
//{
//
//	int n, x, pos1,pos2;
//	cin >> n;
//	SList ls;
//	while (n--)
//	{
//		cin >> x;
//		ls.PushBack(x);
//	}
//	ls.Traverse();
//	cin >> pos1 >> pos2;
//	if (ls.Swap(pos1, pos2))
//		ls.Traverse();
//	else
//		cout << "error" << endl;
//	cin >> pos1 >> pos2;
//	if (ls.Swap(pos1, pos2))
//		ls.Traverse();
//	else
//		cout << "error" << endl;
//
//	return 0;
//}