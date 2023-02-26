//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <deque>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	deque<int> que;
//	vector<int> vec;
//	int t,x;
//	string oper;
//	cin >> t;
//	for (int i = 1; i <= t; i++)
//	{
//		cin >> oper;
//		if (oper == "LIN")
//		{
//			cin >> x;
//			que.push_front(x);
//		}
//		else if (oper == "RIN")
//		{
//			cin >> x;
//			que.push_back(x);
//		}
//		else if (oper == "LOUT")
//		{
//			if (que.size() != 0)
//				que.pop_front();
//			else
//				vec.push_back(i);
//		}
//		else if (oper == "ROUT")
//		{
//			if (que.size() != 0)
//				que.pop_back();
//			else
//				vec.push_back(i);
//		}
//	}
//	deque<int>::iterator it;
//	vector<int>::iterator ite;
//	if (que.empty())
//		cout << "EMPTY" << endl;
//	else
//	{
//		for (it = que.begin(); it < que.end(); it++)
//		{
//			cout << *it << " ";
//		}
//		cout << endl;
//	}
//	for (ite = vec.begin(); ite < vec.end(); ite++)
//		cout << *ite << " ERROR" << endl;
//
//	return 0;
//}