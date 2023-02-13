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
//		Node* p = head->next;
//		while (p)
//		{
//			cout << p->data << " ";
//			p = p->next;
//		}
//		cout << endl;
//	}
//
//	~List()
//	{
//		Node* p = head->next;
//		Node* q = NULL;
//		while (p) 
//		{ 
//			q = p;  p = p->next; 
//			cout << "delete " << q->data << endl;
//			delete q; 
//			q = NULL; 
//		}
//		delete head;
//		head = NULL;
//	}
//};
//
//void Merge(Node* ls1, Node* ls2)
//{
//	Node* p = ls1->next;
//	Node* q = ls2->next;
//	Node* next;
//	while (p && q)
//	{
//		if (p->data < q->data)
//		{
//			next = p->next;
//			p->next = q;
//			p = next;
//		}
//		else
//		{
//			next = q->next;
//			q->next = p;
//			q = next;
//		}
//	}
//	Node* head = ls1;
//	if (ls1->next->data > ls2->next->data)
//		head = ls2;
//	p = head->next;
//	while (p) { cout << p->data << " "; p = p->next; }
//	cout << endl;
//}
//
//
//int main()
//{
//	int n1,n2;
//	List ls1;
//	List ls2;
//	int x;
//	cin >> n1;
//	for (int i = 1; i <= n1; i++)
//	{
//		cin >> x;
//		ls1.Insert(i,x);
//	}
//	cin >> n2;
//	for (int i = 1; i <= n2; i++)
//	{
//		cin >> x;
//		ls2.Insert(i,x);
//	}
//	Merge(ls1.GetPoint(), ls2.GetPoint());
//	return 0;
//}
//
