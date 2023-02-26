//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//using namespace std;
//#define MAXSIZE 1000
//
//class SeqList
//{
//private:
//	int *list;
//	int capacity;
//	int size;
//public:
//	SeqList(int sz);
//	~SeqList();
//	int SeqListInsert(int pos, int x);
//	void multidel(int i, int n);
//	void multiinsert(int i, int n, int item[]);
//	void SeqListPrint();
//};
//SeqList::SeqList(int sz = MAXSIZE)
//{
//	capacity = sz>MAXSIZE ? sz : MAXSIZE;
//	list = new int[capacity];
//	size = 0;
//}
//
//int SeqList::SeqListInsert(int pos, int x)
//{
//	if (pos <= 0 || pos > size + 1)//位置不合法
//		return 0;
//	if (size == capacity)//扩容
//	{
//		capacity *= 2;
//		int*newlist = new int[capacity];
//		for (int i = 0; i < size; i++)
//		{
//			newlist[i] = list[i];
//		}
//		delete[]list;
//		list = newlist;
//	}
//	int end = size - 1;
//	pos -= 1;//转换为从0开始
//	while (end >= pos)
//	{
//		list[end + 1] = list[end];
//		end--;
//	}
//	list[pos] = x;
//	size++;
//	return 1;
//}
//
//void SeqList::multiinsert(int i, int n, int item[])
//{
//	int end = size - 1;
//	while (end >= i - 1)
//	{
//		list[end + n] = list[end];
//		end--;
//	}
//	for (int k = 0; k < n;k++)
//	{
//		list[i - 1] = item[k];
//		i++;
//	}
//	size += n;
//}
//
//void SeqList::multidel(int i, int n)
//{
//	int start = i + n - 1;
//	while (start < size)
//	{
//		list[i - 1] = list[start];
//		start++;
//		i++;
//	}
//	size -= n;
//}
//
//
//void SeqList::SeqListPrint()
//{
//	cout << size << " ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << list[i] << " ";
//	}
//	cout << endl;
//}
//
//SeqList::~SeqList()
//{
//	delete[]list;
//}
//
//
//int main()
//{
//	int state;
//	int n,num;
//	cin >> n;
//	SeqList ls(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		ls.SeqListInsert(i + 1, num);
//	}
//	ls.SeqListPrint();
//	int pos, k;
//	cin >> pos >> k;
//	int*item = new int[k];
//	for (int i = 0; i < k; i++)
//	{
//		cin >> num;
//		item[i] = num;
//	}
//	ls.multiinsert(pos, k, item);
//	ls.SeqListPrint();
//
//	cin >> pos >> k;
//	ls.multidel(pos, k);
//	ls.SeqListPrint();
//
//	delete[]item;
//	return 0;
//}