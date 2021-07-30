//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<list>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	list<int> ls;
//	int key;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> key;
//		ls.push_back(key);
//	}
//	while (m--)
//	{
//		list<int>::iterator ite1;
//		list<int>::iterator ite2;
//		cin >> key;
//		ite1 = find(ls.begin(), ls.end(), key);
//		ite2 = ls.end();
//		ite2--;
//		if (ite1 == ls.begin())
//		{
//			ite1++;
//			cout << *(ite1) << endl;
//		}
//		else if (ite1 == ite2)
//		{
//			ite1--;
//			cout << *(ite1) << endl;
//		}
//		else
//		{
//			cout << *(--ite1) << " ";
//			ite1++;
//			cout << *(++ite1) << endl;
//		}
//	}
//}