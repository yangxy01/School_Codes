//#define _CRT_SECURE_NO_WARNINGS 1
//#include <queue>
//#include <iostream>
//#include <string>
//#include<functional>
//#include <utility>
//using namespace std;
//
//struct message
//{
//	string name;
//	int para;
//	int level;
//	bool operator< (const message& obj) const
//	{
//		return level > obj.level;
//	}
//
//};
//
//int main()
//{
//	string name,order;
//	int para,level;
//	priority_queue<message>myq;
//	while (cin >> order)
//	{
//		if (order == "GET")
//		{
//			if (myq.empty())
//				cout << "EMPTY" << endl;
//			else
//			{
//				cout << myq.top().name << " " << myq.top().para << endl;
//				myq.pop();
//			}
//		}
//		else
//		{
//			cin >> name >> para >> level;
//			myq.push(message{ name,para,level });
//		}
//	}
//	
//
//	return 0;
//}
