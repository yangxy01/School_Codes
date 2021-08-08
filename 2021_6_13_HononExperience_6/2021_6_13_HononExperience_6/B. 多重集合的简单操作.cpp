//#include<iostream>
//#include<set>
//using namespace std;
//
//int main()
//{
//	int t,num,x;
//	cin >> t;
//	multiset<int> myset;
//	while (t--)
//	{
//		cin >> num;
//		if (num == 1)
//		{
//			cin >> x;
//			myset.insert(x);
//		}
//		else if (num == 2)
//		{
//			if (!myset.empty())
//				myset.erase(myset.begin());
//		}
//		else if (num == 3)
//		{
//			if (!myset.empty())
//			{
//				cout << *(--myset.end()) << endl;
//				myset.erase(--myset.end());
//			}				
//		}
//	}
//	return 0;
//}