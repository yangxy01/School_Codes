//#include<iostream>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//};
//
//class List
//{
//	int len;
//	Node* head;
//public:
//	List()
//	{
//		len = 0;
//		head = new Node;
//		if (head == NULL) { exit(-1); }
//		head->next = NULL;
//		head->data = 0;
//	}
//
//	void CreateList(int n)
//	{
//		int x;
//		Node* p = head;
//		while (n--)
//		{
//			cin >> x;
//			Node* newnode = new Node;
//			newnode->data = x;
//			newnode->next = NULL;
//			p->next = newnode;
//			p = p->next;
//		}
//	}
//
//	Node* GetPoint() { return head; }
//
//	bool Insert(int pos, int x)
//	{
//		if (pos <= 0 || pos > len + 1) { return false; }
//		int count = 1;
//		Node* p = head;
//		while (p && count < pos) { p = p->next; count++; }
//		Node* newnode = new Node;
//		newnode->data = x;
//		if (p)
//		{
//			newnode->next = p->next;
//			p->next = newnode;
//			len++;
//		}
//		return true;
//	}
//
//	bool Delete(int pos)
//	{
//		if (pos <= 0 || pos > len) { return false; }
//		int count = 1;
//		Node* p = head;
//		while (p && count < pos) { p = p->next; count++; }
//		if (p)
//		{
//			Node* q = p->next;
//			p->next = q->next;
//			delete q;
//			len--;
//		}
//
//		return true;
//	}
//
//	bool Search(int pos)
//	{
//		if (pos <= 0 || pos > len) { return false; }
//		int count = 1;
//		Node* p = head->next;
//		while (p && count < pos) { p = p->next; count++; }
//		if (p)
//			cout << p->data << endl;
//		return true;
//	}
//
//	void Traverse()
//	{
//		cout << len << ":" << " ";
//		Node* p = head->next;
//		while (p)
//		{
//			if (p->next == NULL)
//				break;
//			cout << p->data << " ";
//			p = p->next;
//		}
//		cout << p->data;
//		cout << endl;
//	}
//
//	void DeleteSame()
//	{
//		Node* p = head->next;
//		if (p == NULL) { return; }
//		while (p)
//		{
//			Node* front = p;
//			Node* tail = p;
//			while (tail)
//			{
//				tail = tail->next;
//				while (tail&&tail->data == p->data)
//				{
//					Node* q = tail;
//					tail = tail->next;
//					delete q;
//					len--;
//				}
//				front->next = tail;
//				front = tail;
//			}
//			p = p->next;
//		}
//	}
//
//	~List()
//	{
//		Node* p = head->next;
//		Node* q = NULL;
//		while (p)
//		{
//			q = p;  p = p->next;
//			delete q;
//			q = NULL;
//		}
//		delete head;
//		head = NULL;
//	}
//};
//
//
//
//int main()
//{
//	int n,t,x;
//	cin >> t;
//	while (t--)
//	{
//		List ls;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> x;
//			ls.Insert(i, x);
//		}
//		ls.DeleteSame();
//		ls.Traverse();
//	}
//	return 0;
//}
//
