//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T>
//void choose(T*p, int n)
//{
//	int count = 0,countmax=0,i,j;
//	T maxobj,obj;
//	for (i = 0; i < n; i++)//从小到大排序
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (p[j]>p[j + 1])
//			{
//				T tmp = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = tmp;
//			}
//		}
//	}
//	obj = p[0];
//	for (i = 0; i < n; i++)
//	{
//		if (p[i] != obj)//换对象了
//		{
//			j = i;
//			break;
//		}
//		count++;
//		
//	}
//	if (i == n){ j = n; }
//	countmax = count;
//	maxobj = obj;
//	while (j<n)
//	{
//		if (p[j] != obj)
//		{		
//			if (count>countmax)
//			{
//				countmax = count;
//				maxobj = obj;
//			}
//			obj = p[j];
//			count = 1;
//		}
//		else
//		{
//			count++;
//		}
//		j++;
//	}
//	if (count>countmax)
//	{
//		countmax = count;
//		maxobj = p[j-1];
//	}
//	cout << maxobj << " " << countmax << endl;
//	
//}
//
//int main()
//{
//	int t,n;
//	cin >> t;
//	while (t--)
//	{
//		char type;
//		cin >> type;
//		if (type == 'I')
//		{
//			cin >> n;
//			int*p = new int[n];
//			int obj;
//			for (int i = 0; i < n; i++)
//			{
//				cin >> obj;
//				p[i] = obj;
//			}
//			choose(p, n);
//			delete[]p;
//		}
//		else if (type == 'C')
//		{
//			cin >> n;
//			char*p = new char[n];
//			char obj;
//			for (int i = 0; i < n; i++)
//			{
//				cin >> obj;
//				p[i] = obj;
//			}
//			choose(p, n);
//			delete[]p;
//		}
//		else if (type == 'S')
//		{
//			cin >> n;
//			string*p = new string[n];
//			string obj;
//			for (int i = 0; i < n; i++)
//			{
//				cin >> obj;
//				p[i] = obj;
//			}
//			choose(p, n);
//			delete[]p;
//		}
//	}
//
//	return 0;
//}