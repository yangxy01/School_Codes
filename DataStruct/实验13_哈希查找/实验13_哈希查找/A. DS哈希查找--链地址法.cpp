//#include<iostream>
//using namespace std;
//#define HASHLISTLEN	11	
//
//struct Node
//{
//	int data;
//	Node* next = NULL;
//};
//
//class HashSearchTable
//{
//	Node HashTable[HASHLISTLEN];
//public:
//	int HashCount;
//	HashSearchTable()
//	{
//		HashCount = 0;
//		for (int i = 0; i < HASHLISTLEN; i++)
//		{
//			HashTable[i].next = NULL;
//			HashTable[i].data = 0;
//		}
//	}
//	int Hash(int Key)
//	{
//		return Key % HASHLISTLEN;
//	}
//	Node* Search(int key)
//	{
//		HashCount = 0;
//		Node* p, *q;
//		int add = Hash(key);
//		p = HashTable[add].next;
//		while (p)
//		{
//			HashCount++;
//			if (p->data == key)
//				return p;
//			else
//				p = p->next;
//		}
//		q = new Node;
//		q->data = key;
//		q->next = HashTable[add].next;
//		HashTable[add].next = q;
//		return NULL;
//	}
//	void Create(int x)
//	{
//		Search(x);
//	}
//
//};
//
//int main()
//{
//	HashSearchTable HST;
//	int n, x, t;
//	cin >> n;
//	while (n--)
//	{
//		cin >> x;
//		HST.Create(x);
//	}
//	cin >> t;
//	while (t--)
//	{
//		cin >> x;
//		Node* p = HST.Search(x);
//		if (p == NULL)
//			cout << "error" << endl;
//		else
//		{
//			cout << HST.Hash(x) <<" "<< HST.HashCount << endl;
//		}
//	}
//	return 0;
//}
//
//
//
