//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//class List
//{
//	vector<string> vec;
//	vector<string> mergevec;
//	int num;
//public:
//	List(int n) { num = n; vec.resize(n); mergevec.resize(n); }
//	void Create()
//	{
//		for (int i = 0; i < num; i++)
//			cin >> vec[i];
//	}
//	void MergeSort()
//	{
//		int gap = 1;
//		int left, mid, right,i;
//		for (gap = 1; gap <= num; gap *= 2)
//		{
//			for (left = 0; left < num; left += 2 * gap)
//			{
//				mid = left + gap-1;
//				if (mid >= num-1)
//					break;
//				right = mid + gap;
//				if (right > num)
//				{
//					right = num - 1;
//				}
//				Merge(left, mid, right);
//				for (i = left; i <= right; i++)
//					vec[i] = mergevec[i];
//			}
//			Show();
//		}
//	}
//	void Merge(int left, int mid, int right)
//	{
//		int i = left;
//		int j = mid + 1;
//		int k = left;
//		while (i <= mid && j <= right)
//		{
//			if (vec[i] > vec[j])
//			{
//				mergevec[k] = vec[i];
//				i++;
//			}
//			else
//			{
//				mergevec[k] = vec[j];
//				j++;
//			}
//			k++;
//		}
//		while (i <= mid) { mergevec[k++] = vec[i++]; }
//		while (j <= right) { mergevec[k++] = vec[j++]; }
//	}
//	void Show()
//	{
//		int len = num;
//		for (int i = 0; i < len - 1; i++)
//			cout << vec[i] << " ";
//		cout << vec[len - 1] << endl;
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
//		ls.Create();
//		ls.MergeSort();
//		cout << endl;
//	}
//	return 0;
//}