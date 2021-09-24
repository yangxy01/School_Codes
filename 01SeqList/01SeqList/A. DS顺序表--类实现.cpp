//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//using namespace std;
//#define MAXSIZE 8
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
//	int SeqListSize();
//	int SeqListInsert(int pos, int x);
//	int SeqListErase(int pos);
//	int SeqListSearch(int pos);
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
//	if (pos <= 0 || pos > size+1)//位置不合法
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
//int SeqList::SeqListErase(int pos)
//{
//	if (pos <= 0 || pos > size)//位置不合法
//		return 0;
//	int start = pos-1;
//	while (start < size-1)
//	{
//		list[start] = list[start+1];
//		start++;
//	}
//	size--;
//	return 1;
//}
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
//int SeqList::SeqListSearch(int pos)
//{
//	if (pos <= 0 || pos > size + 1)//位置不合法
//		return 0;
//	return list[pos - 1];
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
//	int size,num,pos;
//	cin >> size;
//	SeqList ls(size);
//	for (int i = 0; i < size; i++)
//	{
//		cin >> num;
//		ls.SeqListInsert(i+1, num);
//	}
//	ls.SeqListPrint();
//	cin >> pos >> num;
//	state = ls.SeqListInsert(pos, num);
//	if (state == 0)
//		cout << "error" << endl;
//	else
//		ls.SeqListPrint();
//	cin >> pos >> num;
//	state = ls.SeqListInsert(pos, num);
//	if (state == 0)
//		cout << "error" << endl;
//	else
//		ls.SeqListPrint();
//	cin >> pos;
//	state = ls.SeqListErase(pos);
//	if (state == 0)
//		cout << "error" << endl;
//	else
//		ls.SeqListPrint();
//	cin >> pos;
//	state = ls.SeqListErase(pos);
//	if (state == 0)
//		cout << "error" << endl;
//	else
//		ls.SeqListPrint();
//
//	cin >> pos;
//	state = ls.SeqListSearch(pos);
//	if (state == 0)
//		cout << "error" << endl;
//	else
//		cout << state << endl;
//	cin >> pos;
//	state = ls.SeqListSearch(pos);
//	if (state == 0)
//		cout << "error" << endl;
//	else
//		cout << state << endl;
//
//	return 0;
//}