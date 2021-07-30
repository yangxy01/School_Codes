//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<string>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		vector<int>vec;
//		vector<int>::iterator pend;
//		for (int i = 2; i <= n; i++)
//		{
//			vec.push_back(i);
//		}
//		
//		for_each(vec.begin(), vec.end(), [&](int& i)
//		{
//			pend = remove_if(vec.begin(), vec.end(), [&](int& j)
//			{return i != j && (j % i == 0); });
//			vec.erase(pend, vec.end());
//			
//		});
//		for_each(vec.begin(), vec.end()-1, [](int i ) {cout << i << " "; });
//		cout << *(vec.end()-1) << endl;
//
//	}
//}