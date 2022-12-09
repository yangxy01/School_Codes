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
//	void InsertSort()
//	{
//		int start = 1;
//		while (start < len)
//		{
//			int cur = start;
//			while (cur >= 1)
//			{
//				if (mylist[cur] < mylist[cur - 1])
//				{
//					int tmp = mylist[cur];
//					mylist[cur] = mylist[cur - 1];
//					mylist[cur - 1] = tmp;
//				}
//				else
//					break;
//				cur--;
//			}
//			Show();
//			start++;
//		}
//	}
//	void Show()
//	{
//		for (int i = 0; i < len - 1; i++)
//			cout << mylist[i] << " ";
//		cout << mylist[len-1] <<endl;
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	List ls(n);
//	ls.Createmylist();
//	ls.InsertSort();
//	return 0;
//}