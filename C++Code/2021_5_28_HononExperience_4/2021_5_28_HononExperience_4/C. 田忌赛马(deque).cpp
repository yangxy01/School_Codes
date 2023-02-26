//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <deque>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n,x,score=0;
//		cin >> n;
//		deque<int> que1;//田忌
//		deque<int> que2;//大王
//		deque<int> que3;//不同的队列组合
//		for (int i = 0; i < n; i++){ cin >> x; que1.push_back(x); }
//		for (int i = 0; i < n; i++){ cin >> x; que2.push_back(x); }
//		
//		while (n--)
//		{
//			if (que1.back()<=que2.back())
//			{
//				score--;
//				que1.pop_back();
//				que2.pop_front();
//				continue;
//			}
//			else
//			{
//				score++;
//				que1.pop_back();
//				que2.pop_back();
//				continue;
//			}
//		}
//		if (score > 0)
//			cout << "1" << endl;
//		else
//			cout << "0" << endl;
//	}
//	return 0;
//}