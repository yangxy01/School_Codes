//#include<iostream>
//using namespace std;
//
//class List
//{
//	int* mylist;
//	int len;
//public:
//	List(int l) :len(l)
//	{
//		mylist = new int[len];
//	}
//	~List()
//	{
//		if (mylist)
//			delete[]mylist;
//	}
//	void Createmylist()
//	{
//		int x;
//		for (int i = 0; i < len; i++)
//		{
//			cin >> x;
//			mylist[i] = x;
//		}
//	}
//	void InsertSort(int start,int gap)
//	{
//		int i, j;
//		i = start + gap;
//		while (i < len)
//		{
//			j = i;
//			while (j-gap >= start)
//			{
//				if (mylist[j] > mylist[j - gap])
//				{
//					int tmp = mylist[j];
//					mylist[j] = mylist[j - gap];
//					mylist[j - gap] = tmp;
//				}
//				else
//					break;
//				j -= gap;
//			}
//			i += gap;
//		}
//	}
//	void ShellSort()
//	{
//		int gap=len/2;
//		while (gap != 1)
//		{
//			for (int start = 0; start < gap; start++)
//			{
//				InsertSort(start, gap);
//			}
//			Show();
//			gap /= 2;
//		}
//		InsertSort(0, 1);
//		Show();
//	}
//	void Show()
//	{
//		for (int i = 0; i < len - 1; i++)
//			cout << mylist[i] << " ";
//		cout << mylist[len - 1] << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		List ls(n);
//		ls.Createmylist();
//		ls.ShellSort();
//		cout << endl;
//	}
//	return 0;
//}