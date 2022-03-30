//#include<iostream>
//using namespace std;
//
//class SeqList
//{
//	int len;
//	int* arr;
//public:
//	SeqList(int n = 0)
//	{
//		arr = new int[n+1];
//		len = n;
//		arr[0] = 0;
//		for (int i = 1; i <= n; i++)
//			cin >> arr[i];
//	}
//	int Search(int num)
//	{
//		arr[0] = num;
//		int i=len;
//		while (arr[i] != num)
//			i--;
//		return i;
//	}
//	~SeqList()
//	{
//		delete[]arr;
//		arr = nullptr;
//		len = 0;
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	SeqList seq(n);
//	int m;
//	cin >> m;
//	while (m--)
//	{	
//		int num;
//		cin >> num;
//		if (seq.Search(num))
//			cout << seq.Search(num) << endl;
//		else
//			cout << "error" << endl;
//	}
//	return 0;
//}