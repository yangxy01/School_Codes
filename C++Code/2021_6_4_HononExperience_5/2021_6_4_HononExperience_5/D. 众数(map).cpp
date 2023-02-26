//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//#include<algorithm>
//using namespace std;
//
//struct cmp
//{
//	bool operator()(map<int, int> a, map<int, int> b)
//	{
//		
//		return a->second < b->second;
//	}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n,x,count=0,num1,num2;
//		cin >> n;
//		map<int, int> mapNum;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			mapNum[x]++;
//		}
//		num1 = mapNum.begin()->first;
//		num2 = mapNum.begin()->second;
//		auto a = max_element(mapNum.begin(), mapNum.end(), cmp());
//		cout << a->first << " " << a->second << endl;
//		//for (auto it = mapNum.begin(); it != mapNum.end(); it++)
//		//{
//		//	if (it->second > num2)
//		//	{
//		//		num1 = it->first;
//		//		num2 = it->second;
//		//	}
//		//}
//		//cout << num1 << " " << num2 << endl;
//
//
//	}
//	return 0;
//}
//
//
//
////#include<iostream>
////#include<queue>
////#include<vector>
////#include<map>
////#include<algorithm>
////using namespace std;
////struct cmp
////{
////	bool operator()(pair<int, int> a, pair<int, int> b)
////	{
////		return a.second < b.second;
////	}
////};
////int main()
////{
////	int t;
////	cin >> t;
////	while (t--)
////	{
////		map<int, int> m;
////		int n;
////		cin >> n;
////		for (int i = 0; i < n; i++)
////		{
////			int temp;
////			cin >> temp;
////			m[temp]++;
////		}
////		auto a = max_element(m.begin(), m.end(), cmp());
////		cout << a->first << " " << a->second << endl;
////	}
////
////}