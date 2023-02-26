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
//	bool Insert(int pos,int x)
//	{
//		if (pos<=0 || pos>len + 1) { return false; }
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
//		if (pos<=0 || pos>len) { return false; }
//		int count = 1;
//		Node* p = head->next;
//		while (p && count < pos) { p = p->next; count++; }
//		if(p)
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
//		while (p) { q = p;  p = p->next; delete q;}
//		delete head;
//	}
//};
///*
//4 5 9 15 36
//6 999
//5 999
//0
//1
//5
//4
//*/
//
//int main()
//{
//	int n, x;
//	cin >> n;
//	List ls;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x;
//		ls.Insert(i, x);
//	}
//	//ls.CreateList(n);
//	ls.Traverse();
//	int pos;
//	cin >> pos >> x;
//	if (!ls.Insert(pos, x)) { cout << "error" << endl; }
//	else { ls.Traverse(); }
//	cin >> pos >> x;
//	if (!ls.Insert(pos, x)) { cout << "error" << endl; }
//	else { ls.Traverse(); }
//
//	cin >> pos;
//	if (!ls.Delete(pos)) { cout << "error" << endl; }
//	else { ls.Traverse(); }
//	cin >> pos;
//	if (!ls.Delete(pos)) { cout << "error" << endl; }
//	else { ls.Traverse(); }
//
//	cin >> pos;
//	if (!ls.Search(pos)) { cout << "error" << endl; }
//	cin >> pos;
//	if (!ls.Search(pos)) { cout << "error" << endl; }
//	return 0;
//}
//
