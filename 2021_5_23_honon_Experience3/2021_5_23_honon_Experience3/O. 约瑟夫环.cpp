//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//#include<list>
//#include<algorithm>
//#include<functional>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		list<int> ls;
//		int n, k,x;
//		cin >> n;
//		for (int j = 1; j <= n;j++)
//		{
//			ls.push_back(j);
//		}
//		cin >> k;
//		auto it = ls.begin();
//		while (1)
//		{
//			for (int i = 0; i < k - 1; i++)
//			{
//				it++;
//				if (it == ls.end())
//					it = ls.begin();
//			}
//			cout << *it << " ";
//
//			if (it != --ls.end()) 
//			{
//				it = ls.erase(it); 
//			}
//			else
//			{
//				ls.pop_back();
//				it = ls.begin();
//			}
//			if (ls.size() == 1)
//				break;
//		}
//		cout << ls.back()<<endl;
//		ls.clear();
//	}
//}