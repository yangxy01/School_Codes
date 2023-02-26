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
//	
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
//		cout << GetLength() << ": ";
//		Node* cur = head->next;
//		while (cur->next)
//		{
//			cout << cur->data << " ";
//			cur = cur->next;
//		}
//		cout << cur->data;
//		cout << endl;
//	}
//
//	void DeleteSame()
//	{
//		if (head == NULL || head->next == NULL)
//			return;
//		Node* cur = head->next;
//		Node* p = NULL;
//		Node* q = NULL;
//		int i = 1;
//		
//		while (cur)
//		{
//			q = cur;
//			p = cur->next;
//			while (p)
//			{
//				if (p->data == cur->data)
//				{
//					q->next = p->next ;
//					delete p;
//					p = q->next;
//					continue;
//				}
//				q = p;
//				p = p->next;
//			}
//			cur = cur->next;
//		}
//	}
//
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, x;
//		cin >> n;
//		SList ls1;
//		while (n--)
//		{
//			cin >> x;
//			ls1.PushBack(x);
//		}
//		ls1.DeleteSame();
//		ls1.Traverse();
//	}
//
//	return 0;
//}