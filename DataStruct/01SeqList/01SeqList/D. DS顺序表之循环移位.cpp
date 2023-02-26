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
//	void LeftMove();
//	void RightMove();
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
//void SeqList::LeftMove()
//{
//	int start = 0;
//	int num = list[0];
//	while (start < size-1)
//	{
//		list[start] = list[start+1];
//		start++;
//	}
//	list[size - 1] = num;
//}
//void SeqList::RightMove()
//{
//	int num = list[size - 1];
//	int end = list[size - 1];
//	while (end > 0)
//	{
//		list[end] = list[end-1];
//		end--;
//	}
//	list[0] = num;
//}
//
//void SeqList::SeqListPrint()
//{
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
//	int n, num;
//	cin >> n;
//	SeqList ls(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		ls.SeqListInsert(i + 1, num);
//	}
//	ls.SeqListPrint();
//	int pos,time;
//	cin >> pos;
//	if (pos == 1)
//	{
//		cin >> time;
//		while (time--)
//		{
//			ls.RightMove();
//		}
//	}
//	else
//	{
//		cin >> time;
//		while (time--)
//		{
//			ls.LeftMove();
//		}
//	}
//	ls.SeqListPrint();
//	cin >> pos;
//	if (pos == 1)
//	{
//		cin >> time;
//		while (time--)
//		{
//			ls.RightMove();
//		}
//	}
//	else
//	{
//		cin >> time;
//		while (time--)
//		{
//			ls.LeftMove();
//		}
//	}
//	ls.SeqListPrint();
//	return 0;
//}