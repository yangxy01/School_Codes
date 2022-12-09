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
//	
//	void QuickSort(int low,int high)
//	{
//		int Pivotkey, i=low, j=high;
//		Pivotkey = mylist[low];
//		while (i < j)
//		{
//			while (j > i && mylist[j] >= Pivotkey) { j--; }
//			if (j > i)
//			{
//				mylist[i] = mylist[j];
//				i++;
//			}
//			while (j > i && mylist[i] < Pivotkey) { i++; }
//			if (j > i)
//			{
//				mylist[j] = mylist[i];
//				j--;
//			}
//		}
//		mylist[i] = Pivotkey;
//		Show();
//		if(i-1>low)QuickSort(low,i-1);
//		if(j+1<high)QuickSort(i+1, high);
//	}
//
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
//		ls.QuickSort(0,n-1);
//		cout << endl;
//	}
//	return 0;
//}