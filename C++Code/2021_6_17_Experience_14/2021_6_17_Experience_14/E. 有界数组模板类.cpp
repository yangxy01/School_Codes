//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T>class BoundArray
//{
//	T* p;
//	int n;
//public:
//	BoundArray(T*pp, int nn)
//	{
//		n = nn;
//		p = new T[n];
//		for (int i = 0; i < n; i++)
//		{
//			p[i] = pp[i];
//		}
//	}
//	void myfind(T key)
//	{
//		int i;
//		int flag = 1;
//		for (i = 0; i < n; i++)
//		{
//			if (p[i] == key)
//			{
//				cout << i  << endl;
//				flag = 0;
//			}
//		}
//		if (flag)
//		cout << "-1" << endl;
//	}
//	void mysort()
//	{
//		int i, j;
//		for (i = 0; i < n; i++)//从小到大排序
//		{
//			for (j = 0; j < n - 1 - i; j++)
//			{
//				if (p[j]>p[j + 1])
//				{
//					T tmp = p[j];
//					p[j] = p[j + 1];
//					p[j + 1] = tmp;
//				}
//			}
//		}
//		for (i = 0; i < n; i++)
//		{
//			cout << p[i] << " ";
//		}
//		cout << endl;
//	}
//	~BoundArray()
//	{
//		delete[]p;
//	}
//};
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
//			BoundArray<int> Bon(p, n);
//			Bon.mysort();
//			int key;
//			cin >> key;
//			Bon.myfind(key);
//
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
//			BoundArray<char> Bon(p, n);
//			Bon.mysort();
//			char key;
//			cin >> key;
//			Bon.myfind(key);
//			delete[]p;
//		}
//		else if (type == 'D')
//		{
//			cin >> n;
//			double*p = new double[n];
//			double obj;
//			for (int i = 0; i < n; i++)
//			{
//				cin >> obj;
//				p[i] = obj;
//			}
//			BoundArray<double> Bon(p, n);
//			Bon.mysort();
//			double key;
//			cin >> key;
//			Bon.myfind(key);
//			delete[]p;
//		}
//		
//	}
//
//	return 0;
//}



