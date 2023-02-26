#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
#define MAXSIZE 1000

class SeqList
{
private:
	int *list;
	int capacity;
	int size;
public:
	SeqList(int sz = MAXSIZE);
	SeqList(const SeqList&ls);
	~SeqList();
	int SeqListInsert(int pos, int x);
	SeqList CombineList( const SeqList &ls);
	void SeqListPrint();
};

SeqList::SeqList(int s )
{
	capacity = s>MAXSIZE ? s : MAXSIZE;
	list = new int[capacity];
	size = 0;
}

SeqList::SeqList(const SeqList&ls) :list(new int[ls.size])
{
	size = ls.size;
	capacity = ls.capacity;
	for (int i = 0; i<size; i++)
	{
		list[i] = ls.list[i];
	}
}

int SeqList::SeqListInsert(int pos, int x)
{
	if (pos <= 0 || pos > size + 1)//位置不合法
		return 0;
	if (size == capacity)//扩容
	{
		capacity *= 2;
		int*newlist = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			newlist[i] = list[i];
		}
		delete[]list;
		list = newlist;
	}
	int end = size - 1;
	pos -= 1;//转换为从0开始
	while (end >= pos)
	{
		list[end + 1] = list[end];
		end--;
	}
	list[pos] = x;
	size++;
	return 1;
}

SeqList SeqList::CombineList(const SeqList &ls)
{
	SeqList res(size + ls.size);
	res.size = size + ls.size;
	int a = 0, b = 0,i=0;
	while (size-a && ls.size-b)
	{
		if (list[a] < ls.list[b])
		{
			res.list[i] = list[a];
			a++;
			i++;
		}
		else
		{
			res.list[i] = ls.list[b];
			b++;
			i++;
		}
	}
	while (size-a)
	{
		res.list[i]=list[a];
		i++;
		a++;
	}
	while (ls.size - b)
	{
		res.list[i] = ls.list[b];
		b++;
		i++;
	}
	return res;
}

void SeqList::SeqListPrint()
{
	cout << size << " ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

SeqList::~SeqList()
{
	delete[]list;
}

int main()
{
	SeqList ls;

	return 0;
}
//int main()
//{
//	int n, m, num;
//	cin >> n;
//	SeqList ls1(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		ls1.SeqListInsert(i + 1, num);
//	}
//	cin >> m;
//	SeqList ls2(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> num;
//		ls2.SeqListInsert(i + 1, num);
//	}
//
//	SeqList ls3 = ls1.CombineList(ls2);
//	ls3.SeqListPrint();
//	return 0;
//}

