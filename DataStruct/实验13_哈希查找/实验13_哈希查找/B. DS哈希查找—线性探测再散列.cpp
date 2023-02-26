//#include<iostream>
//using namespace std;
//
//
//class HashSearchTable
//{
//	int* HashTable;
//	int len;
//public:
//	int HashCount;
//	int HashPos;
//	HashSearchTable(int m = 11)
//	{
//		len = m;
//		HashPos = 0;
//		HashCount = 0;
//		HashTable = new int[len];
//		for (int i = 0; i < len; i++)
//		{
//			HashTable[i] = 0;
//		}
//	}
//	~HashSearchTable() { delete[]HashTable; }
//	int Hash(int Key)
//	{
//		return Key % 11;
//	}
//	int Search(int key)
//	{
//		HashCount = 0;
//		int add = Hash(key);
//		while (HashTable[add] != 0 && HashTable[add] != key)
//		{
//			HashCount++;
//			add++;
//			if (add >= len)
//				add %= len;
//		}
//		if (HashTable[add] == key)
//		{
//			HashCount++;
//			HashPos = add;
//			return 1;
//		}
//		else
//		{
//			HashCount++;
//			HashTable[add] = key;
//			return 0;
//		}
//	}
//	int SearchB(int key)
//	{
//		HashCount = 0;
//		int add = Hash(key);
//		while (HashTable[add] != 0 && HashTable[add] != key)
//		{
//			HashCount++;
//			add++;
//			if (add >= len)
//				add %= len;
//		}
//		if (HashTable[add] == key)
//		{
//			HashCount++;
//			HashPos = add;
//			return 1;
//		}
//		else
//		{
//			HashCount++;
//			return 0;
//		}
//	}
//	void Create(int x)
//	{
//		Search(x);
//	}
//	void Display()
//	{
//		int i;
//		for (i = 0; i < len - 1; i++)
//		{
//			if (HashTable[i] != 0)
//				cout << HashTable[i] << " ";
//			else
//				cout << "NULL" << " ";
//		}
//		if (HashTable[i] != 0)
//			cout << HashTable[i];
//		else
//			cout << "NULL" << " ";
//		cout << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, x, m, k;
//		cin >> m >> n;
//		HashSearchTable HST(m);
//		while (n--)
//		{
//			cin >> x;
//			HST.Create(x);
//		}
//		HST.Display();
//		cin >> k;
//		while (k--)
//		{
//			cin >> x;
//			int ret = HST.SearchB(x);
//			if (ret)
//			{
//				cout << "1 " << HST.HashCount << " " << HST.HashPos+1 << endl;
//			}
//			else
//				cout << "0 " << HST.HashCount << endl;
//			
//		}
//	}
//	return 0;
//}
//
//
//
