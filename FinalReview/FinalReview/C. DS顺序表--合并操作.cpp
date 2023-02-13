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
//	int GetElem(int pos)
//	{
//		if (pos <= 0 || pos > size) { return -1; }
//		else { return list[pos - 1]; }
//	}
//
//	int GetSize()
//	{
//		return size;
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
//void Merge(SeqList& sq1, SeqList& sq2, SeqList& sq)
//{
//	int i = 0, j = 0, k = 1;
//	while (i < sq1.GetSize() && j < sq2.GetSize())
//	{
//		if (sq1.GetElem(i + 1) < sq2.GetElem(j + 1))
//		{
//			sq.Insert(k++, sq1.GetElem(i + 1));
//			i++;
//		}
//		else
//		{
//			sq.Insert(k++, sq2.GetElem(j + 1));
//			j++;
//		}
//	}
//	while (i < sq1.GetSize()) { sq.Insert(k++, sq1.GetElem(i + 1)); i++; }
//	while (j < sq2.GetSize()) { sq.Insert(k++, sq2.GetElem(j + 1)); j++; }
//}
//
//int main()
//{
//	int n, x;
//	cin >> n;
//	SeqList sq1;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x;
//		if (!sq1.Insert(i, x))
//			break;
//	}
//
//	cin >> n;
//	SeqList sq2;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x;
//		if (!sq2.Insert(i, x))
//			break;
//	}
//
//	SeqList sq;
//	Merge(sq1, sq2, sq);
//	sq.Traverse();
//
//	return 0;
//}