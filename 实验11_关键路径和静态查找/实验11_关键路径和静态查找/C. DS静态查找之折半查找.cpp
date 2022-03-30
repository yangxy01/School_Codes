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
//		arr = new int[n];
//		len = n;
//		for (int i = 0; i < n; i++)
//			cin >> arr[i];
//	}
//	int BinarySearch(int num)
//	{
//		int left = 0;
//		int right = len - 1;
//		while (left <= right)
//		{
//			int mid = (left + right) / 2;
//			if (arr[mid] == num)
//				return mid;
//			else if (arr[mid] < num)
//			{
//				left = mid + 1;
//			}
//			else if (arr[mid] > num)
//			{
//				right = mid - 1;
//			}
//		}
//		return 0;
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
//		if (seq.BinarySearch(num))
//			cout << seq.BinarySearch(num)+1 << endl;
//		else
//			cout << "error" << endl;
//	}
//	return 0;
//}