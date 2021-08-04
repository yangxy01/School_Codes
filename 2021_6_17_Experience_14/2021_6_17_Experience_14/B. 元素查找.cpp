//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T>
//void myfind(T*p, int n, T key)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		if (p[i] == key)
//		{
//			cout << i+1 << endl;
//			return;
//		}
//	}
//	cout << "0" << endl;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		char type;
//		int n;
//		cin >> type;
//		if (type == 'I')
//		{
//			cin >> n;
//			int*p = new int[n];
//			int obj,key;
//			for (int i = 0; i < n; i++)
//			{
//				cin >> obj;
//				p[i] = obj;
//			}
//			cin >> key;
//			myfind(p, n, key);
//			delete[]p;
//		}
//		else if (type == 'D')
//		{
//			cin >> n;
//			double*p = new double[n];
//			double obj, key;
//			for (int i = 0; i < n; i++)
//			{
//				cin >> obj;
//				p[i] = obj;
//			}
//			cin >> key;
//			myfind(p, n, key);
//			delete[]p;
//		}
//		else if (type == 'S')
//		{
//			cin >> n;
//			string*p = new string[n];
//			string obj, key;
//			for (int i = 0; i < n; i++)
//			{
//				cin >> obj;
//				p[i] = obj;
//			}
//			cin >> key;
//			myfind(p, n, key);
//			delete[]p;
//		}
//		else if (type == 'C')
//		{
//			cin >> n;
//			char*p = new char[n];
//			char obj,key;
//			for (int i = 0; i < n; i++)
//			{
//				cin >> obj;
//				p[i] = obj;
//			}
//			cin >> key;
//			myfind(p, n, key);
//			delete[]p;
//		}
//	}
//	return 0;
//}