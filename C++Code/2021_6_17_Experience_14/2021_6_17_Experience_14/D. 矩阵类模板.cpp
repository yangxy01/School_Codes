//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T>class Matrix
//{
//	int m, n;
//	T** M;
//public:
//	Matrix(T**p,int mm,int nn)
//	{
//		m = mm;
//		n = nn;
//		M = new T*[m];
//		for (int i = 0; i < m; i++)
//			M[i] = new T[n];
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//				M[i][j] = p[i][j];
//		}
//	}
//
//	void transport()
//	{
//		T** MM = NULL;
//		MM = new T*[n];
//		for (int i = 0; i < n; i++)
//			MM[i] = new T[m];
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//				MM[i][j] = M[j][i];
//		}
//		M = MM;
//		int tmp = n;
//		n = m;
//		m = tmp;
//	}
//
//	void print()
//	{
//		int j;
//		for (int i = 0; i < m; i++)
//		{
//			for (j= 0; j < n-1; j++)
//			{
//				cout << M[i][j] << " ";
//			}
//			cout << M[i][j] <<endl;
//		}
//	}
//	~Matrix()
//	{
//		for (int i = 0; i < m; i++)
//			delete[]M[i];
//		delete[]M;
//		cout << "666" << endl;
//	}
//};
//
//int main()
//{
//	int t, m,n;
//	cin >> t;
//	while (t--)
//	{
//		char type;
//		cin >> type;
//		if (type == 'I')
//		{
//			cin >> m>>n;
//			int**p = new int*[m];
//			for (int i = 0; i < m; i++)
//				p[i] = new int[n];
//			int obj;
//			for (int i = 0; i < m; i++)
//			{
//				for (int j = 0; j < n; j++)
//				{
//					cin >> obj;
//					p[i][j] = obj;
//				}
//			}
//			Matrix<int> mar(p, m, n);
//			mar.transport();
//			mar.print();
//			for (int i = 0; i < m; i++)
//				delete[]p[i];
//			delete[]p;
//		}
//		else if (type == 'D')
//		{
//			cin >> m >> n;
//			double**p = new double*[m];
//			for (int i = 0; i < m; i++)
//				p[i] = new double[n];
//			double obj;
//			for (int i = 0; i < m; i++)
//			{
//				for (int j = 0; j < n; j++)
//				{
//					cin >> obj;
//					p[i][j] = obj;
//				}
//			}
//			Matrix<double> mar(p, m, n);
//			mar.transport();
//			mar.print();
//			for (int i = 0; i < m; i++)
//				delete[]p[i];
//			delete[]p;
//		}
//		else if (type == 'C')
//		{
//			cin >> m >> n;
//			char**p = new char*[m];
//			for (int i = 0; i < m; i++)
//				p[i] = new char[n];
//			char obj;
//			for (int i = 0; i < m; i++)
//			{
//				for (int j = 0; j < n; j++)
//				{
//					cin >> obj;
//					p[i][j] = obj;
//				}
//			}
//			Matrix<char> mar(p, m, n);
//			mar.transport();
//			mar.print();
//			for (int i = 0; i < m; i++)
//				delete[]p[i];
//			delete[]p;
//		}
//		
//	}
//	return 0;
//}