//#include<iostream>
//using namespace std;
//
//class SeqList
//{
//	int* list;
//	int maxsize;
//	int size;
//public:
//	SeqList()
//	{
//		maxsize = 1000;
//		list = new int[maxsize];
//		size = 0;
//	}
//	~SeqList()
//	{
//		if (list) { delete[]list; list = NULL; }
//	}
//
//	bool Insert(int pos, int elem)
//	{
//		if (pos <= 0 || pos > size + 1) { return false; }
//		int end = size - 1;
//		while (end >= pos - 1) { list[end + 1] = list[end]; end--; }
//		list[pos - 1] = elem;
//		size++;
//		return true;
//	}
//
//	void MutiInsert(int pos,int n)
//	{
//		int x;
//		while (n--)
//		{
//			cin >> x;
//			Insert(pos++, x);
//		}
//	}
//
//	void MutiDelete(int pos, int n)
//	{
//		while(n--)
//			Delete(pos);
//	}
//
//	bool Delete(int pos)
//	{
//		if (pos <= 0 || pos > size) { return false; }
//		int i = pos - 1;
//		while (i < size)
//		{
//			list[i] = list[i + 1];
//			i++;
//		}
//		size--;
//		return true;
//	}
//
//	bool Search(int pos)
//	{
//		if (pos <= 0 || pos > size) { return false; }
//		cout << list[pos - 1] << endl;
//		return true;
//	}
//
//	void Traverse()
//	{
//		cout << size << " ";
//		if (size == 0)
//		{
//			cout << "empty" << endl;
//			return;
//		}
//		for (int i = 0; i < size; i++)
//			cout << list[i] << " ";
//		cout << endl;
//	}
//};
//
//int main()
//{
//	int n, x;
//	cin >> n;
//	SeqList sq;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x;
//		if (!sq.Insert(i, x))
//			break;
//	}
//	sq.Traverse();
//	
//	int pos;
//	cin >> pos >> n;
//	sq.MutiInsert(pos, n);
//	sq.Traverse();
//	cin >> pos >> n;
//	sq.MutiDelete(pos, n);
//	sq.Traverse();
//
//	return 0;
//}